#include <stdio.h>
#include <stdlib.h>

int division(int a,int b),resto(int a,int b);

int main()
{
    int cont = 0;
    printf("Division : %d", division(12,4));
    printf("\nResto : %d", resto(12,4));
    return 0;
}

int division(int a,int b)
{
    if (a != 0)
    {
        return 1 + division(a-b,b);
    }

    return 0;
}

int resto(int a,int b)
{
    if (a >= b)
    {
        return resto(a-b,b);
    }
    return a;
}

/*
int division(int a,int b,int cont)
{
    if (a != 0 && a > 0)
    {
        a = a - b;
        division(a,b,(cont + 1));
    }

    else
    {
        return cont;
    }
}
*/
