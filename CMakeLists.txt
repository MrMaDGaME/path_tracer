cmake_minimum_required(VERSION 3.25)
project(path_tracer)

set(CMAKE_CXX_STANDARD 23)

add_compile_definitions(_USE_MATH_DEFINES)

add_executable(path_tracer main.cpp scene/Camera.cpp image/Color.cpp image/Image.cpp lights/sphere_light.cc scene/Scene.cpp textures/uniform_texture.cc Vector3.cpp objects/plane.cc objects/sphere.cc lights/light.hh lights/plane_light.cc lights/plane_light.hh textures/mirror_texture.cc textures/mirror_texture.hh textures/material.hh textures/glass_texture.cc textures/glass_texture.hh
        image/ImageExporter.cpp
        image/ImageExporter.h
        scene/ObjectManager.cpp
        scene/ObjectManager.h
        scene/LightManager.cpp
        scene/LightManager.h
        scene/RayTracer.cpp
        scene/RayTracer.h
)
