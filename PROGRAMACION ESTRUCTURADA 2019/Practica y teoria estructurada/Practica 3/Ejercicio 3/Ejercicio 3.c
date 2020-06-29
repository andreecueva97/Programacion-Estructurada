#include <stdio.h>
#include <stdlib.h>

void redondeo(double *x);

void main(){
    double x = 18.7;
    printf("%.1lf\n",x);
    redondeo(&x);
    printf("%.1lf",x);

    return 0;
}

void redondeo(double *x){

    int aux = *x;
    if ((*x - aux) > 0.5){

        *x = aux + 1;
    }
    else{
        *x = aux;
    }
}
