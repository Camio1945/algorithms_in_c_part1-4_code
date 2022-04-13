int F(int i) {
  int t;
  if (knownF[i] != unknown) return knownF[i];
  if (i == 0) t = 0;
  if (i == 1) t = 1;
  if (i > 1) t = F(i - 1) + F(i - 2);
  return knownF[i] = t;
}
