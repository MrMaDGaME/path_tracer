#include "SphereObject.h"

SphereObject::SphereObject(const Vector3 &center, float radius, std::shared_ptr<IMaterial> material) : Object(std::move(
        material)), Sphere(center, radius) {}

float SphereObject::getObjectRayCastHit(Vector3 point, Vector3 direction) {
    return getRayCastHit(point, direction);
}

Vector3 SphereObject::getNormal(Vector3 point) {
    return Sphere::getNormal(point);
}
