//
// Created by Jae Choi on 2025-12-25.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "hittable.h"

class sphere : public hittable {
  public:
    sphere(const glm::vec3& center, double radius, shared_ptr<material> mat)
            : center(center), radius(std::fmax(0,radius)), mat(mat) {}

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
      glm::vec3 oc = center - r.origin();
      auto a = glm::dot(r.direction(),r.direction());
      auto h = glm::dot(r.direction(), oc);
      auto c = glm::dot(oc, oc) - radius*radius;

      auto discriminant = h*h - a*c;
      if (discriminant < 0) return false;

      auto sqrtd = std::sqrt(discriminant);

      // Find the nearest root that lies in the acceptable range
      auto root = (h - sqrtd) / a;
      if (!ray_t.surrounds(root)) {
        root = (h+sqrtd) / a;
        if (!ray_t.surrounds(root))
          return false;
      }

      rec.t = root;
      rec.p = r.at(rec.t);
      glm::vec3 outward_normal = (rec.p - center) / float(radius);
      rec.set_face_normal(r, outward_normal);
      rec.mat = mat;
      return true;
    }
  private:
    glm::vec3 center;
    double radius;
    shared_ptr<material> mat;
};

#endif //RAYTRACER_SPHERE_H
