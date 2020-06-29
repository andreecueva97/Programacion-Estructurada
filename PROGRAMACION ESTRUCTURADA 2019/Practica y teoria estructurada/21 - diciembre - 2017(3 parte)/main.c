#include <stdio.h>
#include <stdlib.h>/**
struct alumno{
    int registro;char*nombre;char*ap;
};
struct s_nodo{
    struct alumno alumno;
    struct s_nodo* izq;
    struct s_nodo*der;
};typedef struct s_nodo* t_nodo;
void agregar(t_nodo* arbol,struct alumno a);
int esta(t_nodo arbol,struct alumno a);
void unificar(char* am,char* bm){
    t_nodo* arbol;
    struct alumno alumno;
    //printf("%s",am);cuidado
    FILE* arch=fopen(am,"r");
    int regis=0,c,i=0;
    fscanf(arch,"%d,",&regis);
    while(!feof(arch)){
        alumno.registro=regis;
        alumno.nombre=malloc(sizeof(char));
        c=fgetc(arch);
        i=0;
        (alumno.nombre)[i]=c;
        while(c!=','){
            alumno.nombre=realloc(alumno.nombre,sizeof(char)*(i+2));
            c=fgetc(arch);
            i++;
            (alumno.nombre)[i]=c;

        }
        (alumno.nombre)[i]='\0';

        //apellido
        alumno.ap=malloc(sizeof(char));
        c=fgetc(arch);
        i=0;
        (alumno.ap)[i]=c;
        while(c!=','){
            alumno.ap=realloc(alumno.ap,sizeof(char)*(i+2));
            c=fgetc(arch);
            i++;
            (alumno.ap)[i]=c;

        }
        (alumno.ap)[i]='\0';
        fscanf(arch,"%d,",&regis);
        agregar(arbol,alumno);//arbol sin &
        free(alumno.ap);free(alumno.nombre);
    }
    //lo mismo con b
}
void agregar(t_nodo* arbol,struct alumno a){
    if(*arbol==NULL){
        arbol=malloc(sizeof(struct s_nodo));
        (*arbol)->alumno=a;
        (*arbol)->izq=NULL;
        (*arbol)->der=NULL;
    }
    else{
        if(esta(arbol,a)==0){
            if(a.registro<((*arbol)->alumno).registro){
                agregar(&(*arbol)->izq,a);
            }
            else{
                agregar(&(*arbol)->der,a);
            }
        }
    }

}
**/
/**                3.2     si FUNCIONA **/
/**
struct s_nota{
    int valor;
    struct s_nota*sig;
};typedef struct s_nota* t_nota;
struct s_alu{
    char*apellido;
    t_nota lstnota;
    struct s_alu*sig;
};typedef struct s_alu* t_alu;
void insertar(t_alu* a,double,char*);
void agregar(t_alu* ordenada,t_alu alumno);
int sumNotas(t_nota notas);
int cantidadNotas(t_nota notas);
void listado(t_alu alumno)
    t_alu *ordenada=NULL;
    agregar(ordenada,alumno);
    //PRINTF
}
void agregar(t_alu* ordenada,t_alu alumno){
    double prom;
    if(alumno!=NULL){
        prom=sumNotas(alumno->lstnota)/cantidadNotas(alumno->lstnota);
        insertar(ordenada,prom,alumno->apellido);
        agregar(ordenada,(alumno->sig));
    }
}
int sumNotas(t_nota notas){
    if(notas!=NULL){
        return notas->valor+sumNotas(notas+1);
    }
    else
        return 0;
}
int cantidadNotas(t_nota notas){
    if(notas!=NULL){
        return 1+sumNotas(notas+1);
    }
    else
        return 0;
}
void insertar(t_alu* a,double b,char*c)
{
    t_alu aux = NULL;
    if ((*a) == NULL || b < ((*a)->lstnota)->valor)
    {
    aux = (t_alu) malloc(sizeof(struct s_alu));
    aux->apellido = c;
    (aux->lstnota)->valor = b;
    aux->sig = *a;
        *a = aux;
    }
    else
    {
        insertar( & (*a)->sig, b,c);
    }
}
**//**
int main(){
    printf("%d",retorno(5));
    return 0;
}
int retorno(int valor){
    printf("%d",valor&&valor);
    printf("\n%d",valor&valor);
    if(valor!=(valor&&valor)){//rompe con 2 , cualquier numero es true, menos 0;
        retorno(valor&valor);
        if(valor!=1)
            return 144;

    }
    return 266;
}**//**
int main(){
    int a[]={1,3,5,7,9,0};
    int*uno=NULL,dos=0;
    uno=a;

    dos=*(uno+*uno);
    printf("%d",dos);
    return 0;
}**//**
int main(){
    unsigned char a;
    a=~((~0)<<(1<<2));
    printf("%u",a);
    //00000100 4
    //11110000
    //00001111
}**//**
int main(){
    int a=1000000000000000000000000000000000;
    int b=1;
    if((a<<b)>a){
        printf("rojo");
    }
    else{
        printf("negro");
    }
}**/
