#pragma once

#include <iostream>

#define MAX_COLOR 255.f

class Color {
public:
    Color();

    Color(float r, float g, float b);

    Color operator*(float f) const;

    Color operator+(const Color &color) const;

    Color operator/(float f) const;

    Color operator+=(const Color &color);

    bool operator==(const Color &color) const;

    bool operator<(const Color &color) const;

    Color operator*(const Color &color) const;

    Color operator*=(const Color &color);

    Color operator*=(float f);

    [[maybe_unused]] [[nodiscard]] Color proportionalProduct(float f) const;

    friend std::ostream &operator<<(std::ostream &os, const Color &color);

    [[nodiscard]] float getR() const;

    [[nodiscard]] float getG() const;

    [[nodiscard]] float getB() const;

protected:
    float r_, g_, b_;
};
