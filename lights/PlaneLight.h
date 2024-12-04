#pragma once

#include <iostream>
#include "Light.h"
#include "../geometry/Plane.h"

class PlaneLight : public Light, Plane {
public:
    [[maybe_unused]] PlaneLight(const Vector3 &position, const Vector3 &normal, const Color &color);

    [[maybe_unused]] PlaneLight(float a, float b, float c, float d, const Color &color);

    float getLightRayCastHit(Vector3 point, Vector3 direction) override;
};
