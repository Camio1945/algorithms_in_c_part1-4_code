#include <stdio.h>
#include <stdlib.h>

#include "./Chapter04/program_04_21-04_22-04_23/program_04_23.edited.c"


main() {
  Poly p1 = POLYterm(1, 2);
  printf("POLYeval(p1, 2) : %f\n", POLYeval(p1, 2));
  Poly p2 = POLYterm(3, 4);
  printf("POLYeval(p2, 2) : %f\n", POLYeval(p2, 2));
//  Poly p3 = POLYadd(p1, p2);
//  printf("POLYeval(p3, 2) : %f\n", POLYeval(p3, 2));
  Poly p4 = POLYmult(p1, p2);
  printf("POLYeval(p4, 2) : %f\n", POLYeval(p4, 2));


}
