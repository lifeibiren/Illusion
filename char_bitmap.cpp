#include "char_bitmap.h"

char_bitmap::char_bitmap(int width, int height) :
    width_(width), height_(height), buf_(new char[width * height])
{
}
void char_bitmap::fill(const FT_Bitmap &bitmap)
{
    assert(height_ == bitmap.rows && width_ == bitmap.width);
    memcpy(buf_, bitmap.buffer, height_ * width_);
}
