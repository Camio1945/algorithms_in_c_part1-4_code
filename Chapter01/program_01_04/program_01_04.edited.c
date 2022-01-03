#include <stdio.h>

/** 常量N，表示数组的大小 */
#define N 10

/**
 * 连通问题（改进版3）：
 * <pre>
 *   本程序是 program_01_03.edited.c 程序的改进版，相关注释不再重复。
 *   1.3版本里，如果两个节点已经连通，则不做处理。
 *   1.4版本里，如果两个节点已经连通，还是会做处理，把树的深度变小，这样往上找根节点时要查找的次数就少了。
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
    // 【关键代码段】以下的两个for循环是针对上一版的改进点
    for (root_of_p = p; root_of_p != id[root_of_p]; root_of_p = id[root_of_p]) {
      id[root_of_p] = id[id[root_of_p]];
    }
    for (root_of_q = q; root_of_q != id[root_of_q]; root_of_q = id[root_of_q]) {
      id[root_of_q] = id[id[root_of_q]];
    }
    if (root_of_p == root_of_q) {
      printf("\t连通：%d %d\n", p, q);
      printf("处理之后的数组为：\t");
      for (i = 0; i < N; i++) {
        printf("%d ", id[i]);
      }
      printf("\n");
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

