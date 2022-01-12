#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARR_SIZE 10000000
#define VALUE_SIZE 200000

/**
 * 顺序查找
 * @param a 数组（本例是要求其中的数据是已经升序排序的）
 * @param v 要从数据中查找的值
 * @param l 从哪个下标开始查询，一般为0
 * @param r 到哪个下标为止结束查询，一般为数组的大小 - 1
 * @return 如果找到了，则返回下标，如果没找到，则返回-1
 */
int program_02_01(int a[], int v, int l, int r) {
  int i;
  for (i = l; i <= r; i++) {
    if (v == a[i]) {
      return i;
    }
  }
  return -1;
}

/**
 * 二分查找
 * @param a 数组（本例是要求其中的数据是已经升序排序的）
 * @param v 要从数据中查找的值
 * @param l 从哪个下标开始查询，一般为0
 * @param r 到哪个下标为止结束查询，一般为数组的大小 - 1
 * @return 如果找到了，则返回下标，如果没找到，则返回-1
 */
int program_02_02(int a[], int v, int l, int r) {
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


/** 初始化数组，数组中的值是升序排序的，返回指针 */
int *init_arr() {
  int *arr = malloc(sizeof(int) * ARR_SIZE);
  for (int i = 0; i < ARR_SIZE; ++i) {
    arr[i] = i;
  }
  return arr;
}

/** 初始化要查找的值用于比较的值，由于只测试一个值可能偏差比较大，这里初始化一个随机的数组 */
int *init_values() {
  int *value_arr = malloc(sizeof(int) * VALUE_SIZE);
  for (int i = 0; i < VALUE_SIZE; ++i) {
    value_arr[i] = rand() % ARR_SIZE;
  }
  return value_arr;
}


int main(void) {
  int *arr = init_arr();
  int *values = init_values();

  printf("------------- 性能测试 - program_02_01 开始 -------------\n");
  clock_t start = clock();
  for (int i = 0; i < VALUE_SIZE; ++i) {
    int v = values[i];
    program_02_01(arr, v, 0, ARR_SIZE - 1);
  }
  clock_t end = clock();
  printf("program_02_01 程序耗时毫秒：%lf\n", (double) (end - start));
  printf("------------- 性能测试 - program_02_01 结束 -------------\n\n\n");

  printf("------------- 性能测试 - program_02_02 开始 -------------\n");
  start = clock();
  for (int i = 0; i < VALUE_SIZE; ++i) {
    int v = values[i];
    program_02_02(arr, v, 0, ARR_SIZE - 1);
  }
  end = clock();
  printf("program_02_02 程序耗时毫秒：%lf\n", (double) (end - start));
  printf("------------- 性能测试 - program_02_02 结束 -------------\n\n\n");

}
