#pragma once

#include <random>
#include "ObjectManager.h"
#include "LightManager.h"
#include "Camera.h"
#include "../image/Color.h"

class RayTracer {
public:
    RayTracer(ObjectManager &objectManager, LightManager &lightManager);

    Color getPixelColor(const Vector3 &pixel, const Vector3 &direction, const Color &totalFilter);

private:
    ObjectManager &objectManager;
    LightManager &lightManager;

    Vector3 getDirectHit(const Vector3 &point,
                         const Vector3 &direction,
                         std::shared_ptr<Object> &currentObj,
                         std::shared_ptr<Light> &currentLight);
};
