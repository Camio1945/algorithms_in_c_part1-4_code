#include <stdio.h>

int lg(int);

main() {
  int i, N;
  printf("%7s %7s %12s\n", "N", "lg(N)", "N * lg(N)");
  printf("-------------------------------\n");
  for (i = 1, N = 10; i <= 6; i++, N *= 10) {
    printf("%7d %7d %12d\n", N, lg(N), N * lg(N));
//    printf("%7d %7d %12d\n", N, lgDouble(N), N * lgDouble(N));
  }
}

