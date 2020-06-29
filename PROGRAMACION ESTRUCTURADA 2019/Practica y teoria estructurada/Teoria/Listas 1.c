#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct s_nodo{
    int valor;
    struct s_nodo* sig;
}; typedef struct s_nodo* t_nodo;

void agregar(t_nodo *nodo, int valor), eliminar(t_nodo *nodo, int valor), mostrarLista(t_nodo *nodo), insertar(t_nodo *nodo, int valor);

void main(){
    int valor;
    t_nodo lista = NULL;

    agregar(&lista, 5);
    agregar(&lista, 7);
    agregar(&lista, 2);
    agregar(&lista, 1);

    eliminar(&lista,2);
    insertar(&lista, 2);
    mostrarLista(&lista);
}

void agregar(t_nodo *nodo, int valor){
    if(*nodo == NULL){
        *nodo = (t_nodo)malloc(sizeof(struct s_nodo));
        (*nodo)->valor = valor;
        (*nodo)->sig = NULL;

        printf("Se agrego el valor %d a la lista.\n", valor);
    }
    else{
        agregar(&(*nodo)->sig, valor);
    }
}


void eliminar(t_nodo *nodo, int valor){
    t_nodo aux = NULL;

    if(*nodo == NULL){
        printf("Error al eliminar lista vacia.");
    }
    else if((*nodo)->valor == valor){
        aux = *nodo;
        (*nodo) = (*nodo)->sig;
        free(aux);
        printf("\nSe elimino el valor %d de la lista\n", valor);
    }
    else{
        eliminar(&(*nodo)->sig,valor);
    }
}

void insertar(t_nodo *nodo, int valor){
    t_nodo aux = (t_nodo)malloc(sizeof(struct s_nodo));
    if(*nodo == NULL || valor < (*nodo)->valor){
        aux->valor = valor;
        aux->sig = *nodo;
        *nodo = aux;
    }
    else{
        insertar(&(*nodo)->sig,valor);
    }
}

void mostrarLista(t_nodo *nodo){
    if (*nodo == NULL){
        printf("No se puede imprimir una lista vacia.");
    }
    else{
        while (*nodo != NULL){
            printf("\nLista: %d\n", (*nodo)->valor);
            *nodo = (*nodo)->sig;
        }
    }
}

/// O ///
/*
void mostrarLista(t_nodo *nodo){
    if (*nodo == NULL){
        return 0;
    }
    else{

        printf("\nLista: %d\n", (*nodo)->valor);
        mostrarLista(&(*nodo)->sig);
        }
}
*/
