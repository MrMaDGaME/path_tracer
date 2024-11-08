#include "Image.h"

Image::Image(int width, int height) : height_(height), width_(width) {
    map_.resize(height * width, Color(0, 0, 0));
}

[[maybe_unused]] void Image::setPixel(unsigned int x, unsigned int y, const Color &color) {
    map_[y * width_ + x] = color;
}

[[maybe_unused]] void Image::addColor(unsigned int x, unsigned int y, const Color &color) {
    map_[y * width_ + x] += color;
}

void Image::averageColor(unsigned int x, unsigned int y, const Color &color, int n) {
    auto nf = static_cast<float>(n);
    map_[y * width_ + x] = {(map_[y * width_ + x].getR() * nf + color.getR()) / (nf + 1),
                            (map_[y * width_ + x].getG() * nf + color.getG()) / (nf + 1),
                            (map_[y * width_ + x].getB() * nf + color.getB()) / (nf + 1)};
}

const std::vector<Color> &Image::getMap() const {
    return map_;
}

int Image::getWidth() const {
    return width_;
}

int Image::getHeight() const {
    return height_;
}
