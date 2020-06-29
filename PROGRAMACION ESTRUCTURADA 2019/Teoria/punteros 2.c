#include <stdio.h>
#include <stdlib.h>

void main()
{
    char *pn = NULL;
    char arr[5] = "hola";
    int i = 0;

    printf("Direccion del arreglo: %p",arr);                   /*El arreglo es un puntero */
    printf("\nContenido de la direccion: %c\n\n",*arr);        /*Si la direccion es #41 imprime lo que hay es 4-1*/

    for (i=0;i<4;i++)                                          /*Moverse en la direccion*/
    {
        printf("%p: %c\n",(arr+i),*(arr + i));                 /*Imprime posicion y contenido*/
    }

    printf("\n");

    for (i=0;i<4;i++)
    {
        printf("Posicion: %d\n",*(arr + i));
    }


}
