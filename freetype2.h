#ifndef FREETYPE2_H
#define FREETYPE2_H

#include <ft2build.h>
#include FT_FREETYPE_H

#include <iostream>

#include "frame_buffer.h"
#include "char_bitmap.h"

class freetype2
{
public:
    freetype2();
    void set_fontsize(int width, int height);
    char_bitmap render(char ch);
private:
    FT_Library  library;   /* handle to library     */
    FT_Face     face;      /* handle to face object */
    FT_GlyphSlot  slot;
    int width_, height_;
};

#endif // FREETYPE2_H
