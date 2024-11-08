#pragma once

#include "Object.h"
#include "../geometry/Plane.h"

class PlaneObject : public Object, Plane {
public:
    [[maybe_unused]] PlaneObject(float a, float b, float c, float d, std::shared_ptr<IMaterial> material);

    [[maybe_unused]] PlaneObject(Vector3 point, Vector3 normal, std::shared_ptr<IMaterial> material);

    float getObjectRayCastHit(Vector3 point, Vector3 direction) override;

    Vector3 getNormal(Vector3 point) override;
};
