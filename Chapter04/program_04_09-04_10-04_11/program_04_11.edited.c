/** 先进先出队列的数组实现方式 */
#include <stdlib.h>
#include <stdio.h>
#include "QUEUE.h"

static Item *q;
static int N, head, tail;

/**
 * 队列初始化
 * @param maxN 数组的大小
 */
void QUEUEinit(int maxN) {
  q = malloc(sizeof(Item) * (maxN + 1));
  N = maxN + 1;
  head = N;
  tail = 0;
}

/** 判断队列是否为空 */
int QUEUEempty() {
  return head % N == tail;
}

/**
 * 往队尾放入元素
 * @param item 元素
 */
void QUEUEput(Item item) {
  q[tail] = item;
  tail++;
}

/** 从队头获取元素 */
Item QUEUEget() {
  Item item = q[head % N];
  head++;
  return item;
}

main() {
  QUEUEinit(4);
  QUEUEput(1);
  QUEUEput(2);
  QUEUEput(3);
  QUEUEput(4);
  while (!QUEUEempty()) {
    printf("%d\n", QUEUEget());
  }
}
