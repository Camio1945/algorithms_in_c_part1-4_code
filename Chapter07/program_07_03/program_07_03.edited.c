/** 程序7.3：非递归快速排序 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "STACK_by_array.c"

#define N 20

/** 打印数组 */
void printArr(char *prefix, int *a) {
  printf("%s", prefix);
  for (int i = 0; i < N; i++) {
    printf("%3d ", a[i]);
  }
  printf("\n");
}

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
#define push2(A, B) STACKpush(B); STACKpush(A);

/**
 * 划分（程序7.2）
 * 设定一个基准值（我们这里取的是a[r]）
 * 从左往右遍历a[l]到a[r-1]，如果值比a[r]大(或相等)，则应该排到a[r]的右边
 * 从右往左遍历a[r-1]到a[l]，如果值比a[r]小，则应该排到a[r]的左边
 * 左遍历的下标与右遍历的下标重合时，结束遍历
 * 把基准值放到指定位置（即与最后一次左遍历的下标对调）
 * @param a 数组
 * @param l 左下标
 * @param r 右下标
 * @return
 */
int partition(Item a[], int l, int r) {
  int i = l; // 从左往右遍历的下标
  int j = r; // 从右往左遍历的下标
  int v = a[r];
  while (1) {
    // while循环作用：在数组a中查找值大于等于v的下标(从左往右找)
    while (a[i] < v) {
      i++;
    }
    // while循环作用：在数组a中查找值小于v的下标（从右往左找）
    while (a[j] >= v && j >= i) {
      j--;
    }
    if (i >= j) {
      break;
    }
    exch(a[i], a[j])
    printArr("　　　　", a);
  }
  exch(a[i], a[r])
  printArr("　　　　", a);
  return i;
}


void quicksort(Item a[], int l, int r) {
  int i;
  STACKinit(N);
  push2(l, r)
  while (!STACKempty()) {
    l = STACKpop();
    r = STACKpop();
    if (r <= l) {
      continue;
    }
    i = partition(a, l, r);
    printf("i = %d\n", i);
//    push2(l, i - 1);
//    push2(i + 1, r);
    if (i - l > r - i) {
      push2(l, i - 1);
      push2(i + 1, r);
    } else {
      push2(i + 1, r);
      push2(l, i - 1);
    }
  }
}

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("非递归快速排序\n");
  int *a = malloc(N * sizeof(int));
  for (int i = 0; i < N; ++i) {
    a[i] = 1000 * (1.0 * rand() / RAND_MAX);
  }
  printArr("排序前：", a);
  quicksort(a, 0, N - 1);
  printArr("排序后：", a);
}
