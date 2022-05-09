#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

#define N 15

/** 打印数组 */
void printArr(char *prefix, int *a) {
  printf("%s", prefix);
  for (int i = 0; i < N; i++) {
    printf("%3c ", a[i]);
  }
  printf("\n");
}

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

/**
 * 快速排序
 * @param a 数组
 * @param l 左下标
 * @param r 右下标
 */
void quicksort(Item a[], int l, int r) {
  int i, j, k, p, q;
  if (r <= l) {
    return;
  }
  Item v = a[r];
  i = l - 1;
  j = r;
  p = l - 1;
  q = r;
  for (;;) {
    while (less(a[++i], v));
    while (less(v, a[--j])) {
      if (j == l) {
        break;
      }
    }
    if (i >= j) {
      break;
    }
    printf("a[%d]=%c, a[%d]=%c\n", i, a[i], j, a[j]);
    exch(a[i], a[j]);
    printArr("　　　　", a);
    // 如果左边的元素与划分元素相等，将它交换到数组的最左边(p所在的位置)
    if (eq(a[i], v)) {
      p++;
      printf("a[%d]=%c, a[%d]=%c\n", p, a[p], i, a[i]);
      exch(a[p], a[i])
      printArr("　　　　", a);
    }
    // 如果右边的元素与划分元素相等，将它交换到数组的右边(q所在的位置)
    if (eq(v, a[j])) {
      q--;
      printf("a[%d]=%c, a[%d]=%c\n", q, a[q], j, a[j]);
      exch(a[q], a[j])
      printArr("　　　　", a);
    }
  }
  printf("a[%d]=%c, a[%d]=%c\n", i, a[i], r, a[r]);
  exch(a[i], a[r])
  printArr("　　　　", a);
  j = i - 1;
  i = i + 1;
  // 最左边与划分元素相等的，移到中间去
  for (k = l; k <= p; k++, j--) {
    printf("a[%d]=%c, a[%d]=%c\n", k, a[k], j, a[j]);
    exch(a[k], a[j]);
    printArr("　　　　", a);
  }
  // 最右边与划分元素相等的，移到中间去
  for (k = r - 1; k >= q; k--, i++) {
    printf("a[%d]=%c, a[%d]=%c\n", k, a[k], i, a[i]);
    exch(a[k], a[i]);
    printArr("　　　　", a);
  }
  quicksort(a, l, j);
  quicksort(a, i, r);
}

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("三路划分的快速排序算法\n");
  int *a = malloc(N * sizeof(int));
  a[0] = 'A';
  a[1] = 'B';
  a[2] = 'R';
  a[3] = 'A';
  a[4] = 'C';
  a[5] = 'A';
  a[6] = 'C';
  a[7] = 'A';
  a[8] = 'B';
  a[9] = 'R';
  a[10] = 'A';
  a[11] = 'B';
  a[12] = 'C';
  a[13] = 'D';
  a[14] = 'C';
  printArr("排序前：", a);
  quicksort(a, 0, N - 1);
  printArr("排序后：", a);
}
