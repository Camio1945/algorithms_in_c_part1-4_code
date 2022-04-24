/** 程序6.12：记录数据项的数据类型接口 */

struct record {
  char name[30]; // 名称
  int num; // 数量
};
typedef struct record *Item;
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B);

int less(Item, Item);

Item ITEMrand();

int ITEMscan(Item *);

void ITEMshow(Item);
