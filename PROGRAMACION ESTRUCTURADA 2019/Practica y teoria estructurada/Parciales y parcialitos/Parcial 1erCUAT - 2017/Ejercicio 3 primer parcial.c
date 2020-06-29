#include <stdio.h>
#include <stdlib.h>

int sumaImpar(int n, int m);

int main()
{
    int n = 1, m = 7;
    printf("Numero 1: %d   Numero 2: %d", n, m);
    printf("\nResultado de ejecucion: %d", sumaImpar(n, m));
    return 0;
}

// FUNCION PARA SUMAR LOS NUMERO IMPARES ENTRE LOS DOS NUMEROS DE ENTRADA
int sumaImpar(int n, int m){
    if(n <= m){
        if(n % 2 != 0){
            return n + sumaImpar(n + 1, m);
        }
        else{
            return sumaImpar(n + 1, m);
        }
    }
    return 0;
}
