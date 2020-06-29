#include <stdio.h>
#include <stdlib.h>

int* cargarArr()
{
    printf("test 1\n--------------\n");
    int *arr=NULL,i=0,n=0;
    arr=(int*)malloc(sizeof(int));
    printf("\ningrese numeros: ");
    scanf("%d",&n);
    *(arr)=n;
    while(n!=0)
    {
        printf("inrese numeros:");
        scanf("%d",&n);
        i++
        arr=(int*)realloc(sizeof(int)*(i+1));
        *(arr+i)=n;
    }

    return &arr;
}
