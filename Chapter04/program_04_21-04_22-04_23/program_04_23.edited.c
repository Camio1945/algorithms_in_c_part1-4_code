#include <stdlib.h>
#include <stdio.h>
#include "POLY.h"

struct poly {
  int N; // 多项式的项数
  int *a; // 每一项的系数，a[0]代表常数项，a[1]代表1次方的系数，a[2]代表平方的系数，依此类推
};

/** 显示多项式的公式 */
void showPOLY(Poly p) {
  printf("展开二项式：");
  for (int i = 0; i < p->N; ++i) {
    int coeff = p->a[i];
    if (i == 0) {
      printf("%d", coeff); // 常数项
    } else if (i == 1) {
      if (coeff == 1) {
        printf("x"); // 1次方项
      } else {
        printf("%dx", coeff); // 1次方项
      }
    } else {
      if (coeff == 1) {
        printf("x^%d", i); // 1次方项
      } else {
        printf("%dx^%d", coeff, i); // 其他次方项
      }
    }
    if (i < p->N - 1) {
      printf(" + ");
    }
  }
  printf("\n");
}

/**
 * 初始化多项式中的一项，比如系数coeff为3，exp为4时，代表的是：3乘以(某个变量的4次方)
 * @param coeff 系数
 * @param exp 次方
 * @return
 */
Poly POLYterm(int coeff, int exp) {
  int i;
  Poly t = malloc(sizeof *t);
  t->a = malloc((exp + 1) * sizeof(int));
  t->N = exp + 1;
  t->a[exp] = coeff;
  for (i = 0; i < exp; i++) {
    t->a[i] = 0;
  }
  return t;
}

/** 多项式的加法 */
Poly POLYadd(Poly p, Poly q) {
  int i;
  Poly t;
  if (p->N < q->N) {
    t = p;
    p = q;
    q = t;
  }
  for (i = 0; i < q->N; i++) {
    p->a[i] += q->a[i];
  }
  return p;
}

/** 多项式的乘法 */
Poly POLYmult(Poly p, Poly q) {
  int i, j;
  Poly t = POLYterm(0, (p->N - 1) + (q->N - 1));
  for (i = 0; i < p->N; i++) {
    for (j = 0; j < q->N; j++) {
      t->a[i + j] += p->a[i] * q->a[j];
    }
  }
  return t;
}

/**
 * 计算多项式的结果
 * @param p 多项式
 * @param x 变量x
 * @return
 */
float POLYeval(Poly p, float x) {
  int i;
  double t = 0.0;
  for (i = p->N - 1; i >= 0; i--) {
    t = t * x + p->a[i];
  }
  return t;
}
