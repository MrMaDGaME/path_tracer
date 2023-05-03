#include "colors.hh"

Color::Color(float r, float g, float b) {
    _r = std::min(r, MAX_COLOR);
    _g = std::min(g, MAX_COLOR);
    _b = std::min(b, MAX_COLOR);
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
    _r = std::min(_r, MAX_COLOR);
    _g = std::min(_g, MAX_COLOR);
    _b = std::min(_b, MAX_COLOR);
    return *this;
}

bool Color::operator==(const Color &color) const {
    return color._r == _r && color._g == _g && color._b == _b;
}

Color Color::operator*(const Color &color) const {
    return {_r * color._r, _g * color._g, _b * color._b};
}

bool Color::operator<(const Color &color) const {
    return _r < color._r && _g < color._g && _b < color._b;
}

Color Color::proportionnal_product(const float f) const {
    float max = std::max(_r, std::max(_g, _b));
    if (max * f > MAX_COLOR) {
        return {MAX_COLOR * _r / max, MAX_COLOR * _g / max, MAX_COLOR * _b / max};
    }
    return {_r * f, _g * f, _b * f};
}
