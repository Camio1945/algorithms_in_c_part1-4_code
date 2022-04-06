/** 程序5.6：使用分治法求最大值 */
#include <stdio.h>
#include <stdlib.h>

typedef int Item;

/**
 * 获取最大值
 * @param a 数组
 * @param l 从哪个下标开始
 * @param r 到哪个下标结束
 * @return
 */
Item max(Item a[], int l, int r) {
  if (l == r) {
    return a[l];
  }
  int m = (l + r) / 2;
  printf("l = %d, r = %d, m = %d\n", l, r, m);
  int lMax = max(a, l, m);
  int rMax = max(a, m + 1, r);
  if (lMax >= rMax) {
    return lMax;
  } else {
    return rMax;
  }
}

main() {
  setbuf(stdout, NULL);
  Item a[] = {0, 1, 2, 3, 40, 5, 6, 7, 8, 9, 10};
  printf("max : %d", max(a, 0, 10));
}
