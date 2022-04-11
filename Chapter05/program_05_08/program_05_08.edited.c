/** 程序5.8：使用分治法在尺子上画刻度 */
#include <stdio.h>
#include <stdlib.h>

/**
 * 标记刻度
 * @param m 位置
 * @param h 刻度的高度
 */
void mark(int m, int h) {
  printf("在位置为 %d 的地方的刻度高度为 %d\n", m, h);
}

/**
 * 画尺子
 * @param l 左侧位置
 * @param r 右侧位置
 * @param h 高度
 * @return
 */
rule(int l, int r, int h) {
  int m = (l + r) / 2;
  if (h > 0) {
    rule(l, m, h - 1);
    mark(m, h);
    rule(m, r, h - 1);
  }
}

main() {
  setbuf(stdout, NULL);
  rule(0, 8, 3);
}
