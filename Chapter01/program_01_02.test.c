#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/** 常量N，表示数组的大小 */
#define N 5

int program_01_01(int *id, int *pq_arr, int is_print_result) {
  for (int j = 0; j < N * N - 1; ++j) {
    int p = pq_arr[j];
    int q = pq_arr[j + 1];
    if (is_print_result) {
      printf("处理之前的数组为：\t");
      for (int i = 0; i < N; i++) {
        printf("%d ", id[i]);
      }
    }
    if (id[p] == id[q]) {
      if (is_print_result) {
        printf("\t连通：%d %d\n", p, q);
      }
      continue;
    }
    // 【关键代码段】
    for (int t = id[p], i = 0; i < N; i++) {
      if (id[i] == t) {
        id[i] = id[q];
      }
    }
    if (is_print_result) {
      printf("\t不连通：%d %d\n", p, q);
      printf("处理之后的数组为：\t");
      for (int i = 0; i < N; i++) {
        printf("%d ", id[i]);
      }
      printf("\n");
    }
  }
}

int main() {
  setbuf(stdout, NULL);
  clock_t start = clock();
  // 数组，存放的是各个节点
  int *id = malloc(sizeof(int) * N);
  // p和q的数组，用于模拟输入数据
  int *pq_arr = malloc(N * N * 2);
  for (int i = 0; i < N; i++) {
    id[i] = i;
  }
  for (int i = 0; i < N * N; i+=2) {
    pq_arr[i] = rand() % N;
    pq_arr[i + 1] = rand() % N;
  }
  program_01_01(id, pq_arr, 0);
  clock_t end = clock();
  printf("程序耗时毫秒：%lf\n", (double) (end - start));
  free(id);
  free(pq_arr);
  return 0;
}

