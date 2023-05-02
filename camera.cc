#include "camera.hh"

Camera::Camera(const Vector3 &center, const Vector3 &direction, const Vector3 &up, float alpha,
               float beta, float z) : center(center), direction(direction), up(up), alpha(alpha),
                                      beta(beta), z(z) {}

[[maybe_unused]] Camera::Camera(const Vector3 &center, const Vector3 &direction, float alpha, float beta, float z)
        : center(center), direction(direction), alpha(alpha), beta(beta), z(z), up(Vector3(0, 1, 0)
) {}
