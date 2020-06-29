#include <stdio.h>
#include <stdlib.h>

int ordenar(int arr[5], int a);

int main()
{
    int a = 0, i = 0;
    int arr[6] = {41,25,3,142,98};
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
    printf("Arreglo ordenado: \n");
    ordenar(arr,a);
    return 0;
}

int ordenar(int arr[5],int n)
{
    int i;
    if (n != 0)
    {

        for(i = 0; i < n-1; i++)
        {
            if(arr[i+1] > arr[i])
            {
                int j  = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = j;
            }
        }
        printf("%d ",arr[i]);
        ordenar(arr,n-1);
    }
}
