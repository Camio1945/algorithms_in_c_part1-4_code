/** 程序5.9：画一把尺子的非递归程序 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * 标记刻度
 * @param m 位置
 * @param h 刻度的高度
 */
void mark(int m, int h) {
  printf("在位置为 %d 的地方的刻度高度为 %d\n", m, h);
}

/**
 * 画尺子（书中的方法）
 * @param l 左侧位置
 * @param r 右侧位置
 * @param h 高度
 * @return
 */
rule1(int l, int r, int h) {
  int i, j, t;
  for (t = 1, j = 1; t <= h; j += j, t++) {
    for (i = 0; l + j + i <= r; i += j + j) {
      mark(l + j + i, t);
    }
  }
}

/**
 * 画尺子（自定义的方法）
 * @param r 右侧位置
 * @param h 高度
 * @return
 */
rule2(int r, int h) {
  for (int level = 1; level <= h; ++level) {
    /* 规律：
     * 第1层的起始刻度为1(2的0次方)，任意两个刻度之间的间隔为2（2的1次方），刻度的总数量为 r/2
     * 第2层的起始刻度为2(2的1次方)，任意两个刻度之间的间隔为4（2的2次方），刻度的总数量为 r/4
     * 第3层的起始刻度为4(2的2次方)，任意两个刻度之间的间隔为8（2的3次方），刻度的总数量为 r/8
     * ...
     * 第n层的起始刻度为2的n-1次方，任意两个刻度之间的间隔为2的n次方，刻度的总数量为 r/2的n次方
     */
    int start = pow(2, level - 1); // 起始刻度
    int gap = pow(2, level); // 刻度间的间隔
    for (int position = start; position < r; position += gap) {
      mark(position, level);
    }
  }
}

main() {
  setbuf(stdout, NULL);
  rule1(0, 8, 3);
  printf("\n\n");
  rule2(8, 3);
}
