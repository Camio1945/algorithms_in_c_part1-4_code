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
    printf("a[%d]=%c, a[%d]=%c\n", i, a[i], j, a[j]);
    exch(a[i], a[j])
    printArr("　　　　", a);
  }
  printf("a[%d]=%c, a[%d]=%c\n", i, a[i], r, a[r]);
  exch(a[i], a[r])
  printArr("　　　　", a);
  return i;
}

/**
 * 选择
 * @param a 数组
 * @param l 左下标
 * @param r 右下标
 * @param k 要找的中间值
 */
void select(Item a[], int l, int r, int k) {
  if (r <= l) {
    return;
  }
  int i = partition(a, l, r);
  if (i >= k) {
    select(a, l, i - 1, k);
  } else {
    select(a, i + 1, r, k);
  }
}

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("选择算法\n");
  int *a = malloc(N * sizeof(int));
  a[0] = 'A';
  a[1] = 'S';
  a[2] = 'O';
  a[3] = 'R';
  a[4] = 'T';
  a[5] = 'I';
  a[6] = 'N';
  a[7] = 'G';
  a[8] = 'E';
  a[9] = 'X';
  a[10] = 'A';
  a[11] = 'M';
  a[12] = 'P';
  a[13] = 'L';
  a[14] = 'E';
  printArr("排序前：", a);
  int middle = 7;
  select(a, 0, N - 1, middle);
  printArr("排序后：", a);
  printf("a[%d]=%c\n", middle, a[middle]);
}
