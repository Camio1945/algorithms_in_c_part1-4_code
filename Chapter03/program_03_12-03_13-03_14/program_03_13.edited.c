#include "stdio.h"
#include "program_03_14.edited.c"

main(int argc, char *argv[]) {
  setbuf(stdout, NULL); // 将标准输出的缓存区清零，防止printf不及时打印
  printf("本程序接收两个参数，第1个参数代表圈中的人数(int类型)，第2个参数代表数到几之后出圈(int类型)，如：9 5\n");
  int i, N = atoi(argv[1]), M = atoi(argv[2]);
  Node t, x;
  initNodes(N); // 初始化freelist链表
  // for循环的作用：初始化x链表
  for (i = 2, x = newNode(1); i <= N; i++) {
    t = newNode(i);
    insertNext(x, t);
    x = t;
  }
  // while循环的作用：轮流报数出局、选出领导人
  while (x != Next(x)) {
    // for循环的作用，报数，直到M之前
    for (i = 1; i < M; i++) {
      x = Next(x);
    }
    // 删除下一个节点，并把删除的节点放回freelist中
    freeNode(deleteNext(x));
  }
  printf("最后选出来的领导人是：%d\n", Item(x));
}
