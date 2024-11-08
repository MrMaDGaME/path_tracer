#pragma once

#include <vector>
#include "../objects/Object.h"

class ObjectManager {
public:
    void addObject(std::shared_ptr<Object> object);

    [[nodiscard]] const std::vector<std::shared_ptr<Object> > &getObjects() const;

private:
    std::vector<std::shared_ptr<Object> > objects;
};
