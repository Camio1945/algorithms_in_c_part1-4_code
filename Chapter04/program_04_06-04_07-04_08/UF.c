/** program_04_08 */

#include <stdlib.h>
#include "UF.h"

static int *id, *sz;

/** 初始化默认的连通情况与节点深度 */
void UFinit(int N) {
  int i;
  id = malloc(sizeof(int) * N); // 用于表示节点间是否连通
  sz = malloc(sizeof(int) * N); // 用于表示节点的深度
  for (i = 0; i < N; ++i) {
    id[i] = i; // 自己跟自己是连通的
    sz[i] = 1; // 节点的深度默认都是1
  }
}

/** 查找 */
static int find(x) {
  int i = x;
  while (id[i] != i) {
    i = id[i];
  }
  return i;
}

/** 查找 */
int UFfind(int p, int q) {
  return (find(p) == find(q));
}

/** 合并 */
void UFunion(int p, int q) {
  int i = find(p);
  int j = find(q);
  if (i == j) {
    return;
  }
  if (sz[i] < sz[j]) {
    id[i] = j;
    sz[j] += sz[i];
  } else {
    id[j] = i;
    sz[i] += sz[j];
  }
}

