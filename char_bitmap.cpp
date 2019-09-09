#include "char_bitmap.h"

CharBitmap::CharBitmap(int width, int height)
    : width_(width)
    , height_(height)
    , buf_(width * height)
{
}
void CharBitmap::fill(const FT_Bitmap& bitmap)
{
    assert(height_ == bitmap.rows && width_ == bitmap.width);
    memcpy(buf_.data(), bitmap.buffer, height_ * width_);
}

char CharBitmap::at(std::size_t x, std::size_t y) const
{
    assert(x < width_ && y < height_);
    return buf_[x + y * width_];
}
