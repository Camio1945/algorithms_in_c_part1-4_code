/** 程序9.9：无序双链表优先队列 */
#include "PQfull.h"
#include <stdlib.h>

struct PQnode {
  Item key;
  PQlink prev, next;
};

struct pq {
  PQlink head, tail;
};

/**
 * 初始化队列（pq的head和tail组成了一个环）
 * @return
 */
PQ PQinit() {
  PQ pq = malloc(sizeof *pq);
  PQlink h = malloc(sizeof *h);
  PQlink t = malloc(sizeof *t);
  h->prev = t;
  h->next = t;
  t->prev = h;
  t->next = h;
  pq->head = h;
  pq->tail = t;
  return pq;
}

/**
 * 队列是否为空
 * @param pq
 * @return
 */
int PQempty(PQ pq) {
  return pq->head->next->next == pq->head;
}

/**
 * 往队列中插入元素（插入到头节点的后面）
 * @param pq 队列
 * @param v 元素
 * @return
 */
PQlink PQinsert(PQ pq, Item v) {
  PQlink t = malloc(sizeof *t);
  t->key = v;
  t->next = pq->head->next;
  t->next->prev = t;
  t->prev = pq->head;
  pq->head->next = t;
  return t;
}

/**
 * 删除最大的元素
 * @param pq
 * @return
 */
Item PQdelmax(PQ pq) {
  Item max;
  struct PQnode *t, *x = pq->head->next;
  for (t = x; t->next != pq->head; t = t->next) {
    if (t->key > x->key) {
      x = t;
    }
  }
  max = x->key;
  x->next->prev = x->prev;
  x->prev->next = x->next;
  free(x);
  return max;
}

void PQchange(PQ pq, PQlink x, Item v) {
  x->key = v;
}

void PQdelete(PQ pq, PQlink x) {
  x->next->prev = x->prev;
  x->prev->next = x->next;
  free(x);
}

/**
 * 合并两个链表（把b挂到a的后面）
 * @param a
 * @param b
 */
void PQjoin(PQ a, PQ b) {
  a->tail->prev->next = b->head->next;
  b->head->next->prev = a->tail->prev;
  a->head->prev = b->tail;
  b->tail->next = a->head;
  free(a->tail);
  free(b->head);
}
