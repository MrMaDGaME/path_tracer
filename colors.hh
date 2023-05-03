#pragma once

#include <iostream>

#define MAX_COLOR 255.0f

class Color {
public:
    Color() : _r(0), _g(0), _b(0) {}

    Color(float r, float g, float b);

    Color operator*(float f) const;

    Color operator+(const Color &color) const;

    Color operator/(float f) const;

    Color operator+=(const Color &color);

    bool operator==(const Color &color) const;

    bool operator<(const Color &color) const;

    Color operator*(const Color &color) const;

    Color proportionnal_product(float f) const;

    friend std::ostream &operator<<(std::ostream &os, const Color &color);

    float _r, _g, _b;
};
