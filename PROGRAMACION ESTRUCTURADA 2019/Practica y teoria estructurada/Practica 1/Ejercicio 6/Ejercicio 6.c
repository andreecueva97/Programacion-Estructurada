#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

void cargarArr(char m[30]), imprimirArr(char m[30]), normalizar(char m[30]);

int main()
{
    char arr[30];
    cargarArr(arr);
    printf("\n\n-Frase original: ");
    imprimirArr(arr);
    normalizar(arr);
    return 0;
}

void cargarArr(char m[30])
{
    int i = 0;
    char l = 0;
    printf("-Ingrese una frase: ");
    while (l != '0')
    {
        l = getche();
        m[i] = l;
        i++;

    }
    m[i-1] = '\0';

}

void imprimirArr(char m[30])
{
    printf("%s", m);

}

void normalizar(char m[30])
{
    int i = 0, j , n = 0;
    if (m[0] > 'a', m[0] < 'z')
    {
    m[0] = toupper(m[0]);
    }


    while (m[i] != '\0')
    {
        i++;
    }

    while (n < i)
    {
        if(m[n] == ' ' && (m[n+1] == ' ' || m[n-1] == ' '))
        {
            for(j = n ; j < i ; j++)
            {
                m[j] = m[j+1];
            }
            i--;
        }
        else
        {
            n++;
        }
    }
    if (m[i] == '.')
    {
        printf("\n\n-Frase nueva: %s\n",m);
    }
    else
    {
        printf("\n\n-Frase nueva: %s.\n",m);
    }
}
