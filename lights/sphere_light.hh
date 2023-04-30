#pragma once

#include <iostream>
#include "../vector_3.hh"
#include "../colors.hh"
#include "light.hh"
#include "../objects/sphere.hh"

class SphereLight : public Light {
public:
    Vector3 getPosition();

    float raycast_hit(Vector3 point, Vector3 direction) override;

    SphereLight(const Vector3 &position, const Color &color, float radius);

protected:
    Vector3 position;
    float radius;
};
