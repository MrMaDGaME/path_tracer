#pragma once

#include <iostream>
#include "../Vector3.h"
#include "../image/Color.h"
#include "Light.h"
#include "../geometry/Sphere.h"

class SphereLight : public Light, Sphere {
public:
    [[maybe_unused]] SphereLight(const Vector3 &position, float radius, const Color &color);

    float getLightRayCastHit(Vector3 point, Vector3 direction) override;
};
