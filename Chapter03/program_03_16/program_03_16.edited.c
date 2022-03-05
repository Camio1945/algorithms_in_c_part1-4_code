#include <stdio.h>
#include <stdlib.h>

/**
 * 分配二维数组（这里的 d 代表 dimension (维度)）
 * @param row 行数
 * @param col 列数
 * @return
 */
int **malloc2d(int row, int col) {
  int i;
  int **t = malloc(row * sizeof(int *));
  for (i = 0; i < row; i++) {
    t[i] = malloc(col * sizeof(int));
  }
  return t;
}

int main() {
  int row = 2, col = 3;
  int **arr2d = malloc2d(row, col);
  int number = 1;
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      arr2d[i][j] = number;
      number++;
    }
  }
  printf("arr2d[0][2] : %d\n", arr2d[0][2]);
  return 0;
}
