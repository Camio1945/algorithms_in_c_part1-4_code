#include <stdlib.h>
#include <stdio.h>

typedef struct node *link;
struct node {
  int item;
  link next;
};

main(int argc, char *argv[]) {
  setbuf(stdout, NULL); // 将标准输出的缓存区清零，防止printf不及时打印
  printf("本程序接收两个参数，第1个参数代表圈中的人数(int类型)，第2个参数代表数到几之后出圈(int类型)，如：9 5\n");
  int i, N = atoi(argv[1]), M = atoi(argv[2]);
  link t = malloc(sizeof *t), x = t;
  t->item = 1;
  t->next = t;
  for (i = 2; i <= N; i++) {
    x = (x->next = malloc(sizeof *x));
    x->item = i;
    x->next = t;
  }
  while (x != x->next) {
    for (i = 1; i < M; i++) {
      x = x->next;
    }
    link to_be_deleted = x->next;
    x->next = x->next->next;
    free(to_be_deleted);
  }
  printf("最后选出来的领导人是：%d\n", x->item);
}
