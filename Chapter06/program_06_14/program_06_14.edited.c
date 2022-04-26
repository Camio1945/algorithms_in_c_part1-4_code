/** 程序6.14：原位排序 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }

int N = 15;

/** 打印数组 */
void printArr(char *prefix, int *a) {
  printf("%s", prefix);
  for (int i = 0; i < N; i++) {
    printf("%3c ", a[i]);
  }
  printf("\n");
}

/**
 * 原位排序
 * @param data 数组
 * @param a
 * @param N data数组的大小
 */
void insitu(Item data[], int a[], int N) {
  int i, j, k;
  for (i = 0; i < N; ++i) {
    Item v = data[i];
    for (k = i; a[k] != i; k = a[j], a[j] = j) {
      j = k;
      data[k] = data[a[k]];
      data[a[k]] = '_';
      printArr("　　　　　　　", data);
    }
    data[k] = v;
    a[k] = k;
    printArr("　　　　　　　", data);
  }
}

main() {
  setbuf(stdout, NULL);
  srand((unsigned) time(NULL)); // 初始化随机数种子
  printf("原位排序\n");
  int indexArr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  printf("　　　　下标：");
  for (int i = 0; i < N; i++) {
    printf("%3d ", indexArr[i]);
  }
  printf("\n");
  int *data = malloc(N * sizeof(int));
  int *a = malloc(N * sizeof(int));
  data[0] = 'A';
  data[1] = 'S';
  data[2] = 'O';
  data[3] = 'R';
  data[4] = 'T';
  data[5] = 'I';
  data[6] = 'N';
  data[7] = 'G';
  data[8] = 'E';
  data[9] = 'X';
  data[10] = 'A';
  data[11] = 'M';
  data[12] = 'P';
  data[13] = 'L';
  data[14] = 'E';
  printArr("　　　原数组：", data);
  a[0] = 0;
  a[1] = 10;
  a[2] = 8;
  a[3] = 14;
  a[4] = 7;
  a[5] = 5;
  a[6] = 13;
  a[7] = 11;
  a[8] = 6;
  a[9] = 2;
  a[10] = 12;
  a[11] = 3;
  a[12] = 1;
  a[13] = 4;
  a[14] = 9;
  insitu(data, a, N);
  printArr("排序后的数组：", data);
}
