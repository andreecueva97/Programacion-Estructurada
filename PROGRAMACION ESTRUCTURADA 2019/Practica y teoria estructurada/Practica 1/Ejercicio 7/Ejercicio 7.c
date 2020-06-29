#include<stdio.h>

void cargarMat(int mat[10][10],int x, int y), imprimirMat(int mat[10][10],int x, int y), promMat(int mat[10][10],int x, int y);

int main(void)
{
    int mat[10][10],x,y;
    printf("Ingrese cantidad de filas: ");
    scanf("%d", &x);
    printf("Ingrese cantidad de columnas: ");
    scanf("%d", &y);
    cargarMat(mat, x, y);
    printf("La matriz es:\n");
    imprimirMat(mat, x, y);
    promMat(mat, x, y);
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

void promMat(int mat[10][10],int x, int y)
{
    int i = 0, j = 0, prom = 0, promTot = 0;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            prom = prom + mat[i][j];
        }
    }
        promTot = prom/(x*y);
        printf("\nEl promedio de la matriz es: %d\n", promTot);
}
