#include <stdio.h>

/** 常量N，表示数组的大小 */
#define N 10

/**
 * 连通问题（改进版3）：
 * <pre>
 *   本程序是 program_01_03.edited.c 程序的改进版，相关注释不再重复。
 *   两个版本都是用树来实现，合并时的算法是一样的，区别在于查找时的算法。
 *   1.3版本查找时，是一层一层往上找根节点。
 *   1.4版本查找时，是两层两层往上找根节点，因此速度快一些。
 * </pre>
 *
 * @return
 */
main() {
  setbuf(stdout, NULL); // 将标准输出的缓存区清零，防止printf不及时打印
  int i, p, q, root_of_p, root_of_q, id[N], depth_arr[N];
  for (i = 0; i < N; i++) {
    id[i] = i;
    depth_arr[i] = 1;
  }
  printf("请输入一对数字（10以内），两个数字中间以空格分隔：\n");
  while (scanf("%d %d", &p, &q) == 2) {
    printf("处理之前的数组为：\t");
    for (i = 0; i < N; i++) {
      printf("%d ", id[i]);
    }
    for (root_of_p = p; root_of_p != id[root_of_p]; root_of_p = id[root_of_p]) {
      id[root_of_p] = id[id[root_of_p]];
    }
    for (root_of_q = q; root_of_q != id[root_of_q]; root_of_q = id[root_of_q]) {
      id[root_of_q] = id[id[root_of_q]];
    }
    if (root_of_p == root_of_q) {
      printf("\t连通：%d %d\n", p, q);
      continue;
    }
    if (depth_arr[root_of_p] < depth_arr[root_of_q]) {
      id[root_of_p] = root_of_q;
      depth_arr[root_of_q] += depth_arr[root_of_p];
    } else {
      id[root_of_q] = root_of_p;
      depth_arr[root_of_p] += depth_arr[root_of_q];
    }
    printf("\t不连通：%d %d\n", p, q);
    printf("处理之后的数组为：\t");
    for (i = 0; i < N; i++) {
      printf("%d ", id[i]);
    }
    printf("\n");
  }
}

