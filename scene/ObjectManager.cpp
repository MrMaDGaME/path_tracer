#include "ObjectManager.h"

void ObjectManager::addObject(Object *object) {
    objects.push_back(object);
}

const std::vector<Object *> &ObjectManager::getObjects() const {
    return objects;
}
