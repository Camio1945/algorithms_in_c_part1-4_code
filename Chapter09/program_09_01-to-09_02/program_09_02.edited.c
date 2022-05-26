/** 程序9.2： */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PQ.h"

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }

static Item *pq;
static int N;

void PQinit(int maxN) {
  pq = malloc(maxN * sizeof(Item));
  N = 0;
}

int PQempty() { return N == 0; }

void PQinsert(Item v) { pq[N++] = v; }

Item PQdelmax() {
  int j, max = 0;
  // for循环作用：找出数组pq中值最大的那个数的下标
  for (j = 1; j < N; j++) {
    if (less(pq[max], pq[j])) {
      max = j;
    }
  }
  // 把最大的那个数交换到队列的尾部
  exch(pq[max], pq[N - 1]);
  return pq[--N];
}

/** 打印数组 */
void printArr(char *prefix, int *a) {
  printf("%s", prefix);
  for (int i = 0; i < N; i++) {
    printf("%3d ", a[i]);
  }
  printf("\n");
}

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("程序9.2：优先队列数组实现\n");
  PQinit(5);
  PQinsert(1);
  PQinsert(3);
  PQinsert(5);
  PQinsert(4);
  PQinsert(2);
  printArr("      原数组：", pq);

  Item max = PQdelmax();
  printf("\n     del max：%d\n", max);
  printArr("删除5后的数组：", pq);

  max = PQdelmax();
  printf("\n     del max：%d\n", max);
  printArr("删除4后的数组：", pq);

}
