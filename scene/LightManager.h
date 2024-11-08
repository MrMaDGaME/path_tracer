#pragma once

#include <vector>
#include "../lights/light.hh"

class LightManager {
public:
    void addLight(Light *light);

    [[nodiscard]] const std::vector<Light *> &getLights() const;

private:
    std::vector<Light *> lights;
};
