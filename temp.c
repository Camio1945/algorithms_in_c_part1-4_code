#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef char *Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

main() {
  setbuf(stdout, NULL);
  int N = 2;
  Item *arr = malloc(N * sizeof(Item));
  arr[0] = "hello";
  arr[1] = "world";
  printf("%d\n", strcmp(arr[0], arr[1]));
  printf("%d\n", strcmp(arr[1], arr[0]));
  printf("%s\n", arr[0]);
  printf("%s\n", arr[1]);
  exch(arr[0], arr[1])
  printf("\n\n%d\n", strcmp(arr[0], arr[1]));
  printf("%d\n", strcmp(arr[1], arr[0]));
  printf("%s\n", arr[0]);
  printf("%s\n", arr[1]);
}

