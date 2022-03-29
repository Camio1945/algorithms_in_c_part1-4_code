#include <stdio.h>
#include <string.h>
#include "UF.c"

#define SIZE 12

/** 根据精确的数据来初始化pq_arr */
void init_pq_arr_by_precise_data(int *pq_arr) {
  int precise_arr[SIZE][2] = {
      {3, 4},
      {4, 9},
      {8, 0},
      {2, 3},
      {5, 6},
      {2, 9},
      {5, 9},
      {7, 3},
      {4, 8},
      {5, 6},
      {0, 2},
      {6, 1}
  };
  for (int i = 0; i < SIZE; i++) {
    pq_arr[i * 2] = precise_arr[i][0];
    pq_arr[i * 2 + 1] = precise_arr[i][1];
  }
}

main() {
  int *pq_arr = malloc(sizeof(int) * SIZE * 2); // 定义指针
  init_pq_arr_by_precise_data(pq_arr); // 初始化数组
  UFinit(SIZE); // 初始化默认的连通情况与节点深度
  for (int i = 0; i < SIZE; ++i) {
    int p = pq_arr[i * 2];
    int q = pq_arr[i * 2] + 1;
    if (UFfind(p, q)) {
      printf("连通：%d %d\n", p, q);
    } else {
      UFunion(p, q);
      printf("不连通：%d %d\n", p, q);
    }
  }
}
