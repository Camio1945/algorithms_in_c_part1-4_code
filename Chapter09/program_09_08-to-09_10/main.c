/** 程序9.8~9.10：双链表优先队列 */
#include <stdio.h>
#include <stdlib.h>
#include "PQfull.c"

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("程序9.8~9.10：双链表优先队列\n");
  int N, M, i;
  Item x;
  PQ q1, q2;
  N = 5; // 第1个队列的大小
  M = 7; // 第2个队列的大小
  q1 = PQinit();
  q2 = PQinit();
  printf("第1个队列: ");
  for (i = 0; i < N; i++) {
    x = rand() % 1000;
    printf("%d ", x);
    PQinsert(q1, x);
  }
  printf("\n第2个队列: ");
  for (i = 0; i < M; i++) {
    x = rand() % 1000;
    printf("%d ", x);
    PQinsert(q2, x);
  }
  printf("\n 合并队列: ");
  PQjoin(q1, q2);
  while (!PQempty(q1)) {
    printf("%d ", PQdelmax(q1));
  }
  printf("\n");
}
