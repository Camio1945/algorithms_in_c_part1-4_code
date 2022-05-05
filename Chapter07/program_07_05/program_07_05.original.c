#define eq(A, B) (!less(A, B) && !less(B, A))

void quicksort(Item a[], int l, int r) {
  int i, j, k, p, q;
  Item v;
  if (r <= l) return;
  v = a[r];
  i = l - 1;
  j = r;
  p = l - 1;
  q = r;
  for (;;) {
    while (less(a[++i], v));
    while (less(v, a[--j])) if (j == l) break;
    if (i >= j) break;
    exch(a[i], a[j]);
    if (eq(a[i], v)) {
      p++;
      exch(a[p], a[i]);
    }
    if (eq(v, a[j])) {
      q--;
      exch(a[q], a[j]);
    }
  }
  exch(a[i], a[r]);
  j = i - 1;
  i = i + 1;
  for (k = l; k < p; k++, j--) exch(a[k], a[j]);
  for (k = r - 1; k > q; k--, i++) exch(a[k], a[i]);
  quicksort(a, l, j);
  quicksort(a, i, r);
}
