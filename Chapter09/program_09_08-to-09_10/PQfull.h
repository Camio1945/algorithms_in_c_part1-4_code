/** 程序9.8：一级优先队列ADT */
typedef int Item;
typedef struct pq *PQ;
typedef struct PQnode *PQlink;

PQ PQinit();

int PQempty(PQ);

PQlink PQinsert(PQ, Item);

Item PQdelmax(PQ);

void PQchange(PQ, PQlink, Item);

void PQdelete(PQ, PQlink);

void PQjoin(PQ, PQ);
