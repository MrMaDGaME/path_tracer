#pragma once

#include <iostream>
#include "vector_3.hh"

class Camera {
public:
    Camera(const Vector3 &center, const Vector3 &direction, const Vector3 &up,
           float beta, float z, int width, int height);

    [[maybe_unused]] Camera(const Vector3 &center, const Vector3 &direction, float beta, float z, int width,
                            int height);

    Vector3 center;
    Vector3 direction;
    Vector3 up;
    float beta;
    float z;
    int width;
    int height;
};
