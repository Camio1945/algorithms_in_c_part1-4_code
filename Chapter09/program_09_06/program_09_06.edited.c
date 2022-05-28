/** 程序9.6：使用优先队列进行排序 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

typedef int Item;

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

static Item *pq;
static int N;

/** 打印数组 */
void printArr(char *prefix, int *a, int size) {
  printf("%s", prefix);
  for (int i = 0; i < size; i++) {
    printf("%3d ", a[i]);
  }
  printf("\n");
}

void PQinit(int maxN) {
  pq = malloc((maxN + 1) * sizeof(Item));
  N = 0;
}

int PQempty() {
  return N == 0;
}

void PQinsert(Item v) {
  pq[++N] = v;
  fixUp(pq, N);
}

Item PQdelmax() {
  exch(pq[1], pq[N]);
  fixDown(pq, 1, N - 1);
  return pq[N--];
}

/**
 * 优先队列排序
 * @param a
 * @param l
 * @param r
 */
void PQsort(Item a[], int l, int r) {
  int k;
  PQinit(r + 1);
  // 初始化优先队列
  for (k = l; k <= r; k++) {
    PQinsert(a[k]);
  }
  // 排序（每次都把最大的数取出来）
  for (k = r; k >= l; k--) {
    a[k] = PQdelmax();
  }
}

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("程序9.6：使用优先队列进行排序\n");
  int max = 8;
  int *a = malloc(max * sizeof(int));
  for (int i = 0; i < max; ++i) {
    a[i] = 1000 * (1.0 * rand() / RAND_MAX);
  }
  printArr("原数组：", a, max);
  PQsort(a, 0, max - 1);
  printArr("排序后：", a, max);
}
