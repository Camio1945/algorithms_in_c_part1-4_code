/** 程序6.3：插入排序 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N = 10;

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

/** 打印数组 */
void printArr(char *prefix, int *a) {
  printf("%s", prefix);
  for (int i = 0; i < N; i++) {
    printf("%3d ", a[i]);
  }
  printf("\n");
}

/**
 * 插入排序
 * @param a 数组
 * @param l 左下标
 * @param r 右下标
 */
void insertion(Item a[], int l, int r) {
  int i;
  // for循环的作用，把数组中最小的那个数排到最前面
  for (i = r; i > l; i--) {
    compexch(a[i - 1], a[i])
  }
  printArr("", a);
  for (i = l + 2; i <= r; i++) {
    int v = a[i];
    int j = i;
    printf("i = %d：\n", i);
    while (less(v, a[j - 1])) {
      a[j] = a[j - 1];
      a[j - 1] = -1; // 本行代码为演示代码，表示a[j-1]的位置空出来了，可删除
      printArr("", a);
      j--;
    }
    a[j] = v;
    printArr("", a);
  }
}

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  printf("插入排序\n");
  int *a = malloc(N * sizeof(int));
  for (int i = 0; i < N; ++i) {
    a[i] = 1000 * (1.0 * rand() / RAND_MAX);
  }
  printArr("原数组：", a);
  insertion(a, 0, N - 1);
  printArr("排序后的数组：", a);
  printf("\n\n");

}
