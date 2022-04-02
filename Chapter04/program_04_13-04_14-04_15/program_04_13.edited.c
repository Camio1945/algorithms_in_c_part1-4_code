#include <stdio.h>
#include <math.h>
#include "program_04_15.original.c"

#define PI 3.141592625

main() {
  int i, j, N = 50;
  Complex t, x;
  printf("%dth complex roots of unity\n", N);
  for (i = 0; i < N; i++) {
    float r = 2.0 * PI * i / N;
    t = COMPLEXinit(cos(r), sin(r));
    printf("i：%2d ， 实部：%6.3f ，虚部：%6.3f ", i, Re(t), Im(t));
    for (x = t, j = 0; j < N - 1; j++) {
      x = COMPLEXmult(t, x);
    }
    printf("，进行%2d次自乘之后，实部：%6.3f 虚部：%6.3f\n", i, Re(x), Im(x));
  }
}
