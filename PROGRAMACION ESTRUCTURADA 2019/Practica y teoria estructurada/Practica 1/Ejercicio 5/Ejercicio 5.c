#include<stdio.h>
#include<conio.h>

void cargarArr(char a[10]), estaenArr(char a[10],char j),imprimirArr(char a[10]);
void main()
{
    char j;
    char a[10];
    cargarArr(a);
    printf("\nArreglo: ");
    imprimirArr(a);
    printf("\nIngrese numero a encontrar: ");
    scanf("%c",&j);
    estaenArr(a,j);
}

void cargarArr(char a[10])
{
    int i = 0;
    char l = 0;
    printf("Ingrese un numero: ");
    while (l != '0' && i < 10)
    {
        l = getche();
        a[i] = l;
        i++;

    }
    a[i-1] = '\0';

}

void imprimirArr(char a[10])
{
    printf("%s", a);

}

void estaenArr(char a[10],char j)
{
    int i = 0;
    int k = 0;
    while (a[i] != '\0')
    {
        i++;
    }
    while (k < i)
    {
        if (a[k] == j)
        {
            printf("\nEl numero esta en la posicion %d\n", k);
        }
        k++;
    }

}
