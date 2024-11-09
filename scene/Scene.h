#pragma once

#pragma once

#include "ObjectManager.h"
#include "LightManager.h"
#include "RayTracer.h"
#include "Camera.h"
#include "../image/Color.h"
#include "RayTracer.h"

class Scene {
public:
    Scene();

    void addObject(std::shared_ptr<Object> object);

    void addLight(std::shared_ptr<Light> light);

    Color renderPixel(const Vector3 &pixel, const Vector3 &direction, float maxColor);

private:
    ObjectManager objectManager;
    LightManager lightManager;
    RayTracer rayTracer;
};
