#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SMALL_SIZE_OF_PQ_ARR 12
#define ARR_SIZE 10000000

/**
 * 连通性第3版
 * @param id 原数组
 * @param size_of_id  原数组的大小
 * @param pq_arr 数值对数组（二维数组）
 * @param size_of_pq_arr  数值对的总对数，即二维数组第1维的大小
 * @param depth_arr  节点的深度数组
 * @param is_print_result 是否打印结果（测试正确性时传1，方便在控制台查看结果是否正确；测试性能时传0，因为打印结果本身就很耗时，它会影响原程序的性能）
 * @return
 */
int program_01_03(int *id, int size_of_id, int *pq_arr, int size_of_pq_arr, int *depth_arr, int is_print_result) {
  for (int j = 0; j < size_of_pq_arr; j++) {
    int p = pq_arr[j * 2];
    int q = pq_arr[j * 2 + 1];
    if (is_print_result) {
      printf("处理之前的数组为：\t");
      for (int i = 0; i < size_of_id; i++) {
        printf("%d ", id[i]);
      }
    }
    int root_of_p, root_of_q;
    for (root_of_p = p; root_of_p != id[root_of_p]; root_of_p = id[root_of_p]);
    for (root_of_q = q; root_of_q != id[root_of_q]; root_of_q = id[root_of_q]);
    if (root_of_p == root_of_q) {
      if (is_print_result) {
        printf("\t连通：%d %d\n", p, q);
      }
      continue;
    }
    if (depth_arr[root_of_p] < depth_arr[root_of_q]) {
      id[root_of_p] = root_of_q;
      depth_arr[root_of_q] += depth_arr[root_of_p];
    } else {
      id[root_of_q] = root_of_p;
      depth_arr[root_of_p] += depth_arr[root_of_q];
    }
    if (is_print_result) {
      printf("\t不连通：%d %d\n", p, q);
      printf("处理之后的数组为：\t");
      for (int i = 0; i < size_of_id; i++) {
        printf("%d ", id[i]);
      }
      printf("\n");
    }
  }
}

/**
 * 连通性第4版
 * @param id 原数组
 * @param size_of_id  原数组的大小
 * @param pq_arr 数值对数组（二维数组）
 * @param size_of_pq_arr  数值对的总对数，即二维数组第1维的大小
 * @param depth_arr  节点的深度数组
 * @param is_print_result 是否打印结果（测试正确性时传1，方便在控制台查看结果是否正确；测试性能时传0，因为打印结果本身就很耗时，它会影响原程序的性能）
 * @return
 */
int program_01_04(int *id, int size_of_id, int *pq_arr, int size_of_pq_arr, int *depth_arr, int is_print_result) {
  for (int j = 0; j < size_of_pq_arr; j++) {
    int p = pq_arr[j * 2];
    int q = pq_arr[j * 2 + 1];
    if (is_print_result) {
      printf("处理之前的数组为：\t");
      for (int i = 0; i < size_of_id; i++) {
        printf("%d ", id[i]);
      }
    }
    int root_of_p, root_of_q;
    for (root_of_p = p; root_of_p != id[root_of_p]; root_of_p = id[root_of_p]) {
      id[root_of_p] = id[id[root_of_p]];
    }
    for (root_of_q = q; root_of_q != id[root_of_q]; root_of_q = id[root_of_q]) {
      id[root_of_q] = id[id[root_of_q]];
    }
    if (root_of_p == root_of_q) {
      if (is_print_result) {
        printf("\t连通：%d %d\n", p, q);
      }
      continue;
    }
    if (depth_arr[root_of_p] < depth_arr[root_of_q]) {
      id[root_of_p] = root_of_q;
      depth_arr[root_of_q] += depth_arr[root_of_p];
    } else {
      id[root_of_q] = root_of_p;
      depth_arr[root_of_p] += depth_arr[root_of_q];
    }
    if (is_print_result) {
      printf("\t不连通：%d %d\n", p, q);
      printf("处理之后的数组为：\t");
      for (int i = 0; i < size_of_id; i++) {
        printf("%d ", id[i]);
      }
      printf("\n");
    }
  }
}


