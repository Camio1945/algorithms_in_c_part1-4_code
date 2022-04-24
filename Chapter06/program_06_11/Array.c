#include "Item.c"
#include "Array.h"

/**
 * 使用随机数初始化数组中的值
 * @param a
 * @param N
 */
void randinit(Item a[], int N) {
  // 未实现
}

/**
 * 从控制台输入来初始化数组中的值
 * @param a
 * @param N
 */
void scaninit(Item a[], int *N) {
  int i;
  for (i = 0; i < *N; ++i) {
    if (ITEMscan(&a[i]) == EOF) {
      break;
    }
  }
  *N = i;
}

/**
 * 显示数组中的值
 * @param a
 * @param l
 * @param r
 */
void show(Item a[], int l, int r) {
  for (int i = l; i <= r; ++i) {
    ITEMshow(a[i]);
  }
  printf("\n");
}

/**
 * 数组排序（这里用的是程序6.2中的选择排序）
 * @param a
 * @param l
 * @param r
 */
void sort(Item a[], int l, int r) {
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
