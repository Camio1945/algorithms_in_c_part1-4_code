/** 程序8.5：自底向上的归并排序 */
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
    printf("%3c ", a[i]);
  }
  printf("\n");
}

#define maxN 20
Item aux[maxN];

/**
 * 归并（程序8.2）
 * @param a 数组a
 * @param l 左下标
 * @param m 中间下标（从a[l]到a[m]的所有的数是有序的）
 * @param r 右下标（从a[m+1]到a[r]的所有的数是有序的）
 */
void merge(Item a[], int l, int m, int r) {
  printf("\nl = %d, m = %d, r = %d\n", l, m, r);
  int i, j, k;
  // for循环作用：把a[l]到a[m]顺序存入aux中
  for (i = m + 1; i > l; i--) {
    aux[i - 1] = a[i - 1];
  }
  // for循环作用：把a[m+1]到a[r]倒序存入aux中
  for (j = m; j < r; j++) {
    aux[r + m - j] = a[j + 1];
  }
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

#define min(A, B) (A < B) ? A : B

/**
 * 归并排序
 * @param a 数组
 * @param l 左下标
 * @param r 右下标
 */
void mergesortBU(Item a[], int l, int r) {
  int i, m;
  for (m = 1; m <= r - l; m = m + m) {
    for (i = l; i <= r - m; i += m + m) {
      merge(a, i, i + m - 1, min(i + m + m - 1, r));
      printArr("        a：", a, 15);
    }
  }
}

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("程序8.5：自底向上的归并排序\n");
  int N = 15;
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
  printArr("排序前数组a：", a, N);
  mergesortBU(a, 0, N - 1);
  printArr("排序后数组a：", a, N);
}
