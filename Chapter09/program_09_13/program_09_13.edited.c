/** 程序9.13：连接两个大小相等的2次幂堆 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)


/** 打印数组 */
void printArr(char *prefix, int *a, int size) {
  printf("%s", prefix);
  for (int i = 0; i < size; i++) {
    if (a[i] > 1000) {
      continue;
    }
    printf("%3d ", a[i]);
  }
  printf("\n");
}

typedef int Item;
typedef struct PQnode *PQlink;

struct PQnode {
  Item key;
  PQlink l, r;
};

/**
 * 两个大小相等的2次幂堆的合并
 * @param p 2次幂堆，要求与q的大小相等
 * @param q 2次幂堆，要求与q的大小相等
 * @return
 */
PQlink pair(PQlink p, PQlink q) {
  if (less(p->key, q->key)) {
    p->r = q->l;
    q->l = p;
    return q;
  } else {
    q->r = p->l;
    p->l = q;
    return p;
  }
}


/**
 * 打印节点
 * @param c 节点的名称
 * @param h 高度
 */
void printnode(int key, int h) {
  for (int i = 0; i < h; ++i) {
    printf("    ");
  }
  printf("%d\n", key);
}

/**
 * 显示树结构（程序5.18）
 * @param x 节点
 * @param h 高度
 */
void show(PQlink x, int h) {
  if (x == NULL) {
    // printnode('*', h);
    return;
  }
  show(x->r, h + 1);
  printnode(x->key, h);
  show(x->l, h + 1);
}


main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("程序9.13：连接两个大小相等的2次幂堆\n");
  PQlink node8 = malloc(sizeof(PQlink));
  node8->key = 8;

  PQlink node7 = malloc(sizeof(PQlink));
  node7->key = 7;

  PQlink node6 = malloc(sizeof(PQlink));
  node6->key = 6;

  PQlink node5 = malloc(sizeof(PQlink));
  node5->key = 5;

  PQlink node4 = malloc(sizeof(PQlink));
  node4->key = 4;

  PQlink node3 = malloc(sizeof(PQlink));
  node3->key = 3;

  PQlink node2 = malloc(sizeof(PQlink));
  node2->key = 2;

  PQlink node1 = malloc(sizeof(PQlink));
  node1->key = 1;

  node7->l = node5;
  node7->r = NULL;

  node5->l = node1;
  node5->r = node3;

  node1->l = NULL;
  node1->r = NULL;

  node3->l = NULL;
  node3->r = NULL;

  node8->l = node6;
  node8->r = NULL;

  node6->l = node2;
  node6->r = node4;

  node2->l = NULL;
  node2->r = NULL;

  node4->l = NULL;
  node4->r = NULL;

  PQlink res = pair(node7, node8);
  show(res, 0);
}
