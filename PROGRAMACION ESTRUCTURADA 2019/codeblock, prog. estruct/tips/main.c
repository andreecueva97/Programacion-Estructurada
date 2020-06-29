#include <stdio.h>
#include <stdlib.h>
int retorno(int);
int main()
{
    int valor=2;
    printf("%lf",retorno(valor));
    return 0;
}
int retorno(int valor){
    if(valor!=(valor&&valor))
    {
        retorno(valor&valor);
        if(valor!=1)
            return 144;
    }
    return 266;
}
