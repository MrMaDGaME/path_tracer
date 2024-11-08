#pragma once

#include <vector>
#include "Color.h"

class Image {
public:
    Image(int width, int height);

    [[maybe_unused]] void setPixel(unsigned int x, unsigned int y, const Color &color);

    [[maybe_unused]] void addColor(unsigned int x, unsigned int y, const Color &color);

    void averageColor(unsigned int x, unsigned int y, const Color &color, int n);

    [[nodiscard]] const std::vector<Color> &getMap() const;

    [[nodiscard]] int getWidth() const;

    [[nodiscard]] int getHeight() const;

private:
    int height_, width_;
    std::vector<Color> map_;
};
