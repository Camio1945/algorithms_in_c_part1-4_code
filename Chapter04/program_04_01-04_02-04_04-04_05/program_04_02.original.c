#include <stdio.h>
#include <string.h>
#include "STACK_by_array.c"

main(int argc, char *argv[]) {
  char *a = argv[1];
  int i, N = strlen(a);
  STACKinit(N);
  for (i = 0; i < N; i++) {
    if (a[i] == '+')
      STACKpush(STACKpop() + STACKpop());
    if (a[i] == '*')
      STACKpush(STACKpop() * STACKpop());
    if ((a[i] >= '0') && (a[i] <= '9'))
      STACKpush(0);
    while ((a[i] >= '0') && (a[i] <= '9'))
      STACKpush(10 * STACKpop() + (a[i++] - '0'));
  }
  printf("%d \n", STACKpop());
}
