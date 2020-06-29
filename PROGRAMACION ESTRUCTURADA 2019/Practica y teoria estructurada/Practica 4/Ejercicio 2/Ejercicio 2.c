#include <stdio.h>
#include <stdlib.h>

int division(int a,int b);

int main()
{
    int cont = 0;
    printf("Division : %d", division(14,4));
    return 0;
}

int division(int a,int b)
{
    if (a > 0)
    {
        return 1 + division(a-b,b);
    }

    return 0;
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
