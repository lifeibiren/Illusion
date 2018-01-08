#ifndef CHAR_BITMAP_H
#define CHAR_BITMAP_H

#include <ft2build.h>
#include FT_FREETYPE_H
#include <assert.h>
class char_bitmap
{
public:
    char_bitmap(int width, int heights);
    void fill(const FT_Bitmap &bitmap);
    int height() const
    {
        return height_;
    }
    int width() const
    {
        return width_;
    }
    char* buffer() const
    {
        return buf_;
    }
private:
    int height_;
    int width_;
    char *buf_;
};

#endif // CHAR_BITMAP_H
