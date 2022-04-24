#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"

static char buf[100000];
static int cnt = 0;

/**
 * 获取随机数
 * @return
 */
int ITEMrand(void) {
  // 代码未实现
  return 0;
}

/**
 * 从控制台输入一个Item数组（本例中是double类型的数组）
 * @param x
 * @return
 */
int ITEMscan(char **x) {
  int t;
  *x = &buf[cnt];
  t = scanf("%s", *x);
  cnt += strlen(*x) + 1;
  return t;
}

/**
 * 显示Item
 * @param x
 */
void ITEMshow(char *x) {
  printf("%s ", x);
}

