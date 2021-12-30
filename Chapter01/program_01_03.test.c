#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SMALL_SIZE_OF_PQ_ARR 12
#define LARGE_SIZE 100000

/**
 * ��ͨ�Ե�2��
 * @param id ԭ����
 * @param size_of_id  ԭ����Ĵ�С
 * @param pq_arr ��ֵ�����飨��ά���飩
 * @param size_of_pq_arr  ��ֵ�Ե��ܶ���������ά�����1ά�Ĵ�С
 * @param is_print_result �Ƿ��ӡ�����������ȷ��ʱ��1�������ڿ���̨�鿴����Ƿ���ȷ����������ʱ��0����Ϊ��ӡ�������ͺܺ�ʱ������Ӱ��ԭ��������ܣ�
 * @return
 */
int program_01_02(int *id, int size_of_id, int *pq_arr, int size_of_pq_arr, int is_print_result) {
  for (int j = 0; j < size_of_pq_arr; j++) {
    int p = pq_arr[j * 2];
    int q = pq_arr[j * 2 + 1];
    if (is_print_result) {
      printf("����֮ǰ������Ϊ��\t");
      for (int i = 0; i < size_of_id; i++) {
        printf("%d ", id[i]);
      }
    }
    int root_of_p, root_of_q;
    for (root_of_p = p; root_of_p != id[root_of_p]; root_of_p = id[root_of_p]);
    for (root_of_q = q; root_of_q != id[root_of_q]; root_of_q = id[root_of_q]);
    if (root_of_p == root_of_q) {
      if (is_print_result) {
        printf("\t��ͨ��%d %d\n", p, q);
      }
      continue;
    }
    id[root_of_p] = root_of_q;
    if (is_print_result) {
      printf("\t����ͨ��%d %d\n", p, q);
      printf("����֮�������Ϊ��\t");
      for (int i = 0; i < size_of_id; i++) {
        printf("%d ", id[i]);
      }
      printf("\n");
    }
  }
}

/**
 * ��ͨ�Ե�3��
 * @param id ԭ����
 * @param size_of_id  ԭ����Ĵ�С
 * @param pq_arr ��ֵ�����飨��ά���飩
 * @param size_of_pq_arr  ��ֵ�Ե��ܶ���������ά�����1ά�Ĵ�С
 * @param depth_arr  �ڵ���������
 * @param is_print_result �Ƿ��ӡ�����������ȷ��ʱ��1�������ڿ���̨�鿴����Ƿ���ȷ����������ʱ��0����Ϊ��ӡ�������ͺܺ�ʱ������Ӱ��ԭ��������ܣ�
 * @return
 */
int program_01_03(int *id, int size_of_id, int *pq_arr, int size_of_pq_arr, int *depth_arr, int is_print_result) {
  for (int j = 0; j < size_of_pq_arr; j++) {
    int p = pq_arr[j * 2];
    int q = pq_arr[j * 2 + 1];
    if (is_print_result) {
      printf("����֮ǰ������Ϊ��\t");
      for (int i = 0; i < size_of_id; i++) {
        printf("%d ", id[i]);
      }
    }
    int root_of_p, root_of_q;
    for (root_of_p = p; root_of_p != id[root_of_p]; root_of_p = id[root_of_p]);
    for (root_of_q = q; root_of_q != id[root_of_q]; root_of_q = id[root_of_q]);
    if (root_of_p == root_of_q) {
      if (is_print_result) {
        printf("\t��ͨ��%d %d\n", p, q);
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
      printf("\t����ͨ��%d %d\n", p, q);
      printf("����֮�������Ϊ��\t");
      for (int i = 0; i < size_of_id; i++) {
        printf("%d ", id[i]);
      }
      printf("\n");
    }
  }
}


/** ��ʼ��id�����飩������ָ�� */
int *init_id(int size) {
  int *id = malloc(sizeof(int) * size);
  for (int i = 0; i < size; ++i) {
    id[i] = i;
  }
  return id;
}

/** ��ʼ��������飬����ָ�� */
int *init_depth_arr(int size) {
  int *dept_arr = malloc(sizeof(int) * size);
  for (int i = 0; i < size; ++i) {
    // Ĭ�ϵ���ȶ���1
    dept_arr[i] = 1;
  }
  return dept_arr;
}

/** ���ݾ�ȷ����������ʼ��pq_arr */
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

/** ��ʼ�����ݶ����� */
int *init_pq_arr(size) {
  int *pq_arr = malloc(sizeof(int) * size * 2);
  // ������ݶԵĴ�С�ǽ�С���Ǹ�ֵ�������Ѿ�Լ�������ڲ�����ȷ�Եģ������ԭ����׼���õ����ݶԷ��ػ�ȥ
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
 * ������ȷ��
 * ˵�����������޷�ֱ�Ӳ�����ȷ�ԣ���Ҫ�˹��Աȴ�ӡ���
 */
void test_correctness() {
  int size_of_id = 10; // �ڵ�����Ĵ�С
  int *id = init_id(size_of_id);  // �ڵ�����
  int *pq_arr = init_pq_arr(SMALL_SIZE_OF_PQ_ARR); // p��q�����飬����ģ����������

  printf("------------- ��ȷ�Բ��� - program_01_02 ��ʼ -------------\n");
  program_01_02(id, size_of_id, pq_arr, SMALL_SIZE_OF_PQ_ARR, 1);
  printf("------------- ��ȷ�Բ��� - program_01_02 ���� -------------\n\n\n");


  printf("------------- ��ȷ�Բ��� - program_01_03 ��ʼ -------------\n");
  id = init_id(size_of_id);
  int *dept_arr = init_depth_arr(size_of_id);
  program_01_03(id, size_of_id, pq_arr, SMALL_SIZE_OF_PQ_ARR, dept_arr, 1);
  printf("------------- ��ȷ�Բ��� - program_01_03 ���� -------------\n");
}

/** �������� */
void test_performance() {
  int size_of_id = LARGE_SIZE; // �ڵ�����Ĵ�С
  int *id = init_id(size_of_id);  // �ڵ�����
  int *pq_arr = init_pq_arr(LARGE_SIZE); // p��q�����飬����ģ����������

  printf("\n\n\n------------- ���ܲ��� - program_01_02 ��ʼ -------------\n");
  clock_t start = clock();
  program_01_02(id, size_of_id, pq_arr, LARGE_SIZE, 0);
  clock_t end = clock();
  printf("program_01_02�����ʱ���룺%lf\n", (double) (end - start));
  printf("------------- ���ܲ��� - program_01_02 ���� -------------\n");

  printf("\n\n\n------------- ���ܲ��� - program_01_03 ��ʼ -------------\n");
  id = init_id(size_of_id);
  int *depth_arr = init_depth_arr(LARGE_SIZE);
  start = clock();
  program_01_03(id, size_of_id, pq_arr, LARGE_SIZE, depth_arr, 0);
  end = clock();

  printf("program_01_03�����ʱ���룺%lf\n", (double) (end - start));
  printf("------------- ���ܲ��� - program_01_03 ���� -------------\n\n\n");
}

int main() {
  setbuf(stdout, NULL); // ����׼����Ļ��������㣬��ֹprintf����ʱ��ӡ
  test_correctness(); // ������ȷ��
  test_performance(); // ��������
  return 0;
}

