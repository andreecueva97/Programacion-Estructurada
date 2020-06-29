#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct{
    char *txt;
    int longitud;
}t_texto;

char* cargar();

int main()
{
    FILE* arch;
    int cont = 0;
    t_texto a;
    a.txt = cargar();

    arch = fopen("frase.txt","w");
    while(*(a.txt + cont) != '\0'){
        cont++;
    }
    a.longitud = cont;
    fprintf(arch,"%s, %d", a.txt,a.longitud);
    free(a.txt);
    fclose(arch);
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
