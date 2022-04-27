#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

/**
 * 获取随机数
 * @return
 */
Item ITEMrand(void) {
  return 1.0 * rand() / RAND_MAX;
}

/**
 * 从控制台输入一个Item数组（本例中是double类型的数组）
 * @param x
 * @return
 */
int ITEMscan(Item *x) {
  return scanf("%f", x);
}

/**
 * 显示Item
 * @param x
 */
void ITEMshow(Item x) {
  printf("%7.5f ", x);
}

