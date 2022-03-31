/** 先进先出队列的链表实现方式 */
#include <stdlib.h>
#include <stdio.h>
#include "QUEUE.h"

typedef struct QUEUEnode *link;

struct QUEUEnode {
  Item item;
  link next;
};

static link head, tail;

/**
 * 队列初始化
 * @param maxN 没有用处。（这是为了兼容数组的实现方式而冗余的参数）
 */
void QUEUEinit(int maxN) {
  head = NULL;
  tail = NULL;
}

/** 判断队列是否为空 */
int QUEUEempty() {
  return head == NULL;
}

/**
 * 往队尾放入元素
 * @param item 元素
 */
void QUEUEput(Item item) {
  link newTail = malloc(sizeof(link));
  newTail->item = item;
  newTail->next = NULL;
  if (tail == NULL) {
    tail = newTail;
  } else {
    tail->next = newTail;
    tail = newTail;
  }
  if (head == NULL) {
    head = tail;
  }
}

/** 从队头获取元素 */
Item QUEUEget() {
  link first = head;
  head = head->next;
  return first->item;
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

