#pragma once

#include <iostream>
#include "light.hh"
#include "../objects/plane.hh"

class PlaneLight : public Light {
public:
    PlaneLight(const Color &color, const Vector3 &position, const Vector3 &normal);

    const Vector3 &getPosition() const;

    const Vector3 &getNormal() const;

    float raycast_hit(Vector3 point, Vector3 direction) override;

protected:
    Vector3 position;
    Vector3 normal;
};
