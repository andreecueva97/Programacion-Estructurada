#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 5
typedef struct{
    int fila;
    int columna;
} s_pos_mat;

s_pos_mat * posiciones_vacias(char matriz[N][M]);

int main()
{
    char matriz[N][M];
    posiciones_vacias(matriz);
    return 0;
}

// FUNCION PARA DEVOLVER POSICIONES VACIAS
s_pos_mat* posiciones_vacias(char matriz[N][M]){
    s_pos_mat arr = NULL;
    arr = malloc(sizeof(s_pos_mat));
    int i = 0, j = 0;
    for(i=0;i<N;i++){
        for(i=0;i<M;i++){
            if(matriz[i][j] == '-'){
                (arr + i)->fila = i;
                (arr + i)->columna = j;
                arr = realloc(arr, sizeof(s_pos_mat) * (i + 1))
            }
        }
    }
    return 0;
}
