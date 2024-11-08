cmake_minimum_required(VERSION 3.25)
project(path_tracer)

set(CMAKE_CXX_STANDARD 23)

add_compile_definitions(_USE_MATH_DEFINES)

add_executable(path_tracer main.cpp scene/Camera.cpp image/Color.cpp image/Image.cpp lights/SphereLight.cpp scene/Scene.cpp textures/UniformTexture.cpp Vector3.cpp geometry/Plane.cpp geometry/Sphere.cpp lights/Light.h lights/PlaneLight.cpp lights/PlaneLight.h textures/Mirror.cpp textures/Mirror.h
        image/ImageExporter.cpp
        image/ImageExporter.h
        scene/ObjectManager.cpp
        scene/ObjectManager.h
        scene/LightManager.cpp
        scene/LightManager.h
        scene/RayTracer.cpp
        scene/RayTracer.h
        textures/Texture.h
        objects/Object.cpp
        lights/Light.cpp
        objects/PlaneObject.cpp
        objects/PlaneObject.h
        objects/SphereObject.cpp
        objects/SphereObject.h
)
