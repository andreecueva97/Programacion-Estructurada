#include <stdio.h>
#include <stdlib.h>
struct sven{
    int c;
    char nom[30];
    int obj;
    double sueldo;
};typedef struct sven t_ven;
struct snodo{
    t_ven a;
    struct snodo*izq;
    struct snodo*der;
};typedef struct snodo* t_nodo;

void cargarArbolVendedores(t_nodo*arbol,FILE*fVende);
void cargar(t_nodo* arbol,t_ven a);
int main()
{
    t_nodo arbol;
    FILE*vende;
    vende=fopen("vendedores.txt","rb");
    printf("Hello world!\n");
    cargarArbolVendedores(&arbol,vende);
    return 0;
}
void cargarArbolVendedores(t_nodo*arbol,FILE*fVende)
{
    t_ven aux;
    int r,n,c,i;r=fscanf(fVende,"%d,",&n);double k;
    while(r!=EOF){/**!feof(fVende)**/
        aux.c=n;
        c=fgetc(fVende);
        i=0;
        while(c!=','){
            (aux.nom)[i]=c;
            c=fgetc(fVende);
            i++;
        }
        ((aux).nom)[i]='\0';
        r=fscanf(fVende,"%d,",&n);
        aux.obj=n;
        r=fscanf(fVende,"%lf\n",&k);
        aux.sueldo=k;
        r=fscanf(fVende,"%d,",&n);
        cargar(arbol,aux);
    }
}

void cargar(t_nodo*arbol,t_ven a){
    if(*arbol==NULL){
        arbol=malloc(sizeof(t_nodo));
        (*arbol)->a=a;
        (*arbol)->izq=NULL;
        (*arbol)->der=NULL;
    }
    else{
        if(((*arbol)->a).c > a.c)
            cargar(&(*arbol)->der,a);
        else
            cargar(&(*arbol)->izq,a);
    }
}
