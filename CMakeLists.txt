cmake_minimum_required(VERSION 3.27)
project(raytracer)

set(CMAKE_CXX_STANDARD 17)

# Fetch GLM library
include(FetchContent)

FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG 1.0.1
)

FetchContent_MakeAvailable(glm)

add_executable(raytracer main.cpp
        utils.h
        color.h
        ray.h
        hittable.h
        sphere.h
        hittable_list.h
        interval.h
        camera.h
        material.h
)

target_link_libraries(raytracer glm::glm)
