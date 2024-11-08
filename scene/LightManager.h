#pragma once

#include <vector>
#include "../lights/Light.h"

class LightManager {
public:
    void addLight(std::shared_ptr<Light> light);

    [[nodiscard]] const std::vector<std::shared_ptr<Light>> &getLights() const;

private:
    std::vector<std::shared_ptr<Light>> lights;
};
