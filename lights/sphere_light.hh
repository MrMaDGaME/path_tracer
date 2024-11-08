#pragma once

#include <iostream>
#include "../Vector3.h"
#include "../image/Color.h"
#include "light.hh"
#include "../objects/sphere.hh"

class SphereLight : public Light {
public:
    float raycast_hit(Vector3 point, Vector3 direction) override;

    SphereLight(const Vector3 &position, const Color &color, float radius);

protected:
    Vector3 position;
    float radius;
};
