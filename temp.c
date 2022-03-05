#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Nmax 1000

char buf[10000];
int M = 0;

int compare(const void *i, const void *j) {
  return strcmp(*(char **) i, *(char **) j);
}

main() {
  int i, N;
  char *arr[Nmax]; // 指针数组
  for (N = 0; i < Nmax; ++N) {
    arr[N] = &buf[M];
    if (scanf("%s", arr[N]) == EOF) {
      break;
    }
    M += strlen(arr[N]) + 1;
  }
  qsort(arr, N, sizeof(char *), compare);
  for (int j = 0; j < N; ++j) {
    printf("%s\n", arr[j]);
  }
}
