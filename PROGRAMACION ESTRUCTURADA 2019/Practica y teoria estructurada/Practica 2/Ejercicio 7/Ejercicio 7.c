#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define TAM 30

typedef struct {   char nombre[100];   int legajo, materias[30]; } t_alumno;
typedef struct {   char nombre[100];   int codigo; } t_materia;
typedef struct {   int legajo_alumno;   int cod_materia,nota; } t_nota;

int caralumnos(t_alumno al[TAM]);
int carmaterias(t_materia mat[TAM]);
void carnotas(t_alumno al[TAM],t_materia mat[TAM], int nom, int mate, t_nota nota[TAM]);

int main()
{
    int nom = 0,mate = 0;
    t_alumno al[TAM];
    t_materia mat[TAM];
    t_nota nota[TAM];
    nom = caralumnos(al);
    mate = carmaterias(mat);
    carnotas(al,mat,nom,mate,nota);
    return 0;
}

int caralumnos(t_alumno al[TAM]){
    FILE* arch;
    int i = 0, cont = 0;
    char l;
    arch = fopen("alumnos.txt", "w");
    printf("ingrese un legajo:");
    scanf("%d",&al[0].legajo);
    printf("ingrese un nombre: ");
    l = getche();
    while (l != '\r'){
        al[0].nombre[i]=l;
        i++;
        l = getche();
    }
    al[0].nombre[i] = '\0';
    while(al[cont].legajo != '\0'){
        fprintf(arch,"%d,%s\n",al[cont].legajo,al[cont].nombre);
        cont++;
        printf("\ningrese un legajo:");
        scanf("%d",&al[cont].legajo);
        if(al[cont].legajo != 0){
        printf("ingrese un nombre: ");
        int j = 0;
        l = getche();
        while (l != '\r'){
            al[cont].nombre[j]=l;
            j++;
            l = getche();
        }
        al[cont].nombre[j] = '\0';
        }
    }
    fclose(arch);
    return cont;
}

int carmaterias(t_materia mat[TAM]){
    FILE* arch;
    int i = 0, cont = 0;
    char l;
    arch = fopen("materias.txt", "w");
    printf("ingrese un codigo:");
    scanf("%d",&mat[0].codigo);
    printf("ingrese una materia: ");
    l = getche();
    while (l != '\r'){
        mat[0].nombre[i]=l;
        i++;
        l = getche();
    }
    mat[0].nombre[i] = '\0';
    while(mat[cont].codigo != '\0'){
        fprintf(arch,"%d,%s\n",mat[cont].codigo,mat[cont].nombre);
        cont++;
        printf("\ningrese un codigo:");
        scanf("%d",&mat[cont].codigo);
        if(mat[cont].codigo != 0){
        printf("ingrese una materia: ");
        int j = 0;
        l = getche();
        mat[cont].nombre[0] = l;
        while (l != '\r'){
            j++;
            mat[cont].nombre[j]=l;
            l = getche();
        }
        mat[cont].nombre[j] = '\0';
        }
    }
    fclose(arch);
    return cont;
}

void carnotas(t_alumno al[TAM],t_materia mat[TAM], int nom, int mate,t_nota nota[TAM]){
    int n,m,cont = 0;
    FILE* arch;
    arch = fopen("notas.txt​","r");
    for(n = 0;n <= nom;n++){
            for(m = 0; m <= mate; m++){
                printf("\ningrese la nota de %s para la materia %s:",al[n].nombre,mat[m].nombre);
                scanf("%d",&nota[cont].nota);
                fprintf(arch,"%d,%d,%d\n",al[n].legajo,mat[n].codigo,nota[cont].nota);
                cont++;
                }
    }

}
