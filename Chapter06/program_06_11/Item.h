typedef char *Item;
#include <string.h>
#define key(A) (A)
#define less(A, B) (strcmp(key(A), key(B)) < 0)
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

int ITEMrand(void);

int ITEMscan(char **x);

void ITEMshow(char *x);
