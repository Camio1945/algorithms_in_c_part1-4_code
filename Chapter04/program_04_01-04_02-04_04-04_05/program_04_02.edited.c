#include <stdio.h>
#include <string.h>
#include "STACK_by_array.c"
//#include "STACK_by_linked_list.c"

main() {
  setbuf(stdout, NULL);
  char *a = "123 13 +"; // 123 + 13
//  char *a = "1 2 + 3 *"; // (1 + 2) * 3
//  char *a = "5 9 8 + 4 6 * * 7 + *"; // 5 * ((9 + 8) * (4 * 6) + 7)
  int i, N = strlen(a);
  STACKinit(N);
  // for循环作用：遍历后缀表达式中的每一个字符
  for (i = 0; i < N; i++) {
    // 执行加法
    if (a[i] == '+') {
      Item num1 = STACKpop();
      printf("出栈：%d\n", num1);
      Item num2 = STACKpop();
      printf("出栈：%d\n", num2);
      printf("入栈：%d + %d\n", num1, num2);
      STACKpush(num1 + num2);
    }
    // 执行乘法
    if (a[i] == '*') {
      Item num1 = STACKpop();
      printf("出栈：%d\n", num1);
      Item num2 = STACKpop();
      printf("出栈：%d\n", num2);
      printf("入栈：%d * %d\n", num1, num2);
      STACKpush(num1 * num2);
    }
    // if作用：如果是数字的话，往栈中存入一个0，方便后续在while循环中把字符串转成数字
    if ((a[i] >= '0') && (a[i] <= '9')) {
      printf("入栈：0\n");
      STACKpush(0);
    }
    // while循环作用：把字符串转成数字，比如把 "123" 转成数字 123，用于后续的计算
    while ((a[i] >= '0') && (a[i] <= '9')) {
      Item pop = STACKpop();
      printf("出栈：%d\n", pop);
      Item previous = 10 * pop;
      Item current = (a[i] - '0');
      Item total = previous + current;
      printf("入栈：%d\n", total);
      STACKpush(total);
      i++;
    }
  }
  Item res = STACKpop();
  printf("出栈：%d\n", res);
  printf("结果：%d \n", res);
}
