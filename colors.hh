#pragma once

#include <iostream>

#define MAX_COLOR 255

class Color {
public:
    Color() : _r(0), _g(0), _b(0) {}

    Color(float r, float g, float b);

    Color operator*(float f) const;

    Color operator+(const Color &color) const;

    Color operator/(float f) const;

    Color operator+=(const Color &color);

    friend std::ostream &operator<<(std::ostream &os, const Color &color);

    float _r, _g, _b;
};

float min(float a, float b);