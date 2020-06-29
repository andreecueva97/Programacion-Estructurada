#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct texto
{
    char* txt;
    int lon;
}t_texto;

t_texto* cargartexto(void);

int main()
{
    t_texto* texto = NULL;

    texto = cargartexto();

    printf("\n");

    printf("Longitud: %d (incluye el /0)\n", texto->lon);
    printf("TEXTO: %s", texto->txt);

    return 0;
}

t_texto* cargartexto(void)
{
    t_texto* texto = NULL;
    char c;
    int i = 0;

    printf("Ingrese un texto, termine con Enter: ");
    c = getche();

    texto = (t_texto*) malloc(sizeof(t_texto));
    texto->txt = (char*) malloc(sizeof(char));

    while( c != '\r')
    {
        texto->txt = realloc(texto->txt, (1+i) * sizeof(char));
        (texto->txt)[i] = c;

        texto->lon = i + 1;
        c = getche();
        i ++;
    }

    (texto->txt) = realloc(texto->txt, (1+i) * sizeof(char));
    (texto->txt)[i] = '\0';
    texto->lon = i+1;

    return texto;
}






