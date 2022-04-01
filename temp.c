#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;

struct node {
  int item;
  link next;
};
int staticVar;

main() {
  int *arr = malloc(sizeof(int));
  int *arr2 = malloc(sizeof(int));
  int *arr3 = malloc(sizeof(int));
  printf("hello\n");
}
