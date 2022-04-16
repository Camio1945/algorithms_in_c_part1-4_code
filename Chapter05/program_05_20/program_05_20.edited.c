/** 程序5.20：分析树的构造 */
#include <stdio.h>
#include <stdlib.h>

char a[] = {'*', '+', 'a', '*', '*', 'b', 'c', '+', 'd', 'e', 'f'};
//char a[] = {'*', 'c', '+', 'a', 'b'};
int i = 0;

typedef struct Tnode *link;
struct Tnode {
  char token; // 符号
  link l; // 左边节点
  link r; // 右边节点
};

/**
 * 新建节点
 * @param token 节点的符号
 * @param l 节点左侧的节点
 * @param r 节点右侧的节点
 * @return
 */
link NEW(char token, link l, link r) {
  link x = malloc(sizeof(link));
  x->token = token;
  x->l = l;
  x->r = r;
  return x;
}

/** 解析 */
link parse() {
  char t = a[i];
  i++;
  link x = NEW(t, NULL, NULL);
  if (t == '+' || t == '*') {
    x->l = parse();
    x->r = parse();
  }
  return x;
}


/**
 * 打印节点
 * @param c 节点的名称
 * @param h 高度
 */
void printTnode(char c, int h) {
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
    return;
  }
  show(x->r, h + 1);
  printTnode(x->token, h);
  show(x->l, h + 1);
}

main() {
  setbuf(stdout, NULL);
  printf("分析树的构造\n");
  link x = parse();
  show(x, 0);
}
