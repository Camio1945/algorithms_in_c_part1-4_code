#define min(A, B) (A < B) ? A : B

void mergesortBU(Item a[], int l, int r) {
  int i, m;
  for (m = 1; m <= r - l; m = m + m)
    for (i = l; i <= r - m; i += m + m)
      merge(a, i, i + m - 1, min(i + m + m - 1, r));
}
