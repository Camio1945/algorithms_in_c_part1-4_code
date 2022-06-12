/** 程序10.1：二进制快速排序 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))
#define exch(A, B) { Item t = A; A = B; B = t; }

typedef int Item;

static int N;

/** 打印数组 */
void printArr(char *prefix, int *a, int size) {
  printf("%s", prefix);
  for (int i = 0; i < size; i++) {
    printf("%3d ", a[i]);
  }
  printf("\n");
}

#define bitsword 32
#define bitsbyte 8
#define bytesword 4
#define R (1 << bitsbyte)
//#define digit(A, B) (((A) >> (bitsword-((B)+1)*bitsbyte)) & (R-1))
/* 上面的digit宏相当于以下代码
  int rightMove = bitsword - ((B + 1) * bitsbyte);
  A = A >> rightMove;
  int res = A & (R - 1);
  return res;
 */

int digit(int A, int B) {
  return A;
}

/**
 * 二进制快速排序
 * @param a 数组
 * @param l 左下标
 * @param r 右下标
 * @param w 正在被检查的位
 */
void quicksortB(int a[], int l, int r, int w) {
//  printf("\nw=%d", w);
  int i = l, j = r;
  if (r <= l || w > bitsword) {
    return;
  }
  while (j != i) {
    while (digit(a[i], w) == 0 && (i < j)) {
      i++;
    }
    while (digit(a[j], w) == 1 && (j > i)) {
      j--;
    }
    if (a[i] != a[j]) {
      exch(a[i], a[j]);
      printf("交换a[%d]和a[%d]\n", i, j);
      printArr("       ", a, 8);
    }
  }
  if (digit(a[r], w) == 0) {
    j++;
  }
  quicksortB(a, l, j - 1, w + 1);
  quicksortB(a, j, r, w + 1);
}

void sort(Item a[], int l, int r) {
  quicksortB(a, l, r, 0);
}

main() {
  setbuf(stdout, NULL);
  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("程序10.1：二进制快速排序\n");
//  int max = 10 + rand() % 15;
  int max = 8;
  int a[] = {1, 0, 1, 1, 1, 0, 0, 0};
  printArr("原数组：", a, max);
  sort(a, 0, max - 1);
  printArr("排序后：", a, max);
}
