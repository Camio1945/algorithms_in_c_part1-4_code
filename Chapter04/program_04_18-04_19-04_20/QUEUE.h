/** 程序4.18：队列的一级ADT接口 */
#include "Item.h"

typedef struct queue *Q;

Q QUEUEinit(int);

int QUEUEempty(Q);

void QUEUEput(Q, Item);

Item QUEUEget(Q);
