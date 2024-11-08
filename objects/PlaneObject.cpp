#include "PlaneObject.h"

[[maybe_unused]] PlaneObject::PlaneObject(float a, float b, float c, float d, std::shared_ptr<IMaterial> material)
        : Object(std::move(material)), Plane(a, b, c, d) {}

[[maybe_unused]] PlaneObject::PlaneObject(Vector3 point, Vector3 normal, std::shared_ptr<IMaterial> material) : Object(
        std::move(material)), Plane(point, normal) {
}

float PlaneObject::getObjectRayCastHit(Vector3 point, Vector3 direction) {
    return GetRayCastHit(point, direction);
}

Vector3 PlaneObject::getNormal(Vector3 point) {
    return Plane::getNormal();
}
