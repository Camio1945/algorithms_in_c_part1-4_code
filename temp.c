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
  int i, j, V = 8;
  link adj[V];
  for (i = 0; i < V; i++) {
    adj[i] = NULL;
  }
  int arr2d[12][2] = {
      {0, 1},
      {0, 2},
      {0, 5},
      {0, 6},
      {0, 7},
      {1, 7},
      {2, 7},
      {3, 4},
      {3, 5},
      {4, 5},
      {4, 6},
      {4, 7},
  };
  for (int k = 0; k < 12; ++k) {
    i = arr2d[k][0];
    j = arr2d[k][1];
    adj[i] = NEW(j, adj[i]);
    adj[j] = NEW(i, adj[j]);
  }
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
