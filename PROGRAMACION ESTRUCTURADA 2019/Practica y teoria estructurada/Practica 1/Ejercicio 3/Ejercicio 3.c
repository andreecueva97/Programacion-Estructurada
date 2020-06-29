#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void leer(char arr[100]), reemplazar(char p[100],char l, char r);

int main()
{
    char letra = 'm', reempl = 'j';
    char arr[100];
    leer(arr);
    printf("Ingrese caracter a reemplazar:");
    letra = getche();
    printf("\nIngrese de reemplazo: ");
    reempl = getche();
    printf("\nFrase reemplazada: ");
    reemplazar(arr,letra,reempl);
    return 0;
}

void leer(char m[100])
{
    int i = 0;
    char l = '0';
    printf("Ingrese frase: ");
    while(l != '\r'){
        l = getche();
        m[i] = l;
        i++;
    }
    m[i-1] = '\0';
}

void reemplazar(char p[100], char l, char r)
{
    int i = 0;
    int k = 0;
    while (p[k] != '\0')
    {
        k++;
    }

    for (i = 0; i<k; i++)
    {
        if (p[i] == l)
        {
            p[i] = r;
        }

    printf("%c", p[i]);
    }
}
