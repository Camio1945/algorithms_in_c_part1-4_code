/** 程序4.20：一级队列的链表实现 */

#include <stdlib.h>
#include "QUEUE.h"

typedef struct QUEUEnode *link;

struct QUEUEnode {
  Item item;
  link next;
};

struct queue {
  link head;
  link tail;
};

Q QUEUEinit(int maxN) {
  Q q = malloc(sizeof(Q));
  q->head = NULL;
  q->tail = NULL;
  return q;
}

int QUEUEempty(Q q) {
  return q->head == NULL;
}

void QUEUEput(Q q, Item item) {
  link newTail = malloc(sizeof(link));
  newTail->item = item;
  newTail->next = NULL;
  if (q->tail != NULL) {
    q->tail->next = newTail;
  }
  q->tail = newTail;
  if (q->head == NULL) {
    q->head = q->tail;
  }
}

Item QUEUEget(Q q) {
  link res = q->head;
  q->head = q->head->next;
  return res->item;
}
