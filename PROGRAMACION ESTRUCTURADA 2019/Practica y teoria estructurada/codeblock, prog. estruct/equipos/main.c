#include <stdio.h>
#include <stdlib.h>
#define F 10
#define C 10

void cargarMatTexDeArch(char mat[F][C]);
void imprimirMat(char mat[F][C]);

int main()
{
    char mat[F][C];
    cargarMatTexDeArch(mat);
    imprimirMat(mat);
    return 0;
}

void cargarMatTexDeArch(char mat[F][C]){
    char c;
    int i=0,n=0;
    FILE*  arch;
    arch=fopen("equipos.txt","r");
    c=fgetc(arch);
    while (c != EOF){
        while (c != '\n'){
            mat[i][n]=c;
            c=fgetc(arch);
            n++;
        }
        mat[i][n]='\0';
        i++;
        c=fgetc(arch);
    }
    mat[i][0]='\0';
    fclose(arch);
}

void imprimirMat(char mat[F][C])
{
    int i=0,n=0;
    while (mat[i][0]!='\0'){
        while (c != '\0'){
            printf("%c",mat[i][n]);
            n++;
        }
        printf("\n");
        i++;
    }
}
