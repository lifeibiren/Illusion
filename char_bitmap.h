#pragma once

#include "freetype2.h"

#include <cassert>
#include <string>
#include <vector>

class CharBitmap {
public:
    CharBitmap(int width, int heights);
    void fill(const FT_Bitmap& bitmap);
    int height() const { return height_; }
    int width() const { return width_; }
    const char* buffer() const { return buf_.data(); }

    char at(std::size_t x, std::size_t y) const;

private:
    int height_;
    int width_;
    std::vector<char> buf_;
};

class StringLine {
public:
    StringLine(const std::string& str)
        : str_(str)
    {
    }

    std::vector<CharBitmap> render(freetype2& ft) const
    {
        std::vector<CharBitmap> bitmaps;
        for (auto c : str_) {
            bitmaps.push_back(ft.render(c));
        }
        return bitmaps;
    }

protected:
    std::string str_;
};
