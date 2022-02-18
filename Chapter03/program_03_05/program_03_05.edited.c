#include <stdio.h>

#define N 10000

main() {
  int i, j, a[N];
  // for循环作用：把所有的数字都默认标记为1（表明是素数）
  for (i = 2; i < N; i++) {
    a[i] = 1;
  }
  // for循环作用：如果一个值是两个数的乘积，则把这个下标标记为非素数
  for (i = 2; i < N; i++) {
    if (a[i]) {
      for (j = i; i * j < N; j++) {
        a[i * j] = 0;
      }
    }
  }
  // for循环作用：打印出所有的素数
  for (i = 2; i < N; i++) {
    if (a[i]) {
      printf("%4d ", i);
    }
  }

}
