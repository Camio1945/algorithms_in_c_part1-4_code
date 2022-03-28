/** program_04_08 */

#include <stdlib.h>
#include "UF.h"

static int *id, *sz;

void UFinit(int N) {
  int i;
  id = malloc(sizeof(int) * N);
  sz = malloc(sizeof(int) * N);
  for (i = 0; i < N; ++i) {
    id[i] = i; // 自己跟自己是连通的
    sz[i] = 1; // 节点的深度默认都是1
  }
}

static int find(x) {
  int i = x;
  while (id[i] != i) {
    i = id[i];
  }
  return i;
}

int UFfind(int p, int q) {
  return (find(p) == find(q));
}

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

