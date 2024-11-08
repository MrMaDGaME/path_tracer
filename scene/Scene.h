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

    void addObject(Object *object);

    void addLight(Light *light);

    Color renderPixel(const Vector3 &pixel, const Vector3 &direction);

private:
    ObjectManager objectManager;
    LightManager lightManager;
    RayTracer rayTracer;
};
