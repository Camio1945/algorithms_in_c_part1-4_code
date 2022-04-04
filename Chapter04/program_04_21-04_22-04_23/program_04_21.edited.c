#include <stdio.h>
#include "program_04_23.edited.c"

main() {
  int N = 3;
  float p = 4;
  Poly t, x;
  int i;
  printf("二项式系数，本程序计算的是 (p+1) 的 (N+1) 次方的值\n");
  Poly p1 = POLYterm(1, 1);
  Poly p2 = POLYterm(1, 0);
  t = POLYadd(p1, p2);
  showPOLY(t);
  for (i = 0, x = t; i < N; i++) {
    x = POLYmult(t, x);
    showPOLY(x);
  }
  printf("(%.2f+1) 的 (%d+1) 次方的值为：%f\n", p, N, POLYeval(x, p));
}