/** 初始化id（数组），返回指针 */
int *init_id(int size) {
  int *id = malloc(sizeof(int) * size);
  for (int i = 0; i < size; ++i) {
    id[i] = i;
  }
  return id;
}

/** 初始化深度数组，返回指针 */
int *init_depth_arr(int size) {
  int *dept_arr = malloc(sizeof(int) * size);
  for (int i = 0; i < size; ++i) {
    // 默认的深度都是1
    dept_arr[i] = 1;
  }
  return dept_arr;
}

/** 根据精确的数据来初始化pq_arr */
void init_pq_arr_by_precise_data(int *pq_arr) {
  int precise_arr[SMALL_SIZE_OF_PQ_ARR][2] = {
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
  for (int i = 0; i < SMALL_SIZE_OF_PQ_ARR; i++) {
    pq_arr[i * 2] = precise_arr[i][0];
    pq_arr[i * 2 + 1] = precise_arr[i][1];
  }
}

/** 初始化数据对数组 */
int *init_pq_arr(int size) {
  int *pq_arr = malloc(sizeof(int) * size * 2);
  // 如果数据对的大小是较小的那个值（我们已经约定是用于测试正确性的），则把原书上准备好的数据对返回回去
  if (size == SMALL_SIZE_OF_PQ_ARR) {
    init_pq_arr_by_precise_data(pq_arr);
  } else {
    for (int i = 0; i <= size - 2; i += 2) {
      pq_arr[i] = rand() % size;
      pq_arr[i + 1] = rand() % size;
    }
  }
  return pq_arr;
}

/**
 * 测试正确性
 * 说明：本程序无法直接测试正确性，需要人工对比打印结果
 */
void test_correctness() {
  int size_of_id = 10; // 节点数组的大小
  int *id = init_id(size_of_id);  // 节点数组
  int *pq_arr = init_pq_arr(SMALL_SIZE_OF_PQ_ARR); // p和q的数组，用于模拟输入数据
  int *dept_arr = init_depth_arr(size_of_id);

  printf("------------- 正确性测试 - program_01_03 开始 -------------\n");
  program_01_03(id, size_of_id, pq_arr, SMALL_SIZE_OF_PQ_ARR, dept_arr, 1);
  printf("------------- 正确性测试 - program_01_03 结束 -------------\n\n\n");


  printf("------------- 正确性测试 - program_01_04 开始 -------------\n");
  id = init_id(size_of_id);
  dept_arr = init_depth_arr(size_of_id);
  program_01_04(id, size_of_id, pq_arr, SMALL_SIZE_OF_PQ_ARR, dept_arr, 1);
  printf("------------- 正确性测试 - program_01_04 结束 -------------\n");
}

/** 测试性能 */
void test_performance() {
  int size_of_id = ARR_SIZE; // 节点数组的大小
  int *id = init_id(size_of_id);  // 节点数组
  int *pq_arr = init_pq_arr(ARR_SIZE); // p和q的数组，用于模拟输入数据

  printf("\n\n\n------------- 性能测试 - program_01_03 开始 -------------\n");
  int *depth_arr = init_depth_arr(ARR_SIZE);
  clock_t start = clock();
  program_01_03(id, size_of_id, pq_arr, ARR_SIZE, depth_arr, 0);
  clock_t end = clock();
  printf("program_01_03程序耗时毫秒：%lf\n", (double) (end - start));
  printf("------------- 性能测试 - program_01_03 结束 -------------\n");

  printf("\n\n\n------------- 性能测试 - program_01_04 开始 -------------\n");
  id = init_id(size_of_id);
  depth_arr = init_depth_arr(ARR_SIZE);
  start = clock();
  program_01_04(id, size_of_id, pq_arr, ARR_SIZE, depth_arr, 0);
  end = clock();

  printf("program_01_04程序耗时毫秒：%lf\n", (double) (end - start));
  printf("------------- 性能测试 - program_01_04 结束 -------------\n\n\n");
}

int main() {
  setbuf(stdout, NULL); // 将标准输出的缓存区清零，防止printf不及时打印
  test_correctness(); // 测试正确性
  test_performance(); // 测试性能
  return 0;
}

