#include <stdio.h>
#include <stdlib.h>

int maximo(int arr[5], int a, int max);

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
    printf("Numero maximo: \n");
    printf("%d",maximo(arr,a-1,0));
    return 0;
}

int maximo(int arr[5], int a, int max)
{
    if (a != 0)
    {
        if (arr[a] > max)
        {
            max = arr[a];
        }
        return maximo(arr,a-1,max);

    }
    return max;
}
