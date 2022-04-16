/** 程序5.17：树参数计算 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node {
  char item; // 节点的值
  link l; // 左下边节点
  link r; // 右下边节点
};

/** 初始化树 */
link initTree() {
  link A = malloc(sizeof(link));
  link B = malloc(sizeof(link));
  link C = malloc(sizeof(link));
  link D = malloc(sizeof(link));
  link E = malloc(sizeof(link));
  link F = malloc(sizeof(link));
  link G = malloc(sizeof(link));
  link H = malloc(sizeof(link));
  A->item = 'A';
  B->item = 'B';
  C->item = 'C';
  D->item = 'D';
  E->item = 'E';
  F->item = 'F';
  G->item = 'G';
  H->item = 'H';
  // @formatter:off
  E->l = D;
    D->l = B;
      B->l = A;
        A->l = NULL;
        A->r = NULL;
      B->r = C;
        C->l = NULL;
        C->r = NULL;
    D->r = NULL;
  E->r = H;
    H->l = F;
      F->l = G;
        G->l = NULL;
        G->r = NULL;
      F->r = NULL;
    H->r = NULL;
  // @formatter:on
  return E;
}

/**
 * 计算树结点的数量
 * @param h
 * @return
 */
int count(link h) {
  if (h == NULL) {
    return 0;
  }
  // 自己算1个节点，加上左侧节点的数量，再加上右侧节点的数量，就等于本节点下的全部数量
  return 1 + count(h->l) + count(h->r);
}

/**
 * 计算树的高度
 * @param h
 * @return
 */
int height(link h) {
  if (h == NULL) {
    return 0;
  }
  int lHeight = height(h->l); // 左侧子节点的高度
  int rHeight = height(h->r); // 右侧子节点的高度
  int max = lHeight >= rHeight ? lHeight : rHeight; // 取两个中更高的那一个
  return max + 1; // 加上自身的高度
}


main() {
  setbuf(stdout, NULL);
  printf("树参数计算\n");
  link root = initTree();
  printf("树节点的数量为：%d\n", count(root));
  printf("树的高度为：%d\n", height(root));
}
