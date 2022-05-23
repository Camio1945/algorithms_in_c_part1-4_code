/** 程序8.6：链表归并 */
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
  struct node head;
  link t = &head;
  t->item = -1;
  t->next = NULL;
  while ((a != NULL) && (b != NULL)) {
    if (less(a->item, b->item)) {
      t->next = a;
      t = a;
      a = a->next;
      printf("\n");
      printLink("        a：", a);
      printLink("        b：", b);
      printLink("        t：", t);
      printLink("     head：", &head);
    } else {
      t->next = b;
      t = b;
      b = b->next;
      printf("\n");
      printLink("        a：", a);
      printLink("        b：", b);
      printLink("        t：", t);
      printLink("     head：", &head);
    }
  }

  t->next = (a == NULL) ? b : a;
  printf("\n");
  printLink("        a：", a);
  printLink("        b：", b);
  printLink("        t：", t);
  printLink("     head：", &head);
  return head.next;
}

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("程序8.6：链表归并\n");
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

  a->next = c;
  c->next = e;

  b->next = d;
  d->next = f;

  e->next = NULL;
  f->next = NULL;

  printLink("排序前的a：", a);
  printLink("排序前的b：", b);
  a = merge(a, b);
  printLink("排序后的a：", a);
}
