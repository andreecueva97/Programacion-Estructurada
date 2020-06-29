#include <stdio.h>
#include <stdlib.h>

void invertir(int arr[5], int a);

int main()
{
    int a = 0, i = 0;
    int arr[6] = {1,2,3,4,5};
    arr[6] = '\0';
    while (arr[a] != '\0')
    {
        a++;
    }
    printf("Arreglo original: \n");
    while (arr[i] != '\0')
    {
        printf("%d ",arr[i]);
        i++;
    }
    printf("\n");
    printf("Arreglo invertido: \n");
    invertir(arr,a-1);
    return 0;
}

void invertir(int arr[5], int a)
{
    printf("%d ",arr[a]);
    if (a != 0)
    {
        invertir(arr,a-1);
    }
}
