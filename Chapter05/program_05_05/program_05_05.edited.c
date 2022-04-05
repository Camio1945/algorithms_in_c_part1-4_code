/** 程序5.5：链表递归函数示例 */
#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct node *link;
struct node {
  Item item;
  link next;
};

/** 计算链表的大小 */
int count(link x) {
  if (x == NULL) {
    return 0;
  }
  return 1 + count(x->next);
}

/**
 * 顺序遍历链表
 * @param h
 * @param visit
 */
void traverse(link h, void visit(link)) {
  if (h == NULL) {
    return;
  }
  visit(h);
  traverse(h->next, visit);
}

/**
 * 逆序遍历链表
 * @param h
 * @param visit
 */
void traverseR(link h, void visit(link)) {
  if (h == NULL) {
    return;
  }
  traverseR(h->next, visit);
  visit(h);
}

/**
 * 从链表x中删除值为v的节点
 * @param x
 * @param v
 */
link delete(link x, Item v) {
  if (x == NULL) {
    return NULL;
  }
  if (x->item == v) {
    link t = x->next;
    free(x);
    return t;
  }
  x->next = delete(x->next, v);
  return x;
}

/** 初始化链表 */
link initLink() {
  link head = malloc(sizeof(link));
  link x = head;
  int i = 1;
  int number = 5;
  while (i <= number) {
    x->item = i;
    if (i != number) {
      x->next = malloc(sizeof(link));
      x = x->next;
    } else {
      x->next = NULL;
    }
    i++;
  }
  return head;
}

/** 访问节点 */
void visitNode(link h) {
  printf("%d ", h->item);
}

main() {
  setbuf(stdout, NULL);
  link head = initLink();
  printf("链表的大小为：%d\n", count(head));

  printf("顺序递归访问链表：");
  traverse(head, visitNode);
  printf("\n");

  printf("逆序递归访问链表：");
  traverseR(head, visitNode);
  printf("\n");

  head = delete(head, 3);
  printf("从链表中删除3以后再顺序递归访问链表：");
  traverse(head, visitNode);
  printf("\n");
}
