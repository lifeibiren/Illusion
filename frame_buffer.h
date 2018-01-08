#ifndef FRAME_BUFFER_H
#define FRAME_BUFFER_H

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
    void place(const char_bitmap &cb, int x, int y)
    {
        FT_Int  i, j, p, q;
        FT_Int  x_max = x + cb.width();
        FT_Int  y_max = y + cb.height();
        for ( i = x, p = 0; i < x_max; i++, p++ )
        {
          for ( j = y, q = 0; j < y_max; j++, q++ )
          {
            if ( i < 0      || j < 0       ||
                 i >= height_ || j >= width_)
              continue;

            set_pixel(i, j, cb.buffer()[q * cb.width() + p],
                    cb.buffer()[q * cb.width() + p],
                    cb.buffer()[q * cb.width() + p]);
          }
        }
    }
    int width_, height_;
    unsigned char *buf_;
};

#endif // FRAME_BUFFER_H
