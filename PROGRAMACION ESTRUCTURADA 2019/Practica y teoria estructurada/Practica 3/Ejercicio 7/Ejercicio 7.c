#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char* cargar();

int main()
{
    FILE* arch;
    arch = fopen("frase.txt","w");
    char* frase = NULL;
    frase = cargar();
    fprintf(arch,"%s",frase);
    free(frase);
    fclose(arch);
    return 0;
}

char* cargar(){
    printf("ingrese frase: ");
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
