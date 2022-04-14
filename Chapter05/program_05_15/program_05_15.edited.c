/** 程序5.15：前序遍历（非递归） */
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

int max = 8; // 这里指的是树节点的数量
link *STACK; // 栈
int tailIndex = -1; // 栈尾索引

/** 初始化栈 */
void STACKinit(int max) {
  STACK = malloc(sizeof(link) * max);
  for (int i = 0; i < max; ++i) {
    STACK[i] = NULL;
  }
}

/** 判断栈是否为空 */
int STACKempty() {
  return tailIndex == -1;
}


/** 入栈 */
void STACKpush(link h) {
  tailIndex++;
  STACK[tailIndex] = h;
}

/** 出栈 */
link STACKpop() {
  link h = STACK[tailIndex];
  STACK[tailIndex] = NULL;
  tailIndex--;
  return h;
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
  STACKinit(max);
  STACKpush(h);
  while (!STACKempty()) {
    h = STACKpop();
    visit(h);
    if (h->r != NULL) {
      STACKpush(h->r);
    }
    if (h->l != NULL) {
      STACKpush(h->l);
    }
  }
}

main() {
  setbuf(stdout, NULL);
  printf("非递归树遍历\n");
  link root = initTree();
  traverse(root, visitNode);
}
