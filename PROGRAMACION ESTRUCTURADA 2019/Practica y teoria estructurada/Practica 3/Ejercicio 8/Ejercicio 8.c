#include <stdio.h>
#include <stdlib.h>

char* leer();

int main()
{
    char* frase = NULL;
    frase = leer();
    printf("El contenido de frase es: %s",frase);
    free(frase);
    return 0;
}

char* leer(){
    FILE* arch;
    arch = fopen("frase.txt","r");
    char *fra;
    char l;
    int c = 0;
    fra = malloc(sizeof(char));
    l = fgetc(arch);
    while(l != EOF && l != '.'){
        *(fra + c) = l;
        c++;
        fra = realloc(fra,sizeof(char) * (c+1));
        l = getc(arch);
    }
    return fra;
    fclose(arch);
}
