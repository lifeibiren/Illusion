#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

#include <iostream>

class CharBitmap;

class freetype2
{
public:
    freetype2();
    void set_fontsize(int width, int height);
    CharBitmap render(char ch);

private:
    FT_Library  library;   /* handle to library     */
    FT_Face     face;      /* handle to face object */
    FT_GlyphSlot  slot;
    int width_, height_;
};

