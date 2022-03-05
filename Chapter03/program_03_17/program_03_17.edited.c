#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define Nmax 1000
#define Mmax 10000

/** 代表一个长长的字符串 */
char buf[Mmax];
int M = 0;

/**
 * 比较字符串
 * @param i 第1个字符串
 * @param j 第2个字符串
 * @return
 */
int compare(const void *i, const void *j) {
  // 注意这里的写法，不是 (char *)i ，而是 *(char **)i
  return strcmp(*(char **) i, *(char **) j);
}

main() {
  setbuf(stdout, NULL); // 将标准输出的缓存区清零，防止printf不及时打印
  printf("同时本程序需要在控制台输入一些英文单词，用于排序，如：now is the time for all\n");
  printf("提示：控制台输入完成后，按回车，然后按快捷键：Ctrl + D （也可能是Ctrl + C 或 Ctrl + Z，不同平台不一样，多试试）\n");
  int i, N;
  char *arr[Nmax]; // 指针数组
  // for循环作用：从控制台获取字符串
  for (N = 0; N < Nmax; N++) {
    // arr[N]是一个指针
    arr[N] = &buf[M];
    if (scanf("%s", arr[N]) == EOF) {
      break;
    }
    // 注意后面要加1，为了给字符串增加一个结束符
    M += strlen(arr[N]) + 1;
  }
  // 快速排序
  qsort(arr, N, sizeof(char *), compare);
  // for循环作用：打印结果
  for (i = 0; i < N; i++) {
    printf("%s\n", arr[i]);
  }
}
