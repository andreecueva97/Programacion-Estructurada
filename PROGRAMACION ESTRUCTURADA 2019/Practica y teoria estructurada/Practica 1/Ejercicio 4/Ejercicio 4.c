#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void cargarArr(char m[10]), imprimirArr(char m[10]), invertirArr(char m[10]);

int main()
{
    char arr[10];
    cargarArr(arr);
    printf("\nLista de numeros: ");
    imprimirArr(arr);
    invertirArr(arr);
    return 0;
}

void cargarArr(char m[10])
{
    char l = 0;
    int i = 0;
    printf("Ingrese numero:");
    while (l != '0'){
        l = getche();
        m[i] = l;
        i++;
    }
    m[i-1] = NULL;

}

void imprimirArr(char m[10])
{
    printf("%s", m);

}

void invertirArr(char m[10])
{
    int i = 0;
    int k = 0;
    while (m[k] != '\0')
    {
        k++;
    }
    printf("\nNumero invertido: ");
    while (k > 0)
    {
        printf("%c", m[k-1]);
        k--;
    }
}
