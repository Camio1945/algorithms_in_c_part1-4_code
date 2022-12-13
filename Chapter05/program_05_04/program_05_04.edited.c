/** 程序5.4：前缀表达式求值的递归程序 */
#include <stdio.h>

//char *a = "* + 7 * * 4 6 + 8 9 5";
//char *a = "- 3 / 2 * 4 + 2 3"; // 带减法和除法的示例
char *a = "* 4 + 2 3";
int i = 0;

/** 前缀表达式求值 */
int eval() {
  while (a[i] == ' ') {
    i++;
  }
  if (a[i] == '+') {
    i++;
    return eval() + eval();
  }
  if (a[i] == '-') {
    i++;
    int x = eval();
    int y = eval();
    return y - x;
  }
  if (a[i] == '*') {
    i++;
    return eval() * eval();
  }
  if (a[i] == '/') {
    i++;
    int x = eval();
    int y = eval();
    return y / x;
  }
  int x = 0;
  while (a[i] >= '0' && a[i] <= '9') {
    x = 10 * x + (a[i] - '0');
    i++;
  }
  return x;
}


main() {
  setbuf(stdout, NULL);
  printf("前缀表达式为：%s\n", a);
  printf("前缀表达式的值为：%d", eval());
}
