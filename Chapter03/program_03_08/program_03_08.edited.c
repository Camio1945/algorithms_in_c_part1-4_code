#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Point.h"

float randFloat() { return 1.0 * rand() / RAND_MAX; }

float distance(point a, point b) {
  float dx = a.x - b.x, dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

main(int argc, char *argv[]) {
  setbuf(stdout, NULL); // 将标准输出的缓存区清零，防止printf不及时打印
  printf("本程序接收两个参数，第1个参数代表生成的点的个数(int类型)，第2个参数代表直线的长度(float类型)，如：32 0.5\n");
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  float d = atof(argv[2]);
  int i, j, cnt = 0, N = atoi(argv[1]);
  point *a = malloc(N * (sizeof(*a)));
  // for循环作用：初始化坐标点
  for (i = 0; i < N; i++) {
    a[i].x = randFloat();
    a[i].y = randFloat();
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
  printf("总的点对数为：%d\n", total);
  printf("%d edges shorter than %f\n", cnt, d);
  free(a);
}
