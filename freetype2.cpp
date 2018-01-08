#include "freetype2.h"

void
draw_bitmap( frame_buffer *fb,
             FT_Bitmap*  bitmap,
             FT_Int      x,
             FT_Int      y)
{
  FT_Int  i, j, p, q;
  FT_Int  x_max = x + bitmap->width;
  FT_Int  y_max = y + bitmap->rows;


  for ( i = x, p = 0; i < x_max; i++, p++ )
  {
    for ( j = y, q = 0; j < y_max; j++, q++ )
    {
      if ( i < 0      || j < 0       ||
           i >= fb->height_ || j >= fb-> width_)
        continue;

      fb->set_pixel(i, j, bitmap->buffer[q * bitmap->width + p], bitmap->buffer[q * bitmap->width + p], bitmap->buffer[q * bitmap->width + p]);
    }
  }
}

freetype2::freetype2()
{
    int error = FT_Init_FreeType(&library);
    if (error)
    {
        std::cerr<<"ft init error "<<error<<std::endl;
    }
    error = FT_New_Face( library,
                         "/usr/share/fonts/TTF/Hack-Regular.ttf",
                         0,
                         &face );
    if ( error == FT_Err_Unknown_File_Format )
    {
        std::cerr<<"unknown file format "<<error<<std::endl;
    }
    else if ( error )
    {
        std::cerr<<"unable to read font "<<error<<std::endl;
    }
    slot = face->glyph;  /* a small shortcut */

}
void freetype2::set_fontsize(int width, int height)
{
    width_ = width;
    height_ = height;
//    int error = FT_Set_Pixel_Sizes(face, width_, height_);
    int error = FT_Set_Char_Size(
                face,    /* handle to face object           */
                width_ * 64,       /* char_width in 1/64th of points  */
                height_ * 64,   /* char_height in 1/64th of points */
                96,     /* horizontal device resolution    */
                96 );   /* vertical device resolution      */
    if (error) {
        std::cerr<<"error setting font size "<<error<<std::endl;
    }
}
char_bitmap freetype2::render(char ch)
{
    int error = FT_Load_Char(face, ch, FT_LOAD_RENDER );
    char_bitmap bitmap(slot->bitmap.width, slot->bitmap.rows);
    if (error) {
        std::cerr<<"freetype2 unable to render "<<error<<std::endl;
    } else {
        bitmap.fill(slot->bitmap);
    }
    return bitmap;
}
