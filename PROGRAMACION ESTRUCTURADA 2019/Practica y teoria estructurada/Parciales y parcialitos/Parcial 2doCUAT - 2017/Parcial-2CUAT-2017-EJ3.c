#include <stdio.h>
#include <stdlib.h>

int cantImpar(int* );

int main()
{
    int arreglo[6] = {1,2,4,5,3,0};
    int impares;

    impares = cantImpar(arreglo);

    printf("La cantidad de impares: %d",impares);

    return 0;
}

int cantImpar(int* arreglo)
{
    if(*arreglo != 0)
    {
        if((*arreglo % 2) != 0)
        {
            return 1 + cantImpar(arreglo+1);
        }
        else
        {
            return cantImpar(arreglo+1);
        }
    }
    else
    {
        return 0;
    }
}
