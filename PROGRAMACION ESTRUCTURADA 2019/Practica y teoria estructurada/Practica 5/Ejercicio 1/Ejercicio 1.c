#include <stdio.h>
#include <stdlib.h>
struct s_nodo
{
    int valor;
    struct s_nodo*sig;
};typedef struct s_nodo* t_nodo;

void agregar(t_nodo*,int),imprimir(t_nodo nodo),imprimiralrevez(t_nodo nodo);

int main()
{   int i;
    int j;
    t_nodo lista= NULL;

    printf("Ingrese numero: ");
    scanf("%d",&j);

    while (j!=0)
    {
        agregar(&lista,j);
        printf("Ingrese numero: ");
        scanf("%d",&j);
    }

    printf("Lista original \n");
    imprimir(lista);
    printf("\nLista invertida \n");
    imprimiralrevez(lista);
    return 0;
}

void agregar(t_nodo* nodo,int valor)
{
    if (*nodo==NULL)
    {
        *nodo= (t_nodo)malloc(sizeof(struct s_nodo));
        if(*nodo==NULL)return;
        {
            (*nodo)->valor=valor;
            (*nodo)->sig=NULL;
        }
    }
    else
    {
        agregar(&(*nodo)->sig,valor);
    }
}

void imprimir(t_nodo nodo)
{
    while(nodo!=NULL)
    {

        printf("%d ",nodo->valor);
        nodo=nodo->sig;

    }
}

void imprimiralrevez(t_nodo nodo){

    if (nodo==NULL)
    {
        return;
    }
    imprimiralrevez(nodo->sig);
    printf("%d ",nodo->valor);

}
