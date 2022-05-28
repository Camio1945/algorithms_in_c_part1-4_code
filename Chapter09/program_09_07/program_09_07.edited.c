/** 程序9.7：堆排序 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

typedef int Item;


/** 打印数组 */
void printArr(char *prefix, int *a, int size) {
  printf("%s", prefix);
  for (int i = 0; i < size; i++) {
    if (a[i] > 1000) {
      continue;
    }
    printf("%3d ", a[i]);
  }
  printf("\n");
}

/**
 * 程序9.3：自底向上堆化（仅适用于添加新元素时）
 * @param a
 * @param k
 */
void fixUp(Item a[], int k) {
  while (k > 1 && less(a[k / 2], a[k])) {
    exch(a[k], a[k / 2]);
    k = k / 2;
  }
}

/**
 * 程序9.4：自顶向下堆化（仅适用于删除最大元素时）
 * @param a
 * @param k
 * @param N
 */
void fixDown(Item a[], int k, int N) {
  int j;
  while (2 * k <= N) {
    j = 2 * k;
    if (j < N && less(a[j], a[j + 1])) {
      j++;
    }
    if (!less(a[k], a[j])) {
      break;
    }
    exch(a[k], a[j]);
    k = j;
  }
}

/**
 * 堆排序
 * @param a 数组
 * @param l 左下标
 * @param r 右下标
 */
void heapsort(Item a[], int l, int r) {
  int k, N = r - l + 1;
  Item *pq = a + l - 1;
  for (k = N / 2; k >= 1; k--) {
    printArr("   pq：", pq, r + 2);
    fixDown(pq, k, N);
  }
  printArr("   pq：", pq, r + 2);
  printf("\n");
  while (N > 1) {
    exch(pq[1], pq[N]);
    printArr("   pq：", pq, r + 2);
    fixDown(pq, 1, --N);
    printArr("   pq：", pq, r + 2);
    printf("\n");
  }
  printArr("   pq：", pq, r + 2);
}


main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("程序9.7：堆排序\n");
  int max = 8;
  int *a = malloc(max * sizeof(int));
  for (int i = 0; i < max; ++i) {
    a[i] = 1000 * (1.0 * rand() / RAND_MAX);
  }
  printArr("原数组：", a, max);
  heapsort(a, 0, max - 1);
  printArr("排序后：", a, max);
}
