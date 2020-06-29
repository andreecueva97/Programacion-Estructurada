#include<stdio.h>
#include <stdlib.h>

void cargarMat(int mat[10][10],int x, int y), imprimirMat(int mat[10][10],int x, int y),imprimirMatOrden(int mat[10][10],int x, int y,char caden[10]);

int main()
{
    int mat[10][10],x,y;
    char cadena[10];
    printf("Ingrese N de filas: ");
    scanf("%d", &x);
    printf("Ingrese N de columnas: ");
    scanf("%d", &y);
    cargarMat(mat, x, y);
    printf("\nMatriz original: \n");
    imprimirMat(mat, x, y);
    printf("\nMatriz ordenada: \n");
    imprimirMatOrden(mat, x, y,cadena);
    return 0;
}

void cargarMat(int mat[10][10],int x, int y)
{
    int i = 0, j = 0;

    for(i = 0 ; i < x ; i++)
    {
        for(j = 0 ; j < y ; j++)
        {
            printf("Ingrese letra: ");
            scanf("%s",&mat[i][j]);
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
          printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
}

void imprimirMatOrden(int mat[10][10],int x, int y, char caden[10]) //No funca.
{
    int i, j, k = 1, aux;
    int lcad = x*y;
    caden[lcad];
    for(i = 0; i < lcad; i++)
    {
        for (j = 0; j < lcad; j++)
        {
            if (caden[j]<caden[j+1])
            {
                aux = caden[j];
                caden[j] = caden[j+1];
                caden[j+1] = aux; //cadena[d,c,b,a]
            }
        }
    }
    while(k < lcad)
    {
        for(i = 0; i < x; i++)
        {
            for(j = 0; j < y; j++)
            {
                mat[i][j] = caden[k];
                printf("%c ",mat[i][j]);
                k++;
            }
        printf("\n");
        }
        k++;
    }
}

