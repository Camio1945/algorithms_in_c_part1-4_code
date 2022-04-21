/** 程序6.5：希尔排序 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N = 8;

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

int count = 0;

/**
 * 希尔排序
 * @param a 数组
 * @param l 左下标
 * @param r 右下标
 */
void shellsort(Item a[], int l, int r) {
  int i, j, h = (r - l + 1) / 2;
//  h = 1;
  for (; h > 0; h /= 2) {
    count++;
    printf("h = %d\n", h);
    for (i = l + h; i <= r; i++) {
      count++;
      printf("\ti = %d\n", i);
      j = i;
      Item v = a[i];
      while (j >= l + h && less(v, a[j - h])) {
        count++;
        a[j] = a[j - h];
        a[j - h] = -1; // 本行代码为演示代码，表示a[j-h]的位置空出来了，可删除
        j -= h;
        printArr("\t\t", a);
      }
      a[j] = v;
      printArr("\t\t", a);
    }
  }
}

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  printf("希尔排序\n");
  int *a = malloc(N * sizeof(int));
//  for (int i = 0; i < N; ++i) {
//    a[i] = 1000 * (1.0 * rand() / RAND_MAX);
//  }
  a[0] = 7;
  a[1] = 6;
  a[2] = 9;
  a[3] = 3;
  a[4] = 1;
  a[5] = 5;
  a[6] = 2;
  a[7] = 4;
  printArr("原数组：", a);
  shellsort(a, 0, N - 1);
  printArr("排序后的数组：", a);
  printf("\ncount = %d", count);
  printf("\n\n");
}
