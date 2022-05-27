/** 程序9.5：基于堆的优先队列 */
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
void printArr(char *prefix, int *a) {
  printf("%s", prefix);
  for (int i = 1; i <= N; i++) {
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

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("程序9.5：基于堆的优先队列\n");
  PQinit(8);
  PQinsert(1);
  printArr("      原数组：", pq);
  PQinsert(3);
  printArr("      原数组：", pq);
  PQinsert(5);
  printArr("      原数组：", pq);
  PQinsert(4);
  printArr("      原数组：", pq);
  PQinsert(2);
  printArr("      原数组：", pq);
  PQinsert(8);
  printArr("      原数组：", pq);
  PQinsert(6);
  printArr("      原数组：", pq);
  PQinsert(7);
  printArr("      原数组：", pq);

  Item max = PQdelmax();
  printf("\n     del max：%d\n", max);
  printArr("删除8后的数组：", pq);

  max = PQdelmax();
  printf("\n     del max：%d\n", max);
  printArr("删除7后的数组：", pq);
}
