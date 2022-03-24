/** 以数组的方式实现栈 */
#include "STACK.h"
#include <stdlib.h>

Item *a;
int currentIndex;

/** 初始化栈 */
void STACKinit(int maxN) {
  a = malloc(maxN * sizeof(Item));
  currentIndex = 0;
}

/** 入栈 */
void STACKpush(Item value) {
  a[currentIndex] = value;
  currentIndex++;
}

/** 判断栈是否为空 */
int STACKempty() {
  return currentIndex == 0;
}

/** 出栈 */
Item STACKpop() {
  currentIndex--;
  return a[currentIndex];
}


