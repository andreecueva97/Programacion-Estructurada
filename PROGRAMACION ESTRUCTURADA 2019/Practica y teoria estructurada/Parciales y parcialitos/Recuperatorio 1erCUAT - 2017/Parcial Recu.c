#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define T 3


typedef struct Persona{

    int estatura;
    char* apellido;

}Persona_T;

struct s_ciudad{
int cod;
char* nombre;
unsigned char cod_pai;
};
typedef struct s_ciudad t_ciudad;
t_ciudad* filtrar(t_ciudad arr[T], char cod_pai);
void ordenar(t_ciudad * Arreglo);

void ordenar(t_ciudad* Arreglo){
    int i,j;
    t_ciudad Aux;
    for(i=0;Arreglo[i].cod!=0;i++){
            for(j=i+1; Arreglo[j].cod!=0; j++){
                printf("\nComparo Strings");
                if(strcmp(Arreglo[j].nombre,Arreglo[i].nombre)<0){
                    printf("\nEl %s va antes que %s", Arreglo[j].nombre,Arreglo[i].nombre);
                    Aux = Arreglo[j];
                    Arreglo[j] = Arreglo[i];
                    Arreglo[i] = Aux;
                   }
            }
    }

}

t_ciudad* filtrar(t_ciudad arr[T], char cod_pai){

    int tam = 1, cont = 0, cont_nombre=0;
    t_ciudad* Arreglo = (t_ciudad*)malloc(sizeof(t_ciudad)*(tam+1));
    printf("\nGenerando arreglo dinamico...");

    while(cont<T){
            printf("\nEntre al while por vez N: %d, T=%d", cont+1,T);
            if (arr[cont].cod_pai == cod_pai){
                printf("\nEl arreglo: %s contiene el codigo: %c", arr[cont].nombre,arr[cont].cod_pai);
                Arreglo[cont_nombre] = arr[cont];
                printf("\nArreglo actual es: %s", Arreglo[cont_nombre].nombre);
                tam++;
                cont_nombre++;
                printf("\nTam incrementado");
                Arreglo = realloc(Arreglo, sizeof(t_ciudad)*(tam+1));
                printf("\nReallocado");
            }
            cont++;
            printf("\nCont: %d", cont);
    }

    Arreglo[cont_nombre].cod = 0;
    printf("\nArreglo[%d] cod %d", cont_nombre,Arreglo[2].cod);
    ordenar(Arreglo);
    return Arreglo;

}

int valor(int x){
    int MASK1 = 32640;
    if ((x & MASK1)!=0){
        return -1;
    }
    return 1;
}



//Ej1
/*int main(){
    int i;
    printf("\nCargando Arreglo estatico...");
    t_ciudad arr[T];
    arr[0].cod = 1;
    arr[1].cod = 2;
    arr[2].cod = 3;
    arr[0].nombre = "Gaspar\0";
    arr[1].nombre = "Juan\0";
    arr[2].nombre = "Agustin\0";
    arr[0].cod_pai = 'a';
    arr[1].cod_pai = 'b';
    arr[2].cod_pai = 'a';
    printf("\nCargado!\nCargando Filtrado...");
    t_ciudad* Arreglo = filtrar(arr, 'a');


        for(i=0; Arreglo[i].cod != 0; i++)
    {
        printf("\n%c, %d, %s \n",Arreglo[i].cod_pai,Arreglo[i].cod,Arreglo[i].nombre);
    }

    return 0;




}*/

//EJ2
Persona_T* cargar_personas(int * Estaturas, char** Apellidos){
    int cont = 0, cont_per = 0;
    Persona_T* Personas = (Persona_T*)malloc(sizeof(Persona_T)*(cont_per+1));
    printf("\nMalloque");
    while(Estaturas[cont]!=0 ){
            printf("\nEntre al while | cont: %d | cont_per: %d ", cont, cont_per);
            if(valor(Estaturas[cont])==1){
                Personas[cont_per].estatura = Estaturas[cont];
                printf("\nPor hacer copy %s", Apellidos[cont]);
                Personas[cont_per].apellido = Apellidos[cont];
                printf("\nLo logreee copy");
                cont_per++;
                Personas = realloc(Personas, sizeof(Personas)*(cont_per+1));
            }
            cont++;
    }
    return Personas;
}

int main(){
    int i;
    int * Estaturas = (int*)malloc(sizeof(int)*6);
    Estaturas[0] = 1;
    Estaturas[1] = 2;
    Estaturas[2] = 3;
    Estaturas[3] = 4;
    Estaturas[4] = 0;
    char** Apellidos = malloc(sizeof(char*)*6);
    for(i=0; i<6; i++){
        Apellidos[i] = malloc(100);
    }
    Apellidos[0] = "Gaspar\0";
    Apellidos[1] = "Pablo\0";
    Apellidos[2] = "Joaquin\0";
    Apellidos[3] = "Pepe\0";
    Apellidos[4] = "Juan\0";

    cargar_personas(Estaturas, Apellidos);
    return 0;
}
