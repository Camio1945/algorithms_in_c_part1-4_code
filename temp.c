#include <stdio.h>
#include <string.h>
#include "./Chapter04/program_04_03/STACK.c"

main() {
  char *a = "((1+2)*3)";
  int N = strlen(a);
  STACKinit(N);
  for (int i = 0; i < N; ++i) {
    char c = a[i];
    if (c >= '0' && c <= '9') {
      printf("%c ", c);
    }
    if (c == '+' || c == '*') {
      STACKpush(c);
    }
    if (c == ')') {
      printf("%c ", STACKpop());
    }
  }
}
