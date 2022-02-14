#include <stdio.h>

int lg(int);

int lgDouble(double);

main() {
  int i, N;
  printf("%7s %7s %12s\n", "N", "lg(N)", "N * lg(N)");
  printf("-------------------------------\n");
  for (i = 1, N = 10; i <= 6; i++, N *= 10) {
    printf("%7d %7d %12d\n", N, lg(N), N * lg(N));
//    printf("%7d %7d %12d\n", N, lgDouble(N), N * lgDouble(N));
  }
}

int lgDouble(double N) {
  int i = 0;
  while (N >= 1) {
    i++;
    N = N / 2;
  }
  return i;
}

int lg(int N) {
  int i = 0;
//  while (N > 0) {
//    i++;
//    N = N / 2;
//  }
  for (; N > 0; i++, N = N / 2);
  return i;
}

