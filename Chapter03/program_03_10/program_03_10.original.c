#include <stdlib.h>
#include <stdio.h>

typedef struct node *link;
struct node {
  int item;
  link next;
};

link reverse(link x) {
  link t, y = x, r = NULL;
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
  while (x->next != NULL) {
    printf("%d\n", x->item);
  }
}
