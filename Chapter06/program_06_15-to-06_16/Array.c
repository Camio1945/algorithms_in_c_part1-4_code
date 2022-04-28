#include "Item.c"
#include "Array.h"

link NEW(Item item, link next) {
  link newNode = malloc(sizeof(link));
  newNode->item = item;
  newNode->next = next;
  return newNode;
}

link init(int number) {
  number++;
  link head = malloc(sizeof(link));
  link x = head;
  int i = 1;
  while (i <= number) {
    x->item = 1000 * (1.0 * rand() / RAND_MAX);;
    if (i != number) {
      x->next = malloc(sizeof(link));
      x = x->next;
    } else {
      x->next = NULL;
    }
    i++;
  }
  head->item = -1;
  return head;
}

void show(link h) {
  while (h != NULL) {
    if (h->item != -1) {
      printf("%3d ", h->item);
    }
    h = h->next;
  }
}

link findmax(link h) {
  link max = h;
  h = max->next;
  while (h->next != NULL) {
    if (h->next->item > max->next->item) {
      max = h;
    }
    h = h->next;
  }
  return max;
}


link sort(link h) {
  link max, t, out = NULL;
  while (h->next != NULL) {
    max = findmax(h); // 这里的max不是最大值，max.next才是最大值
    t = max->next; // 这里的t是最大值
    max->next = t->next; // 表示max后面的那个节点被单独拿出来了（即t）
    t->next = out; // out是上一次的最大值（链表）
    out = t; // out是上一次的最大值（链表）

    printf("    out：");
    show(out);
    printf("\n");
    printf("      h：");
    show(h);
    printf("\n");
  }
  h->next = out;
  return h;
}
