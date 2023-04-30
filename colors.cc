#include "colors.hh"

float min(float a, float b) {
    return a < b ? a : b;
}

Color::Color(float r, float g, float b) {
    _r = min(r, MAX_COLOR);
    _g = min(g, MAX_COLOR);
    _b = min(b, MAX_COLOR);
}

std::ostream &operator<<(std::ostream &os, const Color &color) {
    os << "r: " << color._r << " g: " << color._g << " b: " << color._b;
    return os;
}

Color Color::operator*(const float f) const {
    return {_r * f, _g * f, _b * f};
}

Color Color::operator+(const Color &color) const {
    return {_r + color._r, _g + color._g, _b + color._b};
}

Color Color::operator/(float f) const {
    return {_r / f, _g / f, _b / f};
}

Color Color::operator+=(const Color &color) {
    _r += color._r;
    _g += color._g;
    _b += color._b;
    _r = min(_r, MAX_COLOR);
    _g = min(_g, MAX_COLOR);
    _b = min(_b, MAX_COLOR);
    return *this;
}
