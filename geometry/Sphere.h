#pragma once

#include <iostream>
#include "../objects/Object.h"

class Sphere {
public:
    float getRayCastHit(Vector3 point, Vector3 direction);
    Vector3 getNormal(Vector3 point);

protected:
    Sphere(const Vector3 &center, float radius);
    Vector3 center;
    float radius;
};
