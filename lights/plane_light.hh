#pragma once

#include <iostream>
#include "light.hh"
#include "../objects/plane.hh"

class PlaneLight : public Light {
public:
    PlaneLight(const Vector3 &position, const Vector3 &normal, const Color &color);

    float raycast_hit(Vector3 point, Vector3 direction) override;

protected:
    Vector3 position;
    Vector3 normal;
};
