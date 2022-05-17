#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

/** 打印数组 */
void printArr(char *prefix, int *a, int size) {
  printf("%s", prefix);
  for (int i = 0; i < size; i++) {
    printf("%3d ", a[i]);
  }
  printf("\n");
}

#define maxN 10
Item aux[maxN];

/**
 * 归并
 * @param a 数组a
 * @param l 左下标
 * @param m 中间下标（从a[l]到a[m]的所有的数是有序的）
 * @param r 右下标（从a[m+1]到a[r]的所有的数是有序的）
 */
void merge(Item a[], int l, int m, int r) {
  int i, j, k;
  // for循环作用：把a[l]到a[m]顺序存入aux中
  for (i = m + 1; i > l; i--) {
    aux[i - 1] = a[i - 1];
  }
  // for循环作用：把a[m+1]到a[r]倒序存入aux中
  for (j = m; j < r; j++) {
    aux[r + m - j] = a[j + 1];
  }
  printArr("      aux：", aux, (r + 1));
  for (k = l; k <= r; k++) {
    // 把较小的那个赋给a[k]
    if (less(aux[j], aux[i])) {
      a[k] = aux[j];
      j--;
    } else {
      a[k] = aux[i];
      i++;
    }
  }
}

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("抽象原位归并算法\n");
  int N = 6;
  int *a = malloc(N * sizeof(int));
  // 注：本例中要求a可以分成两段，前半段是有序的，后半段也是有序的
  a[0] = 1;
  a[1] = 3;
  a[2] = 7;

  a[3] = 5;
  a[4] = 6;
  a[5] = 8;

  printArr("排序前数组a：", a, N);
  merge(a, 0, 2, N - 1);
  printArr("排序后数组a：", a, N);
}
