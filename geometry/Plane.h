#pragma once

#include <iostream>
#include "../objects/Object.h"

class Plane {
public:
    [[nodiscard]] float GetRayCastHit(Vector3 point, Vector3 direction) const;

    [[nodiscard]] Vector3 getNormal() const;

    virtual ~Plane() = 0;

protected:
    Plane(float a, float b, float c, float d);
    Plane(Vector3 point, Vector3 normal);
    float a_, b_, c_, d_;
};
