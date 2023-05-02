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

    Vector3 normalize() const;

    float norm() const;

    friend std::ostream &operator<<(std::ostream &os, const Vector3 &vector3);

    Vector3 get_reflection(const Vector3 &normal) const;

    float _x, _y, _z;
};
