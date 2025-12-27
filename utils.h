//
// Created by Jae Choi on 2025-12-25.
//

#ifndef RAYTRACER_UTILS_H
#define RAYTRACER_UTILS_H

#include <cmath>
#include <random>
#include <iostream>
#include <limits>
#include <memory>


using std::make_shared;
using std::shared_ptr;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees){
  return degrees * pi / 180.0;
}

inline double random_double() {
  static std::uniform_real_distribution<double> distribution(0.0, 1.0);
  static std::mt19937 generator(42); // reproducible to compare changes
  //  static std::mt19937 generator(std::random_device{}());
  return distribution(generator);
}


inline double random_double(double min, double max) {
  // Returns a random real in [min,max).
  return min + (max-min)*random_double();
}

inline double remap(double value, double in_min, double in_max, double out_min, double out_max){
  return out_min + (value - in_min) * (out_max- out_min) / (in_max - in_min);
}



#include "color.h"
#include "interval.h"
#include "ray.h"
#include <glm/vec3.hpp> // using glm instead of vec3
#include <glm/geometric.hpp> // dot, cross, .. etc
#include <glm/gtc/random.hpp>
#include <glm/gtc/epsilon.hpp>

[[nodiscard]] inline bool near_zero(const glm::vec3& v) {
  return glm::all(glm::epsilonEqual(v, glm::vec3(0.0f), 1e-8f));
//  return glm::dot(v, v) < 1e-16f; //slightly better performance?
}

inline glm::vec3 random_vec3() {
  return glm::vec3(random_double(), random_double(), random_double());
}

inline glm::vec3 random_vec3(double min, double max) {
  return glm::vec3(random_double(min, max), random_double(min, max), random_double(min, max));
}

#endif //RAYTRACER_UTILS_H
