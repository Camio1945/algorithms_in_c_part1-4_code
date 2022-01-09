int search(int a[], int v, int l, int r) {
  int i;
  for (i = l; i <= r; i++)
    if (v == a[i]) return i;
  return -1;
}
