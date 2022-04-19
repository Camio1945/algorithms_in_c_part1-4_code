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
float d;
int total = 0;
int cnt = 0;

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

main(int argc, char *argv[]) {
  setbuf(stdout, NULL); // 将标准输出的缓存区清零，防止printf不及时打印
  printf("本程序接收两个参数，第1个参数代表生成的点的个数(int类型)，第2个参数代表直线的长度(float类型)，如：32 0.5\n");
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  int i, j, N = atoi(argv[1]);
  d = atof(argv[2]);
  G = 1 / d;
  grid = (link **) malloc2d(G + 2, G + 2);
  for (i = 0; i < G + 2; i++) {
    for (j = 0; j < G + 2; j++) {
      grid[i][j] = NULL;
    }
  }
  for (i = 0; i < N; i++) {
    gridinsert(randFloat(), randFloat());
  }
  printf("总的点对数为：%d\n", total);
  printf("%d edges shorter than %f\n", cnt, d);
  /*
   * 规律：
   * grid[1][1]：x < 0.5 且 y < 0.5
   * grid[1][2]：x < 0.5 且 y > 0.5
   * grid[2][1]：x > 0.5 且 y < 0.5
   * grid[2][2]：x > 0.5 且 y > 0.5
   *
   */
}

