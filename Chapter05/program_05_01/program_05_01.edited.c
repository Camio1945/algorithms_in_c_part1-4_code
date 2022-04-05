/** 程序5.1：阶乘函数（递归实现） */
#include <stdio.h>

/**
 * 求阶乘
 * @param N 需要大于等于1
 * @return
 */
int factorial(int N) {
  if (N == 0) {
    return 1;
  }
  return N * factorial(N - 1);
}

main() {
  int N = 5;
  for (int i = 1; i <= N; ++i) {
    printf("%d的阶乘是：%d\n", i, factorial(i));
  }
}
