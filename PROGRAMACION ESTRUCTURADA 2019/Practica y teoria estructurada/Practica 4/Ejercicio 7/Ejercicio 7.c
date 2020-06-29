#include <stdio.h>
#include <stdlib.h>

unsigned int contar_vocales(char arr[5], int n,int cont);

int main()
{
    char arr[5] = "hola";
    printf("Cantidad de vocales en '%s': %d",arr,contar_vocales(arr,0,0));
    return 0;
}

unsigned int contar_vocales(char arr[5], int n, int cont)
{
    if (n != 4)
    {
        if(*(arr + n) == 'a' || *(arr + n) == 'e' || *(arr + n) == 'i' || *(arr + n) == 'o' ||*(arr + n) == 'u')
        {
            cont++;
        }
        return contar_vocales(arr,n+1,cont);
    }

    return cont;
}
