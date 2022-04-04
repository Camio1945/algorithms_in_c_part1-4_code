/** 程序4.19：队列客户程序（队列模拟） */

#include <stdio.h>
#include "program_04_20.edited.c"

#define M 5

main() {
  int i, j, N = 10;
  Q queues[M];
  // for循环作用：初始化5个队列queues
  for (i = 0; i < M; ++i) {
    queues[i] = QUEUEinit(N);
  }
  // for循环作用：随机往5个队列中存入值，共10个值
  for (i = 0; i < N; ++i) {
    Q q = queues[rand() % M]; // 从5个队列中坠机取出一个队列
    QUEUEput(q, i);
  }
  // for循环作用：打印5个队列中存的值
  for (i = 0; i < M; ++i) {
    Q q = queues[i];
    while (!QUEUEempty(q)) {
      printf("%3d", QUEUEget(q));
    }
    printf("\n");
  }
}
