/** 程序6.13：记录元素的数据类型实现 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"

//int less(Item a, Item b) {
//  return a->num < b->num;
//}

int less(Item a, Item b) {
  return strcmp(a->name, b->name) < 0;
}

/**
 * 获取随机数
 * @return
 */
Item ITEMrand(void) {
  // 未实现
  return NULL;
}

#define maxN 2
struct record data[maxN];
int Nrecs = 0;

int ITEMscan(struct record **x) {
  *x = &data[Nrecs];
  int t = scanf("%s %d", data[Nrecs].name, &data[Nrecs].num);
  Nrecs++;
  return t;
}

void ITEMshow(struct record *x) {
  printf("%3d %-30s\n", x->num, x->name);
}


