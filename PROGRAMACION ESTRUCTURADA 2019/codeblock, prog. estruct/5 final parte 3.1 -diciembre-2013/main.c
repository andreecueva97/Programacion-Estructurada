#include <stdio.h>
#include <stdlib.h>
struct s{
    int id_habitante;
    char nombre[60];
    char sexo;
    int edad;
}typedef struct s habitante;
struct c{
    int id_localidad;
    char* nombre_localidad;
}typedef struct c localidad;
struct a{
    int id_localidad;
    int id_habitante;
}typedef struct a habitanteXlocalidad;
int fun1(char nombreloc, char sexo);
int main()
{
    printf("Hello world!\n");
    int x=fun1(nombreloc,sexo);
    printf("la cantidad de personas que viven son %d",x);
    return 0;
}
int fun1(char nombreloc,char sexo)
{
    habitante* datoshabitantes=NULL;char*arr;
    int r;
    localidad* localidades=NULL;
    habitanteXlocalidad* habitantesXlocalidades=NULL;
    FILE *arch;
    arch=fopen("habitantes.dat","rb");
    r=fread(arr,4,1,arch);//INT
    while(r!=EOF){
        datoshabitantes=malloc(sizeof(struct habitante));
        (*datoshabitantes)->id_habitante=r;
        fread(&(*datoshabitantes)->nombre,sizeof(char)*60,1,arch);
        i=0;
        while(*(arr+i)!='\n'){

            /////////////
        }
        r=fread(datoshabitantes,sizeof(struct s),1,arch);
    }
}
