#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  setbuf(stdout, NULL); // 将标准输出的缓存区清零，防止printf不及时打印
  long int i, j, N = atoi(argv[1]);
  if (N <= 2) {
    printf("请输入大于2的参数N.\n");
    return -1;
  }
  int *a = malloc(N * sizeof(int));
  if (a == NULL) {
    printf("内存不足.\n");
    return -1;
  }
  // for循环作用：把所有的数字都默认标记为1（表明是素数）
  for (i = 2; i < N; i++) {
    a[i] = 1;
  }
  // for循环作用：如果一个值是两个数的乘积，则把这个下标标记为非素数
  for (i = 2; i < N; i++) {
    if (a[i]) {
      for (j = i; i * j < N; j++) {
        a[i * j] = 0;
      }
    }
  }
  // for循环作用：打印出所有的素数
  for (i = 2; i < N; i++) {
    if (a[i]) {
      printf("%4d ", i);
    }
  }
  free(a);
}
