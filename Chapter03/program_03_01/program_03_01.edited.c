#include <stdio.h>
//#include <math.h>

int lg(int N) {
  int i;
  for (i = 0; N > 0; i++, N /= 2);
  return i;
}

main() {
  int i, N;
  printf("%7s %7s %12s\n", "N", "lg(N)", "N * lg(N)");
  printf("-------------------------------\n");
  for (i = 1, N = 10; i <= 6; i++, N *= 10) {
    printf("%7d %7d %12d\n", N, lg(N), N * lg(N));
  }
//  printf("log2(10) : %f", log2(10));
}

