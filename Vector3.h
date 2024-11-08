#pragma once

#include <iostream>
#include <cmath>

class Vector3 {
public:
    Vector3();

    Vector3(float x, float y, float z);

    Vector3 operator*(const float &l) const;

    Vector3 operator-(const Vector3 &v) const;

    Vector3 operator-() const;

    Vector3 operator+(const Vector3 &v) const;

    float operator*(const Vector3 &v) const;

    [[nodiscard]] Vector3 normalize() const;

    [[nodiscard]] float norm() const;

    friend std::ostream &operator<<(std::ostream &os, const Vector3 &vector3);

    [[nodiscard]] Vector3 get_reflection(const Vector3 &normal) const;

    [[nodiscard]] Vector3 cross(const Vector3 &v) const;

    float x_, y_, z_;
};
