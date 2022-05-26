link merge(link a, link b);

link mergesort(link t) {
  link u;
  for (Qinit(); t != NULL; t = u) {
    u = t->next;
    t->next = NULL;
    Qput(t);
  }
  t = Qget();
  while (!Qempty()) {
    Qput(t);
    t = merge(Qget(), Qget());
  }
  return t;
}
