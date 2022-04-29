/** 程序6.17：关键字索引统计 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 4
#define N 15

/** 打印数组 */
void printArr(char *prefix, int *a) {
  printf("%s", prefix);
  for (int i = 0; i < N; i++) {
    printf("%3d ", a[i]);
  }
  printf("\n");
}

/** 打印cnt */
void printCnt(char *prefix, int *a) {
  printf("%s", prefix);
  for (int i = 0; i < M + 1; i++) {
    printf("%3d ", a[i]);
  }
  printf("\n");
}

void distcount(int a[], int l, int r) {
  int i, j, cnt[M + 1], b[N];
  // cnt数组整体赋值为0
  for (j = 0; j < M + 1; j++) {
    cnt[j] = 0;
  }
  // 这个for循环执行完后，cnt[n]代表的是：在数组a中，数字 n-1 出现的次数，比如 cnt[2] 表示在数组a中数字1出现的次数
  for (i = l; i <= r; i++) {
    // 0 <= a[i] <= 3
    // 1 <= a[i] + 1 <= 4
    // cnt[1]++、cnt[2]++、cnt[3]++、cnt[4]++
    cnt[a[i] + 1]++;
  }
  printCnt("cnt：", cnt);
  // 这个for循环执行完后，cnt[n]代表的是：数组a中，值小于或等于 n-1 的总数量，
  for (j = 1; j < M + 1; j++) {
    cnt[j] += cnt[j - 1];
  }
  printCnt("cnt：", cnt);
  // 这个for循环执行完后，数组b中的值都是排好序的了
  for (i = l; i <= r; i++) {
    printf("       i = %2d, a[i] = %d, cnt[a[i]] = %2d，即b[%2d]=%2d\n", i, a[i], cnt[a[i]], cnt[a[i]], a[i]);
    b[cnt[a[i]]] = a[i];
    cnt[a[i]]++;
  }
  printCnt("cnt：", cnt);
  // 把数组b中的值依次赋值给数组a
  for (i = l; i <= r; i++) {
    a[i] = b[i - l];
  }
}

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  printf("关键字索引统计\n");
  int i;
  int *a = malloc(sizeof(int) * N);
  for (i = 0; i < N; i++) {
    a[i] = rand() % M;
  }
  printArr("原数组", a);
  distcount(a, 0, N - 1);
  printArr("排序后", a);
}
