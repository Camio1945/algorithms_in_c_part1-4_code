/** 程序5.3：欧几里得算法 */
#include <stdio.h>

/**
 * 求取最大公约数
 * “gcd”分别代表：greatest common divisor
 *
 * @param m
 * @param n
 * @return
 */
int gcd(int m, int n) {
  if (n == 0) {
    return m;
  }
  return gcd(n, m % n);
}

main() {
  setbuf(stdout, NULL);
  printf("%d和%d的最大公约数为：%d\n", 10, 5, gcd(10, 5));
  printf("%d和%d的最大公约数为：%d\n", 5, 10, gcd(5, 10));
  printf("%d和%d的最大公约数为：%d\n", 314159, 271828, gcd(314159, 271828));
}
