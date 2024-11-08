#include "LightManager.h"

void LightManager::addLight(std::shared_ptr<Light> light) {
    lights.push_back(light);
}

const std::vector<std::shared_ptr<Light>> &LightManager::getLights() const {
    return lights;
}
