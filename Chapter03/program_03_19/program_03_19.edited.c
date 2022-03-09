#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node {
  int v;
  link next;
};

/**
 * 新建节点
 * @param v 值
 * @param next 下一个节点
 * @return
 */
link NEW(int v, link next) {
  link x = malloc(sizeof *x);
  x->v = v;
  x->next = next;
  return x;
}

main() {
  setbuf(stdout, NULL); // 将标准输出的缓存区清零，防止printf不及时打印
  printf("本程序需要在控制台输入若干行数字(0到7之间的整数)，每行两个数字(数字间用空格隔开)，用于表示两个点是连通的，如：\n"
         "0 1\n"
         "0 2\n"
         "0 5\n"
         "0 6\n"
         "0 7\n"
         "1 7\n"
         "2 7\n"
         "3 4\n"
         "3 5\n"
         "4 5\n"
         "4 6\n"
         "4 7\n"
  );
  printf("提示：控制台输入完成后，按回车，然后按快捷键：Ctrl + D （也可能是Ctrl + C 或 Ctrl + Z，不同平台不一样，多试试）\n");
  int i, j, V = 8;
  link adj[V];
  // for循环作用：初始化一维数组adj
  for (i = 0; i < V; i++) {
    adj[i] = NULL;
  }
  // while循环作用：把输入的两个数关联到对应的链表上
  while (scanf("%d %d\n", &i, &j) == 2) {
    adj[i] = NEW(j, adj[i]);
    adj[j] = NEW(i, adj[j]);
  }
  // for循环作用：打印结果
  for (int k = 0; k < V; ++k) {
    link obj = adj[k];
    printf("连接到节点 %d 的节点有：", k);
    while (obj != NULL) {
      printf("%d", obj->v);
      obj = obj->next;
      if (obj != NULL) {
        printf(" -> ");
      }
    }
    printf("\n");
  }
}
