#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include "colors.hh"

class Image {
public:
    Image(int width, int height);

    void to_ppm(const std::string &path) const;

    [[maybe_unused]] void set_pixel(unsigned int x, unsigned int y, const Color &color);

    [[maybe_unused]] void add_color(unsigned int x, unsigned int y, const Color &color);

    [[maybe_unused]] void average_color(unsigned int x, unsigned int y, const Color &color, int n);

    [[maybe_unused]] void get_max(unsigned int x, unsigned int y, const Color &color);

protected:
    int height, width;
    std::vector<Color> map;
};
