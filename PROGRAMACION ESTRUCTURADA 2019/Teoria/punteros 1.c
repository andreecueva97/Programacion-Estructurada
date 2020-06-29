#include <stdio.h>
#include <stdlib.h>

/* Punteros */

/*
  "*" El contenido de direccion. Declarar punteros.
  "&" La direccion de variable.
*/

void main()
{
    char c;                                         /*Char ocupa 1b */
    int n;                                          /* Int ocupa 4b */
    int *pn = NULL;                                 /* Los punteros siempre ocupan 4b sea int o char */
    c=64;
    n=5;

    printf("Contenido de c: %d",c);                  /*64*/
    printf("\nDireccion de c: %d",&c);               /*Numero cualquiera*/

    pn = &n;                                         /*Posicion de memoria de n*/

    printf("\nPosicion de memoria de pn: %p",pn);    /*Para imprimir posicion de memoria se usa %p*/
    printf("\nContenido de pn: %d",*pn);             /*Para imprimir posicion de memoria se usa %p*/
}
