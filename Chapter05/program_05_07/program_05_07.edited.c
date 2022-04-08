/** 程序5.7：汉诺塔的解 */
#include <stdio.h>
#include <stdlib.h>

/**
 * 移动盘子
 * @param N 第N个盘子（1代表最短的那个盘子，数字越大盘子越大）
 * @param d 如果为正数，代表往右移动，如果已经是最右边了，就移动到最左边
 *          如果为负数，代表往左移动，如果已经是最左边了，就移动到最右边
 */
void shift(int N, int d) {
  printf("%s%d：把第%d个盘子往%s移\n", d > 0 ? "+" : "-", N, N, d > 0 ? "右" : "左");
}

/**
 * 汉诺塔
 * @param N 层数
 * @param d 如果为正数，代表往右移动，如果已经是最右边了，就移动到最左边
 *          如果为负数，代表往左移动，如果已经是最左边了，就移动到最右边
 */
void hanoi(int N, int d) {
  if (N == 0) {
    return;
  }
  hanoi(N - 1, -d);
  shift(N, d);
  hanoi(N - 1, -d);
}

main() {
  setbuf(stdout, NULL);
  hanoi(3, -1);
}
