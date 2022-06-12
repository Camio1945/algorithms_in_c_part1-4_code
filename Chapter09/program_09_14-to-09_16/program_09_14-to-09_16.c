/** 程序9.14~9.16：二项队列的相关操作 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)


/** 打印数组 */
void printArr(char *prefix, int *a, int size) {
  printf("%s", prefix);
  for (int i = 0; i < size; i++) {
    if (a[i] > 1000) {
      continue;
    }
    printf("%3d ", a[i]);
  }
  printf("\n");
}

typedef int Item;
typedef struct PQnode *PQlink;
typedef struct pq *PQ;

struct PQnode {
  Item key;
  PQlink l, r;
};

struct pq {
  PQlink *bq;
};

/**
 * 两个大小相等的2次幂堆的合并（程序9.13）
 * @param p 2次幂堆，要求与q的大小相等
 * @param q 2次幂堆，要求与q的大小相等
 * @return
 */
PQlink pair(PQlink p, PQlink q) {
  if (less(p->key, q->key)) {
    p->r = q->l;
    q->l = p;
    return q;
  } else {
    q->r = p->l;
    p->l = q;
    return p;
  }
}

#define maxBQsize 10
#define z NULL

/**
 * 判断队列是否为空
 * @param pq
 * @return
 */
int PQempty(PQ pq) {
  int i;
  for (i = 0; i < maxBQsize; i++) {
    if (pq->bq[i] != z) {
      return 0;
    }
  }
  return 1;
}

/** 优先队列初始化 */
PQ PQinit() {
  int i;
  PQ p = malloc(sizeof(struct pq));
  p->bq = malloc(maxBQsize * sizeof(PQlink));
  for (i = 0; i < maxBQsize; i++) {
    p->bq[i] = z;
  }
  return p;
}

/**
 * 二项队列中的插入操作（程序9.14）
 * @param pq 优先队列
 * @param v 要插入的值
 * @return
 */
PQlink PQinsert(PQ pq, Item v) {
  int i;
  PQlink c = malloc(sizeof *c);
  c->l = z;
  c->r = z;
  c->key = v;
  for (i = 0; i < maxBQsize; i++) {
    if (pq->bq[i] == z) {
      pq->bq[i] = c;
      break;
    }
    c = pair(c, pq->bq[i]);
    pq->bq[i] = z;
  }
  return c;
}

#define test(C, B, A) 4*(C) + 2*(B) + 1*(A)

/**
 * 两个二项队列中的连接（合并）操作（程序9.16）
 * @param a
 * @param b
 */
void BQjoin(PQlink *a, PQlink *b) {
  int i;
  PQlink c = z;
  for (i = 0; i < maxBQsize; i++) {
    int testRes = test(c != z, b[i] != z, a[i] != z);
//    printf("\ntestRes : %d  ", testRes);
    switch (testRes) {
      case 2:
        a[i] = b[i];
        break;
      case 3:
        c = pair(a[i], b[i]);
        a[i] = z;
        break;
      case 4:
        a[i] = c;
        c = z;
        break;
      case 5:
        c = pair(c, a[i]);
        a[i] = z;
        break;
      case 6:
      case 7:
        c = pair(c, b[i]);
        break;
    }
  }
}

/**
 * 两个二项队列中的连接（合并）操作（程序9.16）
 * @param a
 * @param b
 */
void PQjoin(PQ a, PQ b) {
  BQjoin(a->bq, b->bq);
}


/**
 * 删除最大元素（程序9.15）
 * @param pq
 * @return
 */
Item PQdelmax(PQ pq) {
  int i, max;
  PQlink x;
  Item v;
  PQlink temp[maxBQsize];
  for (i = 0, max = -1; i < maxBQsize; i++) {
    if (pq->bq[i] != z) {
      if ((max == -1) || less(v, pq->bq[i]->key)) {
        max = i;
        v = pq->bq[max]->key;
      }
    }
  }
  x = pq->bq[max]->l;
  for (i = max; i < maxBQsize; i++) {
    temp[i] = z;
  }
  for (i = max; i > 0; i--) {
    temp[i - 1] = x;
    x = x->r;
    temp[i - 1]->r = z;
  }
  free(pq->bq[max]);
  pq->bq[max] = z;
  BQjoin(pq->bq, temp);
  return v;
}


/**
 * 打印节点
 * @param c 节点的名称
 * @param h 高度
 */
void printnode(int key, int h) {
  for (int i = 0; i < h; ++i) {
    printf("    ");
  }
  printf("%d\n", key);
}

/**
 * 显示树结构（程序5.18）
 * @param x 节点
 * @param h 高度
 */
void show(PQlink x, int h) {
  if (x == NULL) {
    // printnode('*', h);
    return;
  }
  show(x->r, h + 1);
  printnode(x->key, h);
  show(x->l, h + 1);
}


main() {
  setbuf(stdout, NULL);
//  srand((unsigned) time(NULL)); // 初始化随机数种子
  rand();
  printf("程序9.14~9.16：二项队列的相关操作\n");
  int i, x, N = 5, M = 7;
  printf("创建第1个队列：");
  PQ q1 = PQinit();
  for (i = 0; i < N; i++) {
    x = rand() % 1000;
    printf("%d ", x);
    PQinsert(q1, x);
  }
  printf("\n打印第1个队列：\n");
  for (int i = 0; i < N; i++) {
    if (q1->bq[i] != NULL) {
      show(q1->bq[i], 0);
    }
  }

  printf("\n创建第2个队列：");
  PQ q2 = PQinit();
  for (i = 0; i < M; i++) {
    x = rand() % 1000;
    printf("%d ", x);
    PQinsert(q2, x);
  }
  printf("\n打印第2个队列：\n");
  for (int i = 0; i < M; i++) {
    if (q2->bq[i] != NULL) {
      show(q2->bq[i], 0);
    }
  }

  printf("\n删除第1个队列中的最大值：%d", PQdelmax(q1));
  printf("\n打印第1个队列：\n");
  for (int i = 0; i < N; i++) {
    if (q1->bq[i] != NULL) {
      show(q1->bq[i], 0);
    }
  }

  printf("\n删除第2个队列中的最大值：%d", PQdelmax(q2));
  printf("\n打印第2个队列：\n");
  for (int i = 0; i < M; i++) {
    if (q2->bq[i] != NULL) {
      show(q2->bq[i], 0);
    }
  }

  printf("\n合并队列：");
  PQjoin(q1, q2);
  printf("\n打印第1个队列：\n");
  for (int i = 0; i < N; i++) {
    if (q1->bq[i] != NULL) {
      show(q1->bq[i], 0);
    }
  }
  printf("\n从大到小打印：");
  while (!PQempty(q1)) {
    printf("%d ", PQdelmax(q1));
  }
  printf("\n");
}
