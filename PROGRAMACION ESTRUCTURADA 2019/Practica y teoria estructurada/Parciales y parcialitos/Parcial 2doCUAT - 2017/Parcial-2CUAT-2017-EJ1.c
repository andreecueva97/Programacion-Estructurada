#include <stdio.h>
#include <stdlib.h>

char* subcadena(char* , int ini, int cant);

int main()
{
    char texto[100] = "Todo debe simplificarse";

    printf("1:%s\n",subcadena(texto,0,2));
    printf("2:%s\n",subcadena(texto,3,4));
    printf("3:%s\n",subcadena(texto,5,0));
    printf("4:%s\n",subcadena(texto,19,4));
    printf("5:%s\n",subcadena(texto,19,20));

    return 0;
}

char* subcadena(char* cad, int ini, int cant)
{
    char* resultado = NULL;
    int i;

    resultado = (char*) malloc(sizeof(char));

    if(cad == NULL || resultado==NULL){return NULL;}

    for(i = 0; (cad[ini] != '\0') && (i < cant); i++)
    {
        if(cant > 0)
        {
            resultado = realloc(resultado, (1+i) * sizeof(char));
            resultado[i] = cad[ini];
            ini ++;
        }
        else
        {
            resultado[i]= ' ';
        }
    }

    resultado = realloc(resultado,(1+i) * sizeof(char));
    resultado[i] = '\0';

    return (resultado);
}
