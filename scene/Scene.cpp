#include "Scene.h"

Scene::Scene() : rayTracer(objectManager, lightManager) {}

void Scene::addObject(Object *object) {
    objectManager.addObject(object);
}

void Scene::addLight(Light *light) {
    lightManager.addLight(light);
}

Color Scene::renderPixel(const Vector3 &pixel, const Vector3 &direction) {
    return rayTracer.getPixelColor(pixel, direction, Color(255, 255, 255), 1.0f);
}
