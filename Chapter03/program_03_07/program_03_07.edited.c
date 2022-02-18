#include <stdio.h>
#include <stdlib.h>

/** heads代表正面朝上 */
int heads() {
  return rand() < RAND_MAX / 2;
}

main(int argc, char *argv[]) {
  setbuf(stdout, NULL); // 将标准输出的缓存区清零，防止printf不及时打印
  printf("本程序接收两个整型参数，第1个参数代表每次实验中抛硬币的次数，第2个参数代表执行多少次实验，如：32 1000\n");
  int i, j, cnt;
  // N代表每次实验中抛硬币的次数，M代表执行多少次实验
  int N = atoi(argv[1]), M = atoi(argv[2]);
  if (N <= 2 || M <= 2) {
    printf("请输入大于2的参数N和M.\n");
    return -1;
  }
  // f代表频率数组，比如 f[3] 表示在M次实验中每次抛N次硬币恰好3次正面朝上的实验次数
  int *f = malloc((N + 1) * sizeof(int));
  // for循环作用：初始化f数组
  for (j = 0; j <= N; j++) {
    f[j] = 0;
  }
  // for循环作用：执行实验
  for (i = 0; i < M; i++, f[cnt]++) {
    for (cnt = 0, j = 0; j <= N; j++) {
      if (heads()) {
        cnt++;
      }
    }
  }
  // for循环作用：打印结果
  for (j = 0; j <= N; j++) {
    printf("%2d ", j);
    for (i = 0; i < f[j]; i += 10) {
      printf("*");
    }
    printf("\n");
  }
  free(f);
}
