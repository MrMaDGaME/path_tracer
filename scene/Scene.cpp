#include "Scene.h"

#include <utility>

Scene::Scene() : rayTracer(objectManager, lightManager) {}

void Scene::addObject(std::shared_ptr<Object> object) {
    objectManager.addObject(std::move(object));
}

void Scene::addLight(std::shared_ptr<Light> light) {
    lightManager.addLight(std::move(light));
}

Color Scene::renderPixel(const Vector3 &pixel, const Vector3 &direction) {
    return rayTracer.getPixelColor(pixel, direction, Color(255, 255, 255));
}
