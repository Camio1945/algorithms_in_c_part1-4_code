#include <stdlib.h>
#include "list.h"

/** 用于表示所有空闲的节点 */
link freelist;

/**
 * 初始化结点（即freelist）
 * @param N 节点的数量（实际会在内存中申请 N+1 个节点，多出来的那个节点用于维持freelist不为NULL）
 */
void initNodes(int N) {
  int i;
  freelist = malloc((N + 1) * (sizeof *freelist));
  for (i = 0; i < N + 1; i++) {
    freelist[i].next = &freelist[i + 1];
  }
  freelist[N].next = NULL;
}

/**
 * 新建节点（注意不是往freelist中新建节点，而是从freelist中拿出一个来）
 * @param i 节点的值
 * @return
 */
link newNode(int i) {
  link x = deleteNext(freelist);
  x->item = i;
  x->next = x; // 【注意】这句代码是必须的
  return x;
}

/**
 * 释放节点（把节点放回到freelist中）
 * @param x 要释放的节点
 */
void freeNode(link x) { insertNext(freelist, x); }

/**
 * 插入下一个节点，把t插入到x的后面
 * @param x
 * @param t
 */
void insertNext(link x, link t) {
  t->next = x->next;
  x->next = t;
}

/**
 * 删除x的下一个节点
 * @param x
 * @return 删除的节点
 */
link deleteNext(link x) {
  link t = x->next;
  x->next = t->next;
  return t;
}

/**
 * 获取x的下一个节点
 * @param x
 * @return
 */
link Next(link x) { return x->next; }

/**
 * 获取x节点的item值
 * @param x
 * @return
 */
int Item(link x) { return x->item; }
