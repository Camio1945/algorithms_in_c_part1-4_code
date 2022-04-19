#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef int Number;

Number randNum() { return rand(); }

main(int argc, char *argv[]) {
  int i, N = atoi(argv[1]);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  printf("N : %d\n", N);
  float M = 0.0, m2 = 0.0;
  Number x;
  for (i = 0; i < N; i++) {
    x = randNum();
    M += ((float) x) / N;
    m2 += ((float) x * x) / N;
    printf("x%d : %10d \t m1 : %10.2f \t m2 : %15.2f\n", i, x, M, m2);
  }
  printf("Average: %f\n", M);
  printf("Std. deviation: %f\n", sqrt(m2 - M * M));
}

