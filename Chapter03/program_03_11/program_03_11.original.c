#include <stdlib.h>
#include <stdio.h>

typedef struct node *link;
struct node {
  int item;
  link next;
};

main(int argc, char *argv[]) {
  struct node heada, headb;
  link t, u, x, a = &heada, b;
  int i, N = atoi(argv[1]);
  for (i = 0, t = a; i < N; i++) {
    t->next = malloc(sizeof *t);
    t = t->next;
    t->next = NULL;
    t->item = rand() % 1000;
  }
  b = &headb;
  b->next = NULL;
  for (t = a->next; t != NULL; t = u) {
    u = t->next;
    for (x = b; x->next != NULL; x = x->next)
      if (x->next->item > t->item) break;
    t->next = x->next;
    x->next = t;
  }
}
