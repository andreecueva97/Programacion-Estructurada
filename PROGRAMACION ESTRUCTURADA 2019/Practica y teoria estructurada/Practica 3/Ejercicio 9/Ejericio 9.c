#include <stdio.h>
#include <stdlib.h>

char * subcadena (char * p, unsigned int i, unsigned int n);

int main()
{
    FILE *arch;
    arch = fopen("frases.txt","r");
    char *fra;
    char u;
    char *ret = NULL;
    int cont = 0;
    fra = malloc(sizeof(char));
    u = fgetc(arch);
    while(u != EOF && u!= '\n'){
        *(fra + cont) = u;
        cont++;
        fra = realloc(fra,sizeof(char)*(cont + 1));
        u = fgetc(arch);
    }
    *(fra + (cont))= '\0';
    printf("%s\n",fra);
    ret = subcadena(fra, 8, 9);
    printf("la frase es: %s",ret);
    return 0;
}

char * subcadena (char *p, unsigned int i, unsigned int n){
    char *r;
    int cont = 0;
    r = malloc(sizeof(char));
    while (cont < n){
        *(r + cont) = *(p + (i+cont));
        cont++;
        r = realloc(r,sizeof(char)*(cont + 1));
    }
    return r;
}
