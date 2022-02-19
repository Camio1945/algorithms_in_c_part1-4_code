#include <stdlib.h>
#include <stdio.h>

typedef struct node *link;
struct node {
  int item;
  link next;
};

/** 逆序 */
link reverse(link x) {
  link t, y = x, r = NULL;
  // 以下4行是关键代码
  while (y != NULL) {
    t = y->next;
    y->next = r;
    r = y;
    y = t;
  }
  return r;
}

main(int argc, char *argv[]) {
  link x = malloc(sizeof(link));
  x->item = 1;
  x->next = NULL;
  link temp, tail = x;
  for (int i = 2; i <= 5; i++) {
    temp = malloc(sizeof(link));
    temp->item = i;
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
  }
  printf("原链表：\n");
  temp = x;
  while (temp != NULL) {
    printf("%d ", temp->item);
    temp = temp->next;
  }
  link r = reverse(x);
  printf("\n逆序之后的链表：\n");
  while (r != NULL) {
    printf("%d ", r->item);
    link toBeFree = r;
    r = r->next;
    free(toBeFree);
  }
}
