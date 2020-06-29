#include <stdio.h>
#include <stdlib.h>

#define F 30
#define C 30

int cargarMat(char mat[F][C]);
void imprimirArchivo();

int main(){
	char mat[F][C] = {{0}};
    imprimirArchivo();
}


void imprimirArchivo()
{
    FILE *arch;
    int dni, i=0;
    char nombre[30], pais[30], caracter;

    arch=fopen("personas.txt", "r");

    if(arch != NULL)
    {
        printf("Documento  Nombre   Pais\n");
        printf("------------------------------\n");
        while(!feof(arch))
        {
            dni = 0;
            i = 0;
            fscanf(arch,"%d,",&dni);

            for(caracter = fgetc(arch); caracter != ',' && !feof(arch); caracter = fgetc(arch))
            {
                nombre[i] = caracter;
                i++;
            }
            nombre[i] = '\0';

            if(!feof(arch))
            {
                fscanf(arch,"%s\n",&pais);
            }
            printf("%-10d %-8s %s\n",dni,nombre,pais);
        }
    }
}


//int cargarMat(char mat[F][C]){
//
//    int  c=0;
//
//    FILE* arch;
//    arch=fopen("personas.txt","r");
//
//    if(arch==NULL)
//        return -1;
//
//    c=fgetc(arch);
//    printf("Documento  Nombre   Pais\n");
//    printf("------------------------------\n");
//    while (c!= EOF)
//    {
//        printf("%c", c);
//        c=fgetc(arch);
//    }
//    fclose(arch);
//
//    return 0;
//
//}
