#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct{
    int a,b;
}t_dosint;

void invertir(int *p, int*q);

int main()
{
    t_dosint x;
    x.a = 7;
    x.b = 5;
    printf("%d %d\n", x.a,x.b);
    invertir(&x.a, &x.b);
    printf("%d %d", x.a,x.b);
    return 0;
}

void invertir(int *p, int*q)
{
    int aux;
    aux = *p;
    *p = *q;
    *q = aux;
}
