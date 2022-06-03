/** 程序9.11：索引数据项的优先队列ADT接口 */

int less(int, int);

void PQinit(void);

int PQempty();

void PQinsert(int);

int PQdelmax();

void PQchange(int);

void PQdelete(int);
