#include <stdio.h>
#include <stdlib.h>
typedef struct
{
char nombre[20];
int dni;
} Persona;
Persona* mayor(Persona* fila);
int main()
{
    Persona *arr;
    arr=malloc(sizeof(Persona)*2);
    arr->nombre='a';
    arr->dni=123;
    arr->nombre='b';
    arr->dni=0;
    printf("%d\n",mayor(arr));
    return 0;
}

Persona* mayor(Persona* fila)
{
Persona* mayorAux;
if ( fila->dni == 0)
return fila;
else
{
mayorAux = mayor(fila + 1);
if (fila->dni > mayorAux->dni)
mayorAux = fila;
return mayorAux;
}
}
