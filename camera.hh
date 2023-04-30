#pragma once

#include <iostream>
#include "vector_3.hh"

class Camera {
public:
    Camera(const Vector3 &center, const Vector3 &direction, const Vector3 &up, float alpha,
           float beta, float z);

    Camera(const Vector3 &center, const Vector3 &direction, float alpha, float beta, float z);

    float getAlpha() const;

    float getBeta() const;

    float getZ() const;

    Vector3 center;
    Vector3 direction;
    Vector3 up;
    float alpha;
    float beta;
    float z;
};
