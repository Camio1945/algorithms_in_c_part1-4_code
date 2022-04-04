/** 程序4.22：多项式的一级ADT接口 */
typedef struct poly *Poly;

void showPOLY(Poly);

Poly POLYterm(int, int);

Poly POLYadd(Poly, Poly);

Poly POLYmult(Poly, Poly);

float POLYeval(Poly, float);


