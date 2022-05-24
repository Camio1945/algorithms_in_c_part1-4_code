/** 程序8.7：自顶向下链表归并排序 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)


typedef struct node *link;
struct node {
  int item;
  link next;
};

/** 打印链表 */
void printLink(char *prefix, link a) {
  printf("%s", prefix);
  while (a != NULL) {
    printf("%d ", a->item);
    a = a->next;
  }
  printf("\n");
}

/**
 * 归并，把两个已经有序的链表a和链表b归并，归并后的结果保存在a中
 * @param a 链表a，要求其中的数据是有序的
 * @param b 链表b，要求其中的数据是有序的
 * @return
 */
link merge(link a, link b) {
  printf("\n");
  printLink("merge  a：", a);
  printLink("merge  b：", b);
  struct node head;
  link t = &head;
  t->item = -1;
  t->next = NULL;
  while ((a != NULL) && (b != NULL)) {
    if (less(a->item, b->item)) {
      t->next = a;
      t = a;
      a = a->next;
    } else {
      t->next = b;
      t = b;
      b = b->next;
    }
  }
  t->next = (a == NULL) ? b : a;
  return head.next;
}

/**
 * 链表归并排序
 * @param c
 * @return
 */
link mergesort(link c) {
  if (c == NULL || c->next == NULL) {
    return c;
  }
  link a = c;
  link b = c->next;
  while ((b != NULL) && (b->next != NULL)) {
    c = c->next;
    b = b->next->next;
  }
  b = c->next;
  c->next = NULL;
  printf("\n");
  printLink("       a：", a);
  printLink("       b：", b);
  return merge(mergesort(a), mergesort(b));
}

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("程序8.7 自顶向下链表归并排序\n");
  link a = malloc(sizeof(link));
  link b = malloc(sizeof(link));
  link c = malloc(sizeof(link));
  link d = malloc(sizeof(link));
  link e = malloc(sizeof(link));
  link f = malloc(sizeof(link));

  a->item = 1;
  b->item = 2;
  c->item = 3;
  d->item = 4;
  e->item = 5;
  f->item = 6;

  c->next = b;
  b->next = e;
  e->next = d;
  d->next = f;
  f->next = a;
  a->next = NULL;

  printLink("排序前的c：", c);
  c = mergesort(c);
  printLink("排序后的c：", c);
}
