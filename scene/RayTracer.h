#pragma once

#include <random>
#include "ObjectManager.h"
#include "LightManager.h"
#include "Camera.h"
#include "../image/Color.h"

class RayTracer {
public:
    RayTracer(ObjectManager &objectManager, LightManager &lightManager);

    Color getPixelColor(const Vector3 &pixel, const Vector3 &direction, const Color &totalFilter,
                        float currentRefractiveIndex);

private:
    ObjectManager &objectManager;
    LightManager &lightManager;

    Vector3 getDirectHit(const Vector3 &point, const Vector3 &direction, Object *&currentObj, Light *&currentLight);

    static Vector3
    getLightDirection(const Vector3 &previousDirection, const Vector3 &normal, TextureMaterial::Texture *texture);
};
