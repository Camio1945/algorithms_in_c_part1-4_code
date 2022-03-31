#include <stdio.h>

typedef struct node *link;

struct node {
  int item;
  link next;
};
int staticVar;

void testStatic1() {
//  static int staticVar;
  printf("staticVar : %d\n", staticVar);
  staticVar = 100;
  int localVar;
  printf(" localVar : %d\n", localVar);
  localVar = 100;
}


void testStatic2() {
//  static int staticVar;
  printf("staticVar : %d\n", staticVar);
  staticVar = 100;
  int localVar = 0;
  printf(" localVar : %d\n", localVar);
  localVar = 100;
}


main() {
  testStatic1();
  testStatic1();

  printf("\n");

  testStatic2();
  testStatic2();
}
