#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nodo{
    struct nodo *padre;
    struct nodo *izq;
    struct nodo *der;
    int valor;

};

struct nodo *crearNodo(struct nodo *padre, int valor);
void agregarvalor(struct nodo *arbol, int valor);

void main(){
    struct nodo *arbol;
    arbol = crearNodo(NULL, 40);
    agregarvalor(arbol, 50);
    agregarvalor(arbol, 3);
    agregarvalor(arbol, 60);
    agregarvalor(arbol, 4);
    agregarvalor(arbol, 1);

}

struct nodo *crearNodo(struct nodo *padre, int valor){
    struct nodo *n= calloc(sizeof(struct nodo),1);
    n->padre = padre;
    n->valor = valor;

    return n;

};

void agregarvalor(struct nodo *arbol, int valor){
    struct nodo *temp, *pivote;
    int derecho = 0;
    if (arbol){
    temp = arbol;
    while(temp != NULL){
        pivote = temp;
        if(valor > temp->valor){
            temp = temp->der;
            derecho  = 1;
        }
        else{
            temp = temp->izq;
            derecho = 0;
        }
    }
        temp = crearNodo(pivote, valor);
    if(derecho){
        printf("Insertando %i del lado derecho de %i\n", valor, pivote->valor);
        pivote->der = temp;
    }
    else{
        printf("Insertando %i del lado izquierdo de %i\n", valor, pivote->valor);
        pivote->izq = temp;
    }
    }
}
