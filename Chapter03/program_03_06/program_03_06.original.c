#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  long int i, j, N = atoi(argv[1]);
  int *a = malloc(N * sizeof(int));
  if (a == NULL) {
    printf("Insufficient memory.\n");
    return -1;
  }
  for (i = 2; i < N; i++) a[i] = 1;
  for (i = 2; i < N; i++)
    if (a[i])
      for (j = i; i * j < N; j++) a[i * j] = 0;
  for (i = 2; i < N; i++)
    if (a[i]) printf("%4d ", i);
  printf("\n");
}
