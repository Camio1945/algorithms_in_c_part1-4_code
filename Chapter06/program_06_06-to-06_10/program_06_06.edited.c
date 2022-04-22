/** 程序6.6：数组的排序驱动程序 */
#include "Array.c"

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  printf("数组的排序驱动程序\n");
  int N = 10;
  Item *a = malloc(N * sizeof(Item));
  randinit(a, N);
  sort(a, 0, N - 1);
  show(a, 0, N - 1);
}
