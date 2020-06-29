#include <stdio.h>
#include <stdlib.h>

/*Punteros de punteros*/

void main()
{
    int n = 0;
    int *pn = NULL;
    int **ppn = NULL;
    n = 10;
    pn = &n;
    ppn = &pn;
    printf("Direccion de pn: %p\nContenido de n: %d",*ppn,*pn);
}


/*
      Contenido   Posicion
n :      10         #20
pn :    #20         #50
ppn :   #50         #70

n = 10
pn = &n = #20
ppn = &pn = #50

*pn = 10
*ppn = #20

*/
