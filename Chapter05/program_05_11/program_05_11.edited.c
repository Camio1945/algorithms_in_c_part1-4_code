/** 程序5.11：斐波纳契数（动态规划） */
#include <stdio.h>
#include <stdlib.h>

/** 已知的数组 */
int *knownF;

/** 未知值。当数组中的某项的值为 unknown 时，代表这一项还没有赋值。 */
int unknown = -1;

/**
 * 动态规划计算斐波纳契数
 * @param i 计算该数的斐波纳契数
 * @return
 */
int F(int i) {
  int t;
  if (knownF[i] != unknown) {
    return knownF[i];
  }
  if (i == 0) {
    t = 0;
  }
  if (i == 1) {
    t = 1;
  }
  if (i > 1) {
    t = F(i - 1) + F(i - 2);
  }
  return knownF[i] = t;
}

main() {
  setbuf(stdout, NULL);
  knownF = malloc(sizeof(int) * 10);
  printf("斐波纳契数列为：\n");
  for (int i = 0; i < 10; ++i) {
    knownF[i] = unknown;
    printf("%d ", F(i));
  }
}
