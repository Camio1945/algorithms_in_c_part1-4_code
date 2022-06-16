/** 程序10.2：MSD基数排序 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

typedef int Item;

static int N;

/** 打印数组 */
void printArr(char *prefix, int *a, int size) {
  printf("%s", prefix);
  for (int i = 0; i < size; i++) {
    printf("%3d ", a[i]);
  }
  printf("\n");
}

#define bitsword 32
#define bitsbyte 8
#define bytesword 4
#define R (1 << bitsbyte)

//#define digit(A, B) (((A) >> (bitsword-((B)+1)*bitsbyte)) & (R-1))
//上面的digit宏相当于以下代码
int digit(int A, int B) {
  int rightMove = bitsword - ((B + 1) * bitsbyte);
  A = A >> rightMove;
  int res = A & (R - 1);
  printf("rightMove：%d，res：%d\n", rightMove, res);
  return res;
}

/**
 * 插入排序（程序6.3）
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
  for (i = l + 2; i <= r; i++) {
    int v = a[i];
    int j = i;
    while (less(v, a[j - 1])) {
      a[j] = a[j - 1];
      a[j - 1] = -1; // 本行代码为演示代码，表示a[j-1]的位置空出来了，可删除
      j--;
    }
    a[j] = v;
  }
}

#define bin(A) l+count[A]
#define M 4
#define maxN 50
Item aux[maxN];

/**
 * MSD（most significant digit最大有效位）基数排序
 * @param a 数组
 * @param l 左下标
 * @param r 右下标
 * @param w 正在被检查的位
 */
void radixMSD(Item a[], int l, int r, int w) {
  int i, j, count[R + 1];
  if (w > bytesword) {
    return;
  }
  if (r - l <= M) {
    insertion(a, l, r);
    return;
  }
  for (j = 0; j <= R; j++) {
    count[j] = 0;
  }
  for (i = l; i <= r; i++) {
    int digitRes = digit(a[i], w);
    count[digitRes + 1]++;
  }
  for (j = 1; j < R; j++) {
    count[j] += count[j - 1];
  }
  for (i = l; i <= r; i++) {
    int digitRes = digit(a[i], w);
    aux[count[digitRes]++] = a[i];
  }
  for (i = l; i <= r; i++) {
    a[i] = aux[i - l];
  }
  radixMSD(a, l, bin(0) - 1, w + 1);
  for (j = 0; j < R - 1; j++) {
    radixMSD(a, bin(j), bin(j + 1) - 1, w + 1);
  }
}

main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("程序10.2：MSD基数排序\n");
  int max = 50;
  int a[max];
  for (int i = 0; i < max; ++i) {
    a[i] = rand() % 100000000;
  }
  printArr("原数组：", a, max);
  radixMSD(a, 0, max - 1, 0);
  printArr("排序后：", a, max);
}
