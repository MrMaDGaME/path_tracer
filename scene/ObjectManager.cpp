#include "ObjectManager.h"

void ObjectManager::addObject(std::shared_ptr<Object> object) {
    objects.push_back(object);
}

const std::vector<std::shared_ptr<Object> > &ObjectManager::getObjects() const {
    return objects;
}
