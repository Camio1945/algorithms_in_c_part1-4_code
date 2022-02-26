#include <stdio.h>

#define N 10000

main(int argc, char *argv[]) {
  setbuf(stdout, NULL); // 将标准输出的缓存区清零，防止printf不及时打印
  printf("本程序接收一个参数，第1个参数代表要查找的关键字(string类型)，如：hello\n");
  printf("同时本程序需要在控制台输入一段字符串，用于从这段字符串中查找关键字，如：helloworldhelloworld\n");
  printf("提示：控制台输入完成后，按回车，然后按快捷键：Ctrl + D （也可能是Ctrl + C 或 Ctrl + Z，不同平台不一样，多试试）\n");
  int i, j, temp_char;
  char long_str[N], *keyword = argv[1];
  // for循环作用：从控制台接收一段字符串，从这段字符串中查找关键字
  for (i = 0; i < N - 1; long_str[i] = temp_char, i++) {
    if ((temp_char = getchar()) == EOF) {
      break;
    }
  }
  long_str[i] = 0;
  // for循环作用：遍历长字符串中的每一个字符
  for (i = 0; long_str[i] != 0; i++) {
    // for循环作用：遍历关键字中的每一个字符，跟长字符串中的相应位置的字符做比较
    for (j = 0; keyword[j] != 0; j++) {
      if (long_str[i + j] != keyword[j]) {
        break;
      }
    }
    // 当keyword[j]为0时，表示keyword中的每一个字符都跟long_str中相应位置的字符对应上了，则说明该串在该位置存在
    if (keyword[j] == 0) {
      printf("%d ", i);
    }
  }
  printf("\n");
}
