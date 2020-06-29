#include <stdio.h>
#include <stdlib.h>

struct s_cuatro{
    int a,b,c,d;
};
typedef struct s_cuatro t_cuatro;

void ordenar(t_cuatro *q);
int main()
{
    t_cuatro x = {7,1,5,9};
    ordenar(&x);
    printf("%d,%d,%d,%d",x.a,x.b,x.c,x.d);
    return 0;
}

void ordenar(t_cuatro *q){
    int i,j;
    int *aux;
    int aux2;
    aux = q;
    for (i=0;i<4;i++){

        for(j=0;j<4;j++){

            if (*(aux + i) < *(aux + j)){
                aux2 = *(aux + i);
                *(aux + i) = *(aux + j);
                *(aux + j) = aux2;

            }
        }
    }
}
