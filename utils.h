//
// Created by Jae Choi on 2025-12-25.
//

#ifndef RAYTRACER_UTILS_H
#define RAYTRACER_UTILS_H

inline double remap(double value, double in_min, double in_max, double out_min, double out_max){
  return out_min + (value - in_min) * (out_max- out_min) / (in_max - in_min);
}

#endif //RAYTRACER_UTILS_H
