/** 程序5.16：层序遍历 */
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
link *QUEUE; // 队列
int headIndex = -1; // 队列头索引
int tailIndex = -1; // 队列尾索引

/** 初始化队列 */
void QUEUEinit(int max) {
  QUEUE = malloc(sizeof(link) * max);
  for (int i = 0; i < max; ++i) {
    QUEUE[i] = NULL;
  }
}

/** 判断队列是否为空 */
int QUEUEempty() {
  return headIndex == -1;
}

/** 放到队列尾部 */
void QUEUEput(link h) {
  tailIndex++;
  QUEUE[tailIndex] = h;
  if (headIndex == -1) {
    headIndex = 0;
  }
}

/** 从队列头部获取 */
link QUEUEget() {
  link h = QUEUE[headIndex];
  QUEUE[headIndex] = NULL;
  headIndex++;
  if (QUEUE[headIndex] == NULL) {
    headIndex = -1;
    tailIndex = -1;
  }
  return h;
}

/**
 * 遍历
 * @param h 节点
 * @param visit 访问节点的函数（即以一个函数作为参数）
 */
void traverse(link h, void visit(link)) {
  QUEUEinit(max);
  QUEUEput(h);
  while (!QUEUEempty()) {
    link node = QUEUEget();
    visit(node);
    if (node->l != NULL) {
      QUEUEput(node->l);
    }
    if (node->r != NULL) {
      QUEUEput(node->r);
    }
  }
}

main() {
  setbuf(stdout, NULL);
  printf("层序遍历\n");
  link root = initTree();
  traverse(root, visitNode);
}
