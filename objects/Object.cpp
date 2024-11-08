#include "Object.h"

#include <utility>

Object::Object(std::shared_ptr<IMaterial> material) : material_(std::move(material)) {}

std::shared_ptr<IMaterial> Object::getMaterial() const {
    return material_;
}
