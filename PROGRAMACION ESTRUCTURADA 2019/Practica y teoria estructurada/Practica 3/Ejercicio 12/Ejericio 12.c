#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct{
    char * txt;
    unsigned int longitud;
}t_texto;

char* cargar();

int main()
{
    char *frase = NULL;
    frase = cargar();
    t_texto *a;
    /*a = malloc(sizeof(char));
    while (frase != NULL)
    {
        (*a).txt = frase;               NO FUNCIONA!!
        frase = cargar();

    }*/
    (*a).txt = frase;
    printf("\n%s", (*a).txt);
    return 0;

}

char* cargar(){
    printf("Ingrese frase: ");
    char *u;
    char  l;
    int i = 0;
    u = malloc(sizeof(char));
    l = getche();
    while(l != '\r'){
        *(u + i) = l;
        i++;
        u = realloc(u,sizeof(char)*(i + 1));
        l = getche();
    }
    *(u + i) = '\0';
    return u;
}
