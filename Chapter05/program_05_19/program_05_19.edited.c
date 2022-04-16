/** 程序5.19：联赛的构造 */
#include <stdio.h>
#include <stdlib.h>

typedef char Item;
typedef struct node *link;
struct node {
  Item item; // 节点的值
  link l; // 左边节点
  link r; // 右边节点
};

/**
 * 新建节点
 * @param item 节点的值
 * @param l 节点左侧的节点
 * @param r 节点右侧的节点
 * @return
 */
link NEW(Item item, link l, link r) {
  link x = malloc(sizeof(link));
  x->item = item;
  x->l = l;
  x->r = r;
  return x;
}

/**
 * 构造联赛并返回最大的节点（冠军）
 * @param a 队伍数组
 * @param l 左边索引
 * @param r 右边索引
 * @return
 */
link max(Item a[], int l, int r) {
  int m = (l + r) / 2;
  link x = NEW(a[m], NULL, NULL);
  if (l == r) {
    return x;
  }
  x->l = max(a, l, m);
  x->r = max(a, m + 1, r);
  Item lMaxItem = x->l->item;
  Item rMaxItem = x->r->item;
  x->item = lMaxItem > rMaxItem ? lMaxItem : rMaxItem;
  return x;
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
    return;
  }
  show(x->r, h + 1);
  printnode(x->item, h);
  show(x->l, h + 1);
}

main() {
  setbuf(stdout, NULL);
  printf("联赛的构造\n");
  int teamNumber = 4; // 队伍的数量
  Item arr[teamNumber];
  for (int i = 0; i < teamNumber; ++i) {
    arr[i] = 'A' + i;
  }
  link x = max(arr, 0, teamNumber - 1);
  show(x, 0);
}
