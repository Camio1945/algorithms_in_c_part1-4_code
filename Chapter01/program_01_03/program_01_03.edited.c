#include <stdio.h>

/** 常量N，表示数组的大小 */
#define N 10

/**
 * 连通问题（改进版2）：
 * <pre>
 *   本程序是 program_01_02.edited.c 程序的改进版，相关注释不再重复。
 *   看这里：https://blog.csdn.net/blueskybluesoul/article/details/122180163
 *   在这一版本中，树型结构有了变化：
 *      假设有一个一维数组a，大小为10，a[0]到a[9]中存的值分别为0~9，即每个元素的值都不一样，每个节点都是根节点。
 *      程序认为，当a[i]和a[j]的根节点不一样时，i和j不连通，根节点一样时，i和j连通。
 *      以a[1]到a[2]为例，程序初始值如下：
 *          a[1] a[2] a[3]
 *          1    2    3
 *      输入`1 2`后，a[2]的值改成了1，注意这里的1指的是下标为1，根据a[1]里面的值找到对应下标中的值，
 *                                此时a[2]不再是根节点，而是a[1]的子节点，a[1]和a[2]拥有相同的根节点a[1]，所以a[1]和a[2]是连通的：
 *          a[1] a[2] a[3]
 *          1    1    3
 *      输入`2 3`后，a[3]的值变成了1，此时a[3]不再是根节点，而是a[1]的子节点，此时3个节点都连通了，a[2]和a[3]都是a[1]的子节点：
 *          a[1] a[2] a[3]
 *          1    1    1
 * </pre>
 *
 * @return
 */
int main() {
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
    for (root_of_p = p; root_of_p != id[root_of_p]; root_of_p = id[root_of_p]);
    for (root_of_q = q; root_of_q != id[root_of_q]; root_of_q = id[root_of_q]);
    if (root_of_p == root_of_q) {
      printf("\t连通：%d %d\n", p, q);
      continue;
    }
    // 【关键代码段】以下的 if-else 就是相对于program_01_01.edited.c的改进部分，将小树挂在大树下面
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
