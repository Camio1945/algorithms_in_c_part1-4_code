/** 程序6.2：选择排序 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }

/**
 * 选择排序
 * @param a 数组
 * @param l 左下标
 * @param r 右下标
 */
void selection(Item a[], int l, int r) {
  int i, j;
  for (i = l; i < r; i++) {
    int min = i;
    for (j = i + 1; j <= r; j++) {
      if (less(a[j], a[min])) {
        min = j;
      }
    }
    exch(a[i], a[min])
  }
}

main() {
  setbuf(stdout, NULL);
  srand((unsigned) time(NULL)); // 初始化随机数种子
  printf("选择排序\n");
  int i, N = 3;
  int *a = malloc(N * sizeof(int));
  printf("原数组：");
  for (i = 0; i < N; i++) {
    a[i] = 1000 * (1.0 * rand() / RAND_MAX);
    printf("%3d ", a[i]);
  }
  selection(a, 0, N - 1);
  printf("\n排序后的数组：");
  for (i = 0; i < N; i++) {
    printf("%3d ", a[i]);
  }
  printf("\n\n");

}
