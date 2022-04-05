/** 程序5.2：有问题的递归函数 */
#include <stdio.h>

/**
 * 谜之函数
 * @param N
 * @return
 */
int puzzle(int N) {
  if (N == 1) {
    return 1;
  }
  if (N % 2 == 0) {
    printf("偶数：%d\n", N);
    return puzzle(N / 2);
  } else {
    printf("奇数：%d\n", N);
    return puzzle(3 * N + 1);
  }
}

main() {
  setbuf(stdout, NULL);
  puzzle(113383);
}
