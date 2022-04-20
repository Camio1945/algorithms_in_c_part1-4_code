/** 程序6.4：冒泡排序 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N = 10;

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
/* 以上的compexch宏相当于以下代码：
 if (B < A) {
   Item t = A;
   A = B;
   B = t;
 }
 */

/** 打印数组 */
void printArr(char *prefix, int *a) {
  printf("%s", prefix);
  for (int i = 0; i < N; i++) {
    printf("%3d ", a[i]);
  }
  printf("\n");
}

/**
 * 冒泡排序
 * @param a 数组
 * @param l 左下标
 * @param r 右下标
 */
void bubble(Item a[], int l, int r) {
  int i, j;
  for (i = r; i >= l; i--) {
    printf("i = %d：\n", i);
    for (j = l + 1; j <= i; j++) {
      compexch(a[j - 1], a[j])
      printArr("", a);
    }
  }
}

main() {
  setbuf(stdout, NULL);
  srand((unsigned) time(NULL)); // 初始化随机数种子
  printf("冒泡排序\n");
  int *a = malloc(N * sizeof(int));
  for (int i = 0; i < N; ++i) {
    a[i] = 1000 * (1.0 * rand() / RAND_MAX);
  }
  printArr("原数组：", a);
  bubble(a, 0, N - 1);
  printArr("排序后的数组：", a);
  printf("\n\n");
}
