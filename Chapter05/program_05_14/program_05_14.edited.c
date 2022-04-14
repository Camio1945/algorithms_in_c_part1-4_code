/** 程序5.14：递归树遍历 */
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

/** 访问节点 */
void visitNode(link h) {
  printf("%c ", h->item);
}

/**
 * 遍历
 * @param h 节点
 * @param visit 访问节点的函数（即以一个函数作为参数）
 */
void traverse(link h, void visit(link)) {
  if (h == NULL) {
    return;
  }
  visit(h);
  traverse(h->l, visit);
  traverse(h->r, visit);
}

main() {
  setbuf(stdout, NULL);
  printf("递归树遍历\n");
  link root = initTree();
  traverse(root, visitNode);
}
