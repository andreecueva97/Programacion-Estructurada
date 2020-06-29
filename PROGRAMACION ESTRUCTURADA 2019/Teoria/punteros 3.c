#include <stdio.h>
#include <stdlib.h>

void incrementar(int *c);

void main()
{
    int a = 0;
    incrementar(&a);
    printf("Valor de a: %d", a);
}

void incrementar(int *c)
{
    *c = *c + 1;
}
