#pragma once

#include <GL/gl.h>
#include <GL/glu.h>

#include "char_bitmap.h"

class frame_buffer
{
public:
    frame_buffer(int width, int height) : width_(width), height_(height)
    {
        buf_ = new unsigned char[width * height * 3];
        buf_[0] = 255;
    }
    void set_pixel(int x, int y, int r, int g, int b)
    {
        y = height_ - y - 1;
        buf_[3 * (width_ * y + x)] = r;
        buf_[3 * (width_ * y + x) + 1] = g;
        buf_[3 * (width_ * y + x) + 2] = b;
    }
    const unsigned char *buf() const
    {
        return buf_;
    }

    void place(const CharBitmap& cb, int x, int y)
    {
        for (std::size_t y0 = 0; y0 < cb.height(); y0++) {
            for (std::size_t x0 = 0; x0 < cb.width(); x0++) {
                std::uint8_t r, g, b;
                r = g = b = cb.at(x0, y0);
                set_pixel(x + x0, y + y0 - cb.height(), r, g, b);
            }
        }
    }

    void place(const std::vector<CharBitmap>& vcb, int x, int y)
    {
        for (const auto& cb : vcb) {
            place(cb, x, y);
            x += cb.width();
        }
    }

    int width_, height_;
    unsigned char *buf_;
};
