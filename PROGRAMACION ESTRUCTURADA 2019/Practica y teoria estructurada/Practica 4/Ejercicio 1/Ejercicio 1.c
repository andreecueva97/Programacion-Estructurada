#include <stdio.h>
#include <stdlib.h>

int producto(int a,int b);

int main()
{
    printf("Producto : %d", producto(3,4));
    return 0;
}

int producto(int a,int b)
{
    if (a != 0)
    {
        return b + producto(a-1,b);
    }
    return 0;
}
