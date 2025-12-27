//
// Created by Jae Choi on 2025-12-25.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include <glm/vec3.hpp> // using glm instead of vec3
#include "interval.h"
#include "utils.h"

using color = glm::vec3;
inline double linear_to_gamma(double linear_component)
{
  if (linear_component > 0)
    return std::sqrt(linear_component);

  return 0;
}

void write_color(std::ostream& out, const color& pixel_color) {
  auto r = pixel_color.x;
  auto g = pixel_color.y;
  auto b = pixel_color.z;

  // Apply a linear to gamma transform for gamma 2
  r = linear_to_gamma(r);
  g = linear_to_gamma(g);
  b = linear_to_gamma(b);

  // Translate the [0,1] component values to the byte range [0,255].
  static const interval intensity(0.000, 0.999);
  int rbyte = int(256 * intensity.clamp(r));
  int gbyte = int(256 * intensity.clamp(g));
  int bbyte = int(256 * intensity.clamp(b));

  out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
#endif //RAYTRACER_COLOR_H
