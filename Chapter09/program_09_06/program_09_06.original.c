void PQsort(Item a[], int l, int r) {
  int k;
  PQinit();
  for (k = l; k <= r; k++) PQinsert(a[k]);
  for (k = r; k >= l; k--) a[k] = PQdelmax();
}
