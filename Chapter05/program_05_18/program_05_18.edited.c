/** 程序5.18：快速打印树的函数 */
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
 * 打印节点
 * @param c 节点的名称
 * @param h 高度
 */
void printnode(char c, int h) {
  for (int i = 0; i < h; ++i) {
    printf("    ");
  }
  printf("%c\n", c);
}

/**
 * 显示树结构
 * @param x 节点
 * @param h 高度
 */
void show(link x, int h) {
  if (x == NULL) {
    // printnode('*', h);
    return;
  }
  show(x->r, h + 1);
  printnode(x->item, h);
  show(x->l, h + 1);
}

main() {
  setbuf(stdout, NULL);
  printf("快速打印树的函数\n");
  link root = initTree();
  show(root, 0);
}
