#pragma once

#include <vector>
#include "../objects/object.hh"

class ObjectManager {
public:
    void addObject(Object *object);

    [[nodiscard]] const std::vector<Object *> &getObjects() const;

private:
    std::vector<Object *> objects;
};
