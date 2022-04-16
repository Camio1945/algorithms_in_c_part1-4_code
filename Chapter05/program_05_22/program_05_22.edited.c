/** 程序5.22：广度优先搜索 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node {
  int v; // 节点的值
  link next; // 下一个元素
};

int *visited;
link *adj;


int V = 80; // 这里指的是树节点的数量
int *QUEUE; // 队列
int headIndex = -1; // 队列头索引
int tailIndex = -1; // 队列尾索引

/** 初始化队列 */
void QUEUEinit(int max) {
  QUEUE = malloc(sizeof(int) * max);
  for (int i = 0; i < max; ++i) {
    QUEUE[i] = -1;
  }
}

/** 判断队列是否为空 */
int QUEUEempty() {
  return headIndex == -1;
}

/** 放到队列尾部 */
void QUEUEput(int h) {
  tailIndex++;
  QUEUE[tailIndex] = h;
  if (headIndex == -1) {
    headIndex = 0;
  }
}

/** 从队列头部获取 */
int QUEUEget() {
  int h = QUEUE[headIndex];
  QUEUE[headIndex] = -1;
  headIndex++;
  if (QUEUE[headIndex] == -1) {
    headIndex = -1;
    tailIndex = -1;
  }
  return h;
}

/**
 * 遍历
 * @param k 节点下标
 * @param visit 访问方法
 */
void traverse(int k, void visit(int)) {
  QUEUEinit(V);
  QUEUEput(k);
  while (!QUEUEempty()) {
    k = QUEUEget();
    if (!visited[k]) {
      visit(k);
      visited[k] = 1;
      for (link t = adj[k]; t != NULL; t = t->next) {
        if (!visited[t->v]) {
          QUEUEput(t->v);
        }
      }
    }
  }
}

/** 访问一个整型值 */
void visitInt(int item) {
  printf("%d ", item);
}

/** 初始化邻接矩阵 */
void initAdj(link node, int arr[], int arrSize) {
  link prevNode;
  for (int i = 0; i < arrSize; ++i) {
    link newNode = malloc(sizeof(link));
    newNode->v = arr[i];
    newNode->next = NULL;
    if (i == 0) {
      node->v = newNode->v;
      node->next = NULL;
      prevNode = node;
    } else {
      prevNode->next = newNode;
      prevNode = newNode;
    }
  }
}

/** 准备数据 */
void prepareData() {
  int nodeNumber = 8;
  visited = malloc(sizeof(int) * nodeNumber);
  adj = malloc(sizeof(link) * nodeNumber);
  for (int i = 0; i < nodeNumber; ++i) {
    visited[i] = 0;
    adj[i] = malloc(sizeof(link));
  }
  int arr0[] = {7, 5, 2, 1, 6};
  initAdj(adj[0], arr0, sizeof(arr0) / sizeof(int));

  int arr1[] = {7, 0};
  initAdj(adj[1], arr1, sizeof(arr1) / sizeof(int));

  int arr2[] = {7, 0};
  initAdj(adj[2], arr2, sizeof(arr2) / sizeof(int));

  int arr3[] = {5, 4};
  initAdj(adj[3], arr3, sizeof(arr3) / sizeof(int));

  int arr4[] = {6, 5, 7, 3};
  initAdj(adj[4], arr4, sizeof(arr4) / sizeof(int));

  int arr5[] = {0, 4, 3};
  initAdj(adj[5], arr5, sizeof(arr5) / sizeof(int));

  int arr6[] = {4, 0};
  initAdj(adj[6], arr6, sizeof(arr6) / sizeof(int));

  int arr7[] = {1, 2, 0, 4};
  initAdj(adj[7], arr7, sizeof(arr7) / sizeof(int));
}

main() {
  setbuf(stdout, NULL);
  printf("广度优先搜索\n");
  prepareData();
  traverse(0, visitInt);
}
