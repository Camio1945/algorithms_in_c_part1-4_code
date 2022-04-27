#include "Array.c"
#include <time.h>

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  printf("链表选择排序\n");
  int N = 5;
  link h = init(N);
  printf("排序前：");
  show(h);
  printf("\n");
  sort(h);
  printf("排序后：");
  show(h);
}
