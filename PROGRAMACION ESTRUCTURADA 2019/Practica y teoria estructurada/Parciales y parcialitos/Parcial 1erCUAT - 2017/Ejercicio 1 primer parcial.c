#include <stdio.h>
#include <stdlib.h>
#define T 99999
#define N 5
#define M 5
void reconstruirMatriz(int* backup, char matriz[N][M]);

int main()
{
    int backup[T];
    char matriz[N][M];
    reconstruirMatriz(backup, matriz);
    return 0;
}

// FUNCION RECONSTRUIR MATRIZ
void reconstruirMatriz(int* backup, char matriz[N][M]){
    int i = 0;
    int fila = 0; columna = 0;
    char caracter = 'c';
    while(*(backup + i) != 0){
        columna = *(backup + i) & 255;
        fila = (*(backup + i) >> 8) & 255;
        caracter = (*(backup + i) >> 16) & 255;
        matriz[fila][columna] = caracter;
        i++;
    }
}