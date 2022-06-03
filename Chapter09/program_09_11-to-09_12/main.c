/** 程序9.11~9.12：基于索引堆的优先队列 */
#include <stdio.h>
#include <stdlib.h>
#include "PQindex.c"

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("程序9.11~9.12：基于索引堆的优先队列\n");
  int N = 10;
  a = malloc(N * sizeof(Item));
  int i;
  for (i = 0; i < N; i++) {
    a[i] = rand() % 1000;
  }
  printf("　原数组: ");
  for (i = 0; i < N; i++) {
    printf("%d ", a[i]);
  }
  printf("\n创建队列");
  for (i = 0; i < N; i++) {
    PQinsert(i);
  }
  printf("\n倒序打印: ");
  while (!PQempty()) {
    printf("%d ", a[PQdelmax()]);
  }
  printf("\n");
}
