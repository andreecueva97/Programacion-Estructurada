#include <stdio.h>
#include <stdlib.h>
struct com
{
    int nro_registro;
    char* nombre;
    char* apellido;
}
typedef struct com comision;
void unificar(*char,*char);
void nuevo(comision*am,comision*bm);
int main()
{
    char*am,bm;
    *am="comisionAM.txt";*bm="comisionBM.txt";
    printf("3 PARTE FINAL 21 DICIEMBRE 2017\n");
    return 0;

}

void unificar(*char a,*char b)
{
    comision* am;
    comision* bm;

    FILE* arch1=fopen(*a,"r");
    FILE* arch2=fopen(*b,"r");
    contenido(am,arch1);
    contenido(bm,arch2);
    nuevo(am,bm);
}
void contenido(comision*am,FILE*arch){
    am=malloc(sizeof(typedef struct com));
    int nro,r,i=0,e;char c="";
    char*nombre,apellido;
    r=fscanf(arch,"%d,",&num);
    while(r!=EOF){
        *(am+i).nro_registo=num;
        c=fgetc(arch);
        e=0;
        nombre=malloc(sizeof(char));
        while(c!=','){
            *(nombre+i)=c;
            e++;
            nombre=realloc(nombre,sizeof(char)*(e+2));
            c=fgetc(arch);
        }
        *(nombre+i)='\0';
        (am+i).apellido=apellido;
        c=fgetc(arch);
        e=0;
        apellido=malloc(sizeof(char));
        while(c!=','){
            *(apellido+i)=c;
            e++;
            apellido=realloc(apellido,sizeof(char)*(e+2));
            c=fgetc(arch);
        }
        *(apellido+i)='\0';
        (am+i).apellido=apellido;

        r=fscanf(arch,"%d,",&num);

        i++;
        am=realloc(am,sizeof(typedef struct com)*(i+2));

    }
    *(arr+i).nro_registro=0;
}
void nuevo(comision*am,comision*bm)
{
    int i,j,esta=0;
    FILE *archc=fopen("nuevo.txt","w");
    for(i=0;*(am+).nro_registro!=0:i++){
        esta=0; /**falso**/
        fwrite(archc,"");
        for(j=0;*(bm+).nro_registro!=0:j++){
            if(*(bm+).nro_registro==*(am+).nro_registro){
                esta=1;/**verdadero**/
            }
        }
        if (esta==0)
            fwrite(archc,"");
    }

}
