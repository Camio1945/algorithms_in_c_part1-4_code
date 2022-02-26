#include "Chapter03/program_03_12-03_13-03_14/list.h"
#include <stdlib.h>

link freelist;

void initNodes(int N) {
  freelist = malloc((N + 1) * sizeof(link));
  for (int i = 0; i < N + 1; i++) {
    freelist[i].next = &freelist[i + 1];
  }
  freelist[N].next = NULL;
}

link newNode(int i) {
  link x = deleteNext(freelist);
  x->item = i;
  x->next = x;
  return x;
}

void freeNode(link x) {
  insertNext(freelist, x);
}

void insertNext(link x, link t) {
  t->next = x->next;
  x->next = t;
}

link deleteNext(link x) {
  link t = x->next;
  x->next = t->next;
  return t;
}

link Next(link x) {
  return x->next;
}

int Item(link x) {
  return x->item;
}



