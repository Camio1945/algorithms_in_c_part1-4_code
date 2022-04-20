/** 程序6.1：使用驱动程序的数组排序的例子 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
/*
 if (B < A) {
   Item t = A;
   A = B;
   B = t;
 }
 */
int count = 0; // 用于统计比较次数

/**
 * 排序
 * @param a 数组
 * @param l 左下标
 * @param r 右下标
 */
void sort(Item a[], int l, int r) {
  int i, j;
  for (i = l + 1; i <= r; i++) {
    for (j = i; j > l; j--) {
      printf("排序前：a[%d]=%d、a[%d]=%d", j - 1, a[j - 1], j, a[j]);
      compexch(a[j - 1], a[j]);
      printf("\t排序后：a[%d]=%d、a[%d]=%d\n", j - 1, a[j - 1], j, a[j]);
      count++;
    }
  }
}

main() {
  setbuf(stdout, NULL);
  srand((unsigned) time(NULL)); // 初始化随机数种子
  printf("使用驱动程序的数组排序的例子\n");
  int i, N = 3;
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
