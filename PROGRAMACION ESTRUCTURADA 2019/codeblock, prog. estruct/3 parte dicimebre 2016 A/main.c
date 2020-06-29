#include <stdio.h>
#include <stdlib.h>
struct s_nodo_bin
{
char valor[4];
struct s_nodo_bin* izq;
struct s_nodo_bin* der;
};
typedef struct s_nodo_bin* t_nodo_bin;
void agregar(t_nodo_bin* arbol, int valor);
int cargarArbolVendedores(t_nodo_bin* arbol,FILE* fVende);
void ordenarArborl(t_nodo_bin arboln);
int main()
{
    printf("Hello world!\n");
    FILE* arch;
    arch=fopen("vendedores.txt","r");
    t_nodo_bin* arboln;
    cargarArbolVendedores(arboln,arch);
    ordenarArborl(arboln);
    fclose(arch);
    return 0;
}
void agregar(t_nodo_bin* arbol, int valor)
{
    if (*arbol == NULL)
    {
        *arbol = (t_nodo_bin)malloc(sizeof(struct s_nodo_bin));
        (*arbol)->valor = valor;
        (*arbol)->izq = NULL;
        (*arbol)->der = NULL;
    }
    else
    {
        if (valor < (*arbol)->valor)
            agregar(& (*arbol)->izq, valor);
        else
            agregar(& (*arbol)->der, valor);
    }
}
int cargarArbolVendedores(t_nodo_bin* arbol,FILE* fVende)
{
    int num,r,i=0,e=0;char c='';char*nombre=malloc(sizeof(char));
    char arr[5];
    int num2,num3;
    r=fscanf(fVende,"%d,"&num);
    while(r!=EOF){
        c=fgetc(fVende);
        while(c!=','){
            *(nombre+i)=c;
            i++;
            nombre=realloc(nombre,sizeof(char)*(i+2));
        }
        *(nombre+i)='\0';
        r=fscanf(fVende,"%d,%d\n",&num2,&num3);
        arr[e]={num,*nombre,num2,num3};
        agregar(arbol,arr[e]);
        e++;
        r=fscanf(fVende,"%d,",&num);
    }
}
void ordenarArborl(t_nodo_bin arboln)
{



}
