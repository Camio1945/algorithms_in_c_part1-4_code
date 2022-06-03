#include "PQindex.h"

typedef int Item;

#define maxPQ 100

static int N, pq[maxPQ + 1], qp[maxPQ + 1];
Item *a;

int less(int i, int j) {
  return (a[i] < a[j]);
}

void exch(int i, int j) {
  int t;
  t = qp[i];
  qp[i] = qp[j];
  qp[j] = t;
  pq[qp[i]] = i;
  pq[qp[j]] = j;
}

/**
 * 程序9.3：自底向上堆化（仅适用于添加新元素时）
 * @param a
 * @param k
 */
void fixUp(Item a[], int k) {
  while (k > 1 && less(a[k / 2], a[k])) {
    exch(a[k], a[k / 2]);
    k = k / 2;
  }
}

/**
 * 程序9.4：自顶向下堆化（仅适用于删除最大元素时）
 * @param a
 * @param k
 * @param N
 */
void fixDown(Item a[], int k, int N) {
  int j;
  while (2 * k <= N) {
    j = 2 * k;
    if (j < N && less(a[j], a[j + 1])) {
      j++;
    }
    if (!less(a[k], a[j])) {
      break;
    }
    exch(a[k], a[j]);
    k = j;
  }
}

void PQinit(void) {
  N = 0;
}

int PQempty(void) {
  return !N;
}

void PQinsert(int k) {
  qp[k] = ++N;
  pq[N] = k;
  fixUp(pq, N);
}

/**
 * 删除最大值（注意这里返回的是数组最大值的下标，而不是最大值本身）
 * @return
 */
int PQdelmax(void) {
  exch(pq[1], pq[N]);
  fixDown(pq, 1, --N);
  return pq[N + 1];
}

void PQchange(int k) {
  fixUp(pq, qp[k]);
  fixDown(pq, qp[k], N);
}
