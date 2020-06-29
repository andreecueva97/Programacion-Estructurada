#include<stdio.h>

void cargarMat(int mat[10][10],int x, int y), imprimirMat(int mat[10][10],int x, int y);

int main()
{
    int mat[10][10],x,y;
    printf("Ingrese N de filas: ");
    scanf("%d", &x);
    printf("Ingrese N de columnas (Deben ser iguales a las filas): ");
    scanf("%d", &y);
    while (y != x)
    {
        printf("Ingrese N de columnas (Deben ser iguales a las filas): ");
        scanf("%d", &y);
    }
    cargarMat(mat, x, y);
    printf("\nMatriz original: \n");
    imprimirMat(mat, x, y);
    printf("\nMatriz transpuesta: \n");
    imprimirMatTrans(mat, x, y);
    return 0;
}

void cargarMat(int mat[10][10],int x, int y)
{
    int i = 0, j = 0;

    for(i = 0 ; i < x ; i++)
    {
        for(j = 0 ; j < y ; j++)
        {
            printf("Ingrese numero: ");
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\n");

}

void imprimirMat(int mat[10][10],int x, int y)
{
    int i = 0, j = 0;

    for(i = 0 ; i < x ; i++)
    {
        for(j = 0 ; j < y ; j++)
        {
          printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}


void imprimirMatTrans(int mat[10][10],int x, int y)
{
    int i = 0, j = 0;

    for(i = 0 ; i < x ; i++)
    {
        for(j = 0 ; j < y ; j++)
        {
          printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
}
