#include "camera.hh"

Camera::Camera(const Vector3 &center, const Vector3 &direction, const Vector3 &up, float beta, float z, int width,
               int height) : center(center), direction(direction), up(up),
                             beta(beta), z(z), width(width), height(height) {}

[[maybe_unused]] Camera::Camera(const Vector3 &center, const Vector3 &direction, float beta, float z, int width,
                                int height)
        : center(center), direction(direction), beta(beta), z(z), up(Vector3(0, 1, 0)), width(width), height(height) {}
