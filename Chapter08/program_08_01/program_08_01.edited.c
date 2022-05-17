/** 程序8.1：归并 */
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

/**
 * 归并
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
      printf("b[%d] = %d", j, b[j]);
      c[k] = b[j++];
      printf(", c[%d] = %d\n", k, c[k]);
      continue;
    }
    if (j == M) {
      printf("a[%d] = %d", i, a[i]);
      c[k] = a[i++];
      printf(", c[%d] = %d\n", k, c[k]);
      continue;
    }
    printf("a[%d] = %d, b[%d] = %d", i, a[i], j, b[j]);
    c[k] = (less(a[i], b[j])) ? a[i++] : b[j++];
    printf(", c[%d] = %d\n", k, c[k]);
    /*
    if (a[i] < b[j]) {
      c[k] = a[i];
      i++;
    } else {
      c[k] = b[j];
      j++;
    }
    */
  }
}


main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("归并\n");
  int N = 5;
  int M = 8;
  int *a = malloc(N * sizeof(int));
  int *b = malloc(M * sizeof(int));
  int *c = malloc((N + M) * sizeof(int));
  // 注：本例中要求a和b中的数是已经排好了序的
  a[0] = 1;
  a[1] = 3;
  a[2] = 5;
  a[3] = 7;
  a[4] = 9;

  b[0] = 4;
  b[1] = 5;
  b[2] = 6;
  b[3] = 7;
  b[4] = 8;
  b[5] = 9;
  b[6] = 10;
  b[7] = 11;

  printArr("排序前数组a：", a, N);
  printArr("排序前数组b：", b, M);
  mergeAB(c, a, N, b, M);
  printArr("排序后数组c：", c, N + M);
}
