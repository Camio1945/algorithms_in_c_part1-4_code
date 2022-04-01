#include <stdlib.h>
#include <stdio.h>

static int *s, *t, N; // s中存的是实际的元素值，t中保存的是该元素在栈中是否已经存在

/**
 * 初始化栈
 * @param maxN 栈大小
 */
void STACKinit(int maxN) {
  s = malloc(sizeof(int) * maxN);
  t = malloc(sizeof(int) * maxN);
  N = 0;
  // for循环作用：表示每个元素在数组中都不存在
  for (int i = 0; i < N; ++i) {
    t[i] = 0;
  }
}

/** 判断栈是否为空 */
int STACKempty() {
  return N == 0;
}

/**
 * 入栈
 * @param item
 */
void STACKpush(int item) {
  // 如果已经存在，则返回
  if (t[item] == 1) {
    return;
  }
  s[N] = item;
  N++;
  t[item] = 1;
}

/** 出栈 */
int STACKpop() {
  N--;
  int item = s[N];
  t[item] = 0;
  return item;
}

main() {
  STACKinit(10);
  STACKpush(1);
  STACKpush(2);
  STACKpush(3);
  STACKpush(2);
  STACKpush(1);
  while (!STACKempty()) {
    printf("%d\n", STACKpop());
  }
}
