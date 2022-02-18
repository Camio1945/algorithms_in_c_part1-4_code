#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node {
  int item;
  link next;
};

int main(int argc, char *argv[]) {
  int i, N = atoi(argv[1]), M = atoi(argv[2]);
  printf("%d %d", N, M);
  int size = sizeof(link);
  link t = malloc(size);
  link x = t;
  t->item = 1;
  t->next = t;
  for (i = 2; i <= N; ++i) {
    x = (x->next = malloc(size));
    x->item = i;
    x->next = t;
  }
  while (x != x->next) {
    for (i = 1; i < M; ++i) {
      x = x->next;
    }
    link to_be_deleted = x->next;
    x->next = x->next->next;
    free(to_be_deleted);
  }
  printf("\nmaster : %d", x->item);
  return 0;
}
