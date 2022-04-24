/** 程序6.11：字符串元素的数据类型实现 */
#include "Array.c"

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  printf("字符串元素的数据类型实现\n");
  printf("本程序需要在控制台输入多个字符串（回车键分隔），用于对这些字符串排序，如：\nthis\nis\na\nbasic\ntest\n");
  printf("提示：控制台输入完成后，按回车，然后按快捷键：Ctrl + D （也可能是Ctrl + C 或 Ctrl + Z，不同平台不一样，多试试）\n");
  int N = 10;
  Item *a = malloc(N * sizeof(Item));
  scaninit(a, &N);
  sort(a, 0, N - 1);
  show(a, 0, N - 1);
}
