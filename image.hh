#pragma once

#include <iostream>
#include <vector>
#include "colors.hh"

class Image {
public:
    Image(int width, int heigth);

    void to_ppm(const std::string &path) const;

    void set_pixel(unsigned int x, unsigned int y, const Color &color);

    void add_color(unsigned int x, unsigned int y, const Color &color);

    [[maybe_unused]] void avegrage_color(unsigned int x, unsigned int y, const Color &color, int n);

protected:
    int height, width;
    std::vector<Color> map;
};
