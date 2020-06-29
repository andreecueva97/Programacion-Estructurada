#include <stdio.h>
#include <stdlib.h>

int invertir(int *p, int *q);

void main(){
    int a = 5;
    int b = 7;
    printf("%d - %d\n",a,b);
    invertir(&a,&b);
    printf("%d - %d",a,b);
}

int invertir(int *p, int *q){

    int aux = 0;

    aux = *p;
    *p = *q;
    *q = aux;
}
