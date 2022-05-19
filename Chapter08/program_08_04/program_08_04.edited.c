/** 程序8.4：没有复制的归并排序 */
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
 * 归并（程序8.1）
 * @param c 合并之后最终的数组
 * @param a 要合并的数组a
 * @param N 数组a的大小
 * @param b 要合并的数组b
 * @param M 数组b的大小
 */
void mergeAB(Item c[], Item a[], int N, Item b[], int M) {
  int i, j, k;
  for (i = 0, j = 0, k = 0; k < N + M; k++) {
    if (i == N) {
      c[k] = b[j++];
      continue;
    }
    if (j == M) {
      c[k] = a[i++];
      continue;
    }
    c[k] = (less(a[i], b[j])) ? a[i++] : b[j++];
  }
}

/**
 * 插入排序（程序6.3）
 * @param a 数组
 * @param l 左下标
 * @param r 右下标
 */
void insertion(Item a[], int l, int r) {
  int i;
  // for循环的作用，把数组中最小的那个数排到最前面
  for (i = r; i > l; i--) {
    compexch(a[i - 1], a[i])
  }
  for (i = l + 2; i <= r; i++) {
    int v = a[i];
    int j = i;
    while (less(v, a[j - 1])) {
      a[j] = a[j - 1];
      a[j - 1] = -1; // 本行代码为演示代码，表示a[j-1]的位置空出来了，可删除
      j--;
    }
    a[j] = v;
  }
}

/**
 *
 * @param a 数组
 * @param b
 * @param l 左下标
 * @param r 右下标
 */
void mergesortABr(Item a[], Item b[], int l, int r) {
  int m = (l + r) / 2;
  if (r - l <= 10) {
    insertion(a, l, r);
    return;
  }
  mergesortABr(b, a, l, m);
  mergesortABr(b, a, m + 1, r);
  mergeAB(a + l, b + l, m - l + 1, b + m + 1, r - m);
}

/**
 * 归并排序
 * @param a 数组
 * @param l 左下标
 * @param r 右下标
 */
void mergesortAB(Item a[], int l, int r) {
  int i;
  for (i = l; i <= r; i++) {
    aux[i] = a[i];
  }
  mergesortABr(a, aux, l, r);
}

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("程序8.4：没有复制的归并排序\n");
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
  mergesortAB(a, 0, N - 1);
  printArr("排序后数组a：", a, N);
}
