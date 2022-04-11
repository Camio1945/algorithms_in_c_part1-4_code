/** 程序5.10：斐波纳契数（递归实现） */
#include <stdio.h>
#include <stdlib.h>

/** 调用第1个方法的次数 */
int count1 = 0;

/** 调用第2个方法的次数 */
int count2 = 0;

/**
 * 递归计算斐波纳契数。这种做法不推荐，因为效率太低了，会重复计算。
 * 推荐的算法见F2
 * @param i 计算该数的斐波纳契数
 * @return
 */
int F(int i) {
  count1++;
  if (i < 1) {
    return 0;
  }
  if (i == 1) {
    return 1;
  }
  return F(i - 1) + F(i - 2);
}


/**
 * 非递归计算斐波纳契数。推荐的算法。
 *
 * @param arr 数组
 * @param i 计算该数的斐波纳契数
 * @return
 */
int F2(int *arr, int i) {
  count2++;
  if (i < 1) {
    return 0;
  }
  if (i == 1) {
    return 1;
  }
  return arr[i - 1] + arr[i - 2];
}

main() {
  setbuf(stdout, NULL);
  printf("第一种方法斐波纳契数列为：\n");
  for (int i = 0; i < 10; ++i) {
    printf("%d ", F(i));
  }
  printf("\n第一种方法调用次数：%d\n", count1);

  printf("\n\n第二种方法斐波纳契数列为：\n");
  int *arr = malloc(sizeof(int) * 10);
  for (int i = 0; i < 10; ++i) {
    arr[i] = F2(arr, i);
    printf("%d ", arr[i]);
  }
  printf("\n第二种方法调用次数：%d\n", count2);
}
