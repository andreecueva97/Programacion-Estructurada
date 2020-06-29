#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void escribirArch();

int main()
{
    escribirArch();
    return 0;
}


void escribirArch()
{
    int dni,i = 0, f=0;
    char nombre[20], pais[15];
    FILE* arch;
    arch = fopen("personas.txt","w");
    printf("Cuantas personas desea ingresar? ");
    scanf("%d",&f);

    while (i < f)
    {
        printf("\nPersona %d\n", i+1);
        printf("\nIngrese DNI: ");
        scanf("%d", &dni);
        printf("Ingrese nombre: ");
        scanf("%s", &nombre);
        printf("Ingrese pais: ");
        scanf("%s", &pais);
        fprintf(arch,"%d,%s,%s ",dni,nombre,pais);
        i++;
     }
     fclose(arch);
}
