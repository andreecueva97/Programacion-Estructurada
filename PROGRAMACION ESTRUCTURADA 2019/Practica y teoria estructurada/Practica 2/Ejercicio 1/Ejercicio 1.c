#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void cargarMat(char mat[10][10], int x, int y, char z, int u, int l, char k),imprimirMat(char mat[10][10], int x, int y, char z, int u, int l, char k);

int main()
{
    int x,y,u,l;
    char z,k;
    printf("Ingrese primer punto: \n");
    printf("Ingrese posicion en X: ");
    scanf("%d",&x);
    while (x > 9)
    {
        printf("Ingrese posicion en X menor a 10: ");
        scanf("%d",&x);
    }
    printf("Ingrese posicion en Y: ");
    scanf("%d",&y);
    while (y > 9)
    {
        printf("Ingrese posicion en Y menor a 10: ");
        scanf("%d",&y);
    }
    printf("Ingrese informacion a guardar: ");
    z = getche();
    printf("\n\nIngrese segundo punto: \n");
    printf("Ingrese posicion en X: ");
    scanf("%d",&u);
    while (u > 9)
    {
        printf("Ingrese posicion en X menor a 10: ");
        scanf("%d",&u);
    }
    printf("Ingrese posicion en Y: ");
    scanf("%d",&l);
    while (l > 9)
    {
        printf("Ingrese posicion en Y menor a 10: ");
        scanf("%d",&l);
    }
    printf("Ingrese informacion a guardar: ");
    k = getche();
    char mat[10][10];
    cargarMat(mat, x, y, z, u ,l ,k);
    imprimirMat(mat,x,y,z,u,l,k);
    return 0;
}

void cargarMat(char mat[10][10], int x, int y, char z, int u, int l, char k)
{
    printf("\n");
    printf("\n");
    int i = 1, j = 1;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if ((i == y) && (j == x))
            {
                mat[i][j] = z;
            }
            else if ((i == l) && (j == u))
            {
                mat[i][j] = k;
            }
            else
            {
                mat[i][j] = '-';
            }
        }
    }
}

void imprimirMat(char mat[10][10], int x, int y, char z, int u, int l, char k)
{
    double pnt1 = sqrt((pow(x,2)) + (pow(y,2)));
    double pnt2 = sqrt((pow(u,2)) + (pow(l,2)));

    int i = 0, j = 0;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            printf("  %c ",mat[i][j]);
        }
        printf("\n");
    }
    if (pnt1 < pnt2)
    {
        printf("\nEl punto que contiene '%c' esta mas cerca del (0;0)\n", z);
    }
    else if (pnt2 < pnt1)
    {
        printf("\nEl punto que contiene %c esta mas cerca del (0;0)\n", k);
    }
    else
    {
        printf("\nAmbos puntos son iguales\n");
    }
}

