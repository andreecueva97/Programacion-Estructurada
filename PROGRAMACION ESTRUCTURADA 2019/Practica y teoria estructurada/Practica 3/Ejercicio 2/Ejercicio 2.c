#include <stdio.h>
#include <stdlib.h>

int posicion(int arr[10], int pos);

void main(){
    int arr[10] = {15,26,89,116,35,24,99,44,62,128};
    int pos;
    int *p = NULL;
    printf("Ingrese posicion: ");
    scanf("%d",&pos);

    p = posicion(arr,pos);
    printf("%d",*p);
    return 0;
}

int posicion(int arr[10], int pos){

     return &arr[pos];
}

