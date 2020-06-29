#include <stdio.h>
#include <stdlib.h>
#define T 6
int main()
{
    char arr[T]={"hola"};
    printf("\n - - - CHAR- - - \n");
    printf("contenido arreglo arr: %s\n",arr);
    printf("dir arreglo arr: %d\n",arr);
    printf("contenido arreglo *arr: %c\n",*(arr+0));
    printf("contenido arreglo *arr: %c\n",arr[0]);
    printf("contenido arreglo *arr: %c\n",*(arr+2));
    printf("contenido arreglo *arr: %c\n",arr[2]);
    printf("dir mem pos 2 de arr[2]: %d\n",&(arr[2]));
    printf("dir mem pos 2 de  arr + 2: %d\n",arr+2);

    printf("\n - - - ENTEROS- - - \n");
    int arrI[T]={5,7,22,42,18,21};
    printf("contenido arreglo arr: %d\n",arrI);
    printf("dir arreglo arr: %d\n",arrI);
    printf("contenido arreglo *arr: %d\n",*(arrI+0));
    printf("contenido arreglo *arr: %d\n",arrI[0]);
    printf("contenido arreglo *arr: %d\n",*(arrI+2));
    printf("contenido arreglo *arr: %d\n",arrI[2]);
    printf("dir mem pos 2 de arr[2]: %d\n",&(arrI[2]));
    printf("dir mem pos 2 de  arr + 2: %d\n",arrI+2);



    return 0;
}
