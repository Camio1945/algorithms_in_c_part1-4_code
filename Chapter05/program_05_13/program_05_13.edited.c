/** 程序5.13：背包问题（动态规划） */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size; // 大小
  int val; // 价值
} Item;

int N = 5;
Item *items;
int count = 0;

/** 已知的数组。 */
int *maxKnown;

/** 未知值。当数组中的某项的值为 unknown 时，代表这一项还没有赋值。 */
int unknown = -1;

/**
 * 计算背包能装下的最大价值
 * @param cap 背包的容量
 * @return 装下的最大价值
 */
int knap(int cap) {
  if (maxKnown[cap] != unknown) {
    return maxKnown[cap];
  }
  int i, space, max = 0, t;
  for (i = 0; i < N; ++i) {
    count++;
    space = cap - items[i].size; // space代表背包装下items[i]之后的剩余空间
    if (space >= 0) { // 如果装得下
      t = items[i].val;
      if (space > 0) {
        int maxForSpace = knap(space);
        t += maxForSpace;
      }
      if (t > max) {
        max = t;
      }
    }
  }
  maxKnown[cap] = max;
  return max;
}

/** 初始化items */
void initItems() {
  items = malloc(N * sizeof(Item));
  items[0].size = 3;
  items[0].val = 4;

  items[1].size = 4;
  items[1].val = 5;

  items[2].size = 7;
  items[2].val = 10;

  items[3].size = 8;
  items[3].val = 11;

  items[4].size = 9;
  items[4].val = 13;
}

main() {
  setbuf(stdout, NULL);
  initItems();
  int knapSize = 17;
  maxKnown = malloc(sizeof(int) * knapSize);
  for (int i = 0; i <= knapSize; ++i) {
    maxKnown[i] = unknown;
  }
  int maxVal = knap(knapSize);
  printf("注：在本例中，各物品的数量都是无限的\n");
  printf("背包的大小为：%d，能装下的最大价值为：%d\n", knapSize, maxVal);
  printf("总循环的次数：%d\n", count);
}
