#include <math.h>
#include <stdio.h>
#include "Point.h"

float distance(point a, point b) {
  float dx = a.x - b.x, dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

main() {
  // a点的坐标是原点，b点的坐标是 3,4 ，根据勾股定理，两点的距离是5
  point a = {0, 0}, b = {3, 4};
  float d = distance(a, b);
  printf("%f", d);
}
