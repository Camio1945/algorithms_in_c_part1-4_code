#include <stdio.h>

/**
 * 二分查找
 * @param a 数组（本例是要求其中的数据是已经升序排序的）
 * @param v 要从数据中查找的值
 * @param l 从哪个下标开始查询，一般为0
 * @param r 到哪个下标为止结束查询，一般为数组的大小 - 1
 * @return 如果找到了，则返回下标，如果没找到，则返回-1
 */
int search(int a[], int v, int l, int r) {
  while (r >= l) {
    int m = (l + r) / 2;
    if (v == a[m]) {
      return m;
    }
    if (v < a[m]) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return -1;
}

main() {
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int res = search(a, 5, 0, 9);
  printf("%d\n", res);
}
