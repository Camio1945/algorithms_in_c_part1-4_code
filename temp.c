#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Item;
/*

typedef struct STACKnode *link;

struct STACKnode {
  Item item;
  link next;
};
link head;

void STACKinit(int maxN) {
  head = NULL;
}

int STACKEmpty() {
  return head == NULL;
}

void STACKpush(Item item) {
  link x = malloc(sizeof(link));
  x->item = item;
  x->next = head;
  head = x;
}

Item STACKpop() {
  link x = head;
  head = head->next;
  return x->item;
}
*/

Item *s;
int N;
void STACKinit(int maxN) {
  s = malloc(maxN * sizeof(Item));
  N = 0;
}
int STACKEmpty() {
  return N == 0;
}
void STACKpush(Item item) {
  s[N] = item;
  N++;
}
Item STACKpop() {
  N--;
  Item item = s[N];
  return item;
}

main() {
  setbuf(stdout, NULL);
  char *a = "123 13 +";
  int N = strlen(a);
  STACKinit(N);
  for (int i = 0; i < N; ++i) {
    char c = a[i];
    if (c == '+') {
      Item num1 = STACKpop();
      Item num2 = STACKpop();
      Item num3 = num1 + num2;
      STACKpush(num3);
    }
    if (c == '*') {
      Item num1 = STACKpop();
      Item num2 = STACKpop();
      Item num3 = num1 * num2;
      STACKpush(num3);
    }
    if (c >= '0' && c <= '9') {
      STACKpush(0);
    }
    while (c >= '0' && c <= '9') {
      Item pop = STACKpop();
      Item previous = 10 * pop;
      Item current = c - '0';
      Item total = previous + current;
      STACKpush(total);
      i++;
      c = a[i];
    }
  }
  Item res = STACKpop();
  printf("结果：%d \n", res);
}
