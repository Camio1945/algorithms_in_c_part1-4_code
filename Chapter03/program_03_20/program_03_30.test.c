#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Point.h"

typedef struct node *link;
struct node {
  point p;
  link next;
};
link **grid;
int G;
float d = 0.1;
int total = 0;
int cnt = 0;
const int N = 3200;
point *point_arr;

float randFloat() { return 1.0 * rand() / RAND_MAX; }

float distance(point a, point b) {
  float dx = a.x - b.x, dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

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

gridinsert(float x, float y) {
  int i, j;
  link s;
  // 下面的 X 和 Y 是为了确定该点(x,y)应该落入哪个网格中
  int X = x * G + 1;
  int Y = y * G + 1;
//  printf("%d %d\n", X, Y);
  link t = malloc(sizeof *t);
  t->p.x = x;
  t->p.y = y;
  for (i = X - 1; i <= X + 1; i++) {
    for (j = Y - 1; j <= Y + 1; j++) {
      for (s = grid[i][j]; s != NULL; s = s->next) {
        total++;
        if (distance(s->p, t->p) < d) {
          cnt++;
        }
      }
    }
  }
  t->next = grid[X][Y];
  grid[X][Y] = t;
}

/** 程序3.8版本 */
point program_03_08() {
  int i, j, cnt = 0;
  point *a = malloc(N * (sizeof(*a)));
  // for循环作用：初始化坐标点
  for (i = 0; i < N; i++) {
    a[i].x = point_arr[i].x;
    a[i].y = point_arr[i].y;
  }
  int total = 0;
  // for循环作用：计算点对的距离小于d的数量
  for (i = 0; i < N; i++) {
    for (j = i + 1; j < N; j++) {
      total++;
      if (distance(a[i], a[j]) < d) {
        cnt++;
      }
    }
  }
  point res = {total, cnt};
  return res;
}

/** 程序3.20版本 */
point program_03_20() {
  int i, j;
  G = 1 / d;
  grid = (link **) malloc2d(G + 2, G + 2);
  for (i = 0; i < G + 2; i++) {
    for (j = 0; j < G + 2; j++) {
      grid[i][j] = NULL;
    }
  }
  for (i = 0; i < N; i++) {
    gridinsert(point_arr[i].x, point_arr[i].y);
  }
  point res = {total, cnt};
  return res;
}

/**
 * 测试正确性
 */
void test_correctness() {
  printf("------------- 正确性测试 开始 -------------\n");
  point result_03_08 = program_03_08();
  point result_03_20 = program_03_20();
  if (result_03_08.x == result_03_20.x && result_03_08.y == result_03_20.y) {
    printf("正确性测试通过\n");
  } else {
    printf("正确性测试未通过！！！！！！！！！！！！！！！！！！！！！\n");
  }
  printf("------------- 正确性测试 结束-------------\n");
}

/** 测试性能 */
void test_performance() {

  printf("\n\n\n------------- 性能测试 - program_03_08 开始 -------------\n");
  clock_t start = clock();
  program_03_08();
  clock_t end = clock();

  printf("program_03_08程序耗时毫秒：%lf\n", (double) (end - start));
  printf("------------- 性能测试 - program_03_08 结束 -------------\n\n\n");

  printf("------------- 性能测试 - program_03_20 开始 -------------\n");
  start = clock();
  program_03_20();
  end = clock();
  printf("program_03_20程序耗时毫秒：%lf\n", (double) (end - start));
  printf("------------- 性能测试 - program_03_20 结束 -------------\n");
}

int main() {
  setbuf(stdout, NULL); // 将标准输出的缓存区清零，防止printf不及时打印
  srand((unsigned) time(NULL)); // 初始化随机数种子
  point_arr = malloc(N * sizeof(point));
  for (int i = 0; i < N; ++i) {
    point_arr[i].x = randFloat();
    point_arr[i].y = randFloat();
  }
  test_correctness(); // 测试正确性
  test_performance(); // 测试性能
  return 0;
}

