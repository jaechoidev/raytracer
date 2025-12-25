#include <iostream>
#include "utils.h"

int main() {

  int image_width = 256;
  int image_height = 256;

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
    std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
    for (int i = 0; i < image_width; i++) {
      auto r = remap(i, 0, image_width-1, 0, 255.999);
      auto g = remap(j, 0, image_height-1, 0, 255.999);
      auto b = 0.0;

      int ir = int(r);
      int ig = int(g);
      int ib = int(b);

      std::cout << ir << ' ' << ig << ' ' << ib << '\n';
    }
  }
  std::clog << "\rDone.                                 \n";
}
