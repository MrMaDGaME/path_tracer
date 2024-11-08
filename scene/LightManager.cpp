#include "LightManager.h"

void LightManager::addLight(Light *light) {
    lights.push_back(light);
}

const std::vector<Light *> &LightManager::getLights() const {
    return lights;
}
