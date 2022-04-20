#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define compexch(A, B) if(less(B, A)) exch(A, B)

int count = 0;

void sort(Item a[], int l, int r) {
  int i, j;
  for (j = l + 1; j <= r; j++) {
    for (i = j; i <= r; i++) {
      compexch(a[j - 1], a[i])
      count++;
    }
  }
}

main() {
  setbuf(stdout, NULL);
  srand((unsigned) time(NULL)); // 初始化随机数种子
  printf("使用驱动程序的数组排序的例子\n");
  int i, N = 4;
  int *a = malloc(N * sizeof(int));
  printf("原数组：");
  for (i = 0; i < N; i++) {
    a[i] = 1000 * (1.0 * rand() / RAND_MAX);
    printf("%3d ", a[i]);
  }
  printf("\n\n");

  sort(a, 0, N - 1);
  printf("\n\n排序后的数组：");
  for (i = 0; i < N; i++) {
    printf("%3d ", a[i]);
  }
  printf("\n\n");

  printf("数组大小：%d，总比较次数：%d（等于%d的阶乘）\n", N, count, (N - 1));
}

