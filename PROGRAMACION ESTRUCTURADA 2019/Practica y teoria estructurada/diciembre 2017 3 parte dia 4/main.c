#include <stdio.h>
#include <stdlib.h>
struct s_nodo{
    int valor;
    struct s_nodo* izq;
    struct s_nodo* der;
};typedef struct s_nodo* t_nodo;

void nodoEliminar(t_nodo* arbol,int valor);
void inorder(t_nodo arbol);
void agregar(t_nodo* arbol,int valor);
void eliminarArbol(t_nodo* arbol);
int niveles(t_nodo arbol);
int main(){
    t_nodo arbol=NULL;
    agregar(&arbol,8);
    agregar(&arbol,7);
    agregar(&arbol,9);
    agregar(&arbol,5);
     agregar(&arbol,4);
      agregar(&arbol,6);
    inorder(arbol);
    nodoEliminar(&arbol,6);
    //eliminarArbol(&arbol,2);
    inorder(arbol);printf("aca");
    printf("\nniveles %d",niveles(arbol));
    return 0;
}
void agregar(t_nodo* arbol, int valor){
    if(*arbol==NULL){

            *arbol=malloc(sizeof(struct s_nodo));
            (*arbol)->valor=valor;
            (*arbol)->izq=NULL;
            (*arbol)->der=NULL;}
    else{
        if((*arbol)->valor>valor){
            agregar(&(*arbol)->izq,valor);
        }else{
            agregar(&(*arbol)->der,valor);
        }
    }

}
void inorder(t_nodo arbol){//MENOR A MAYOR
    if(arbol!=NULL){
        inorder(arbol->izq);
        printf("%d ",arbol->valor);
        inorder(arbol->der);
    }
}

void eliminarArbol(t_nodo* arbol){//elimina todo el arbol
    if((*arbol)!=NULL){
        eliminarArbol(&(*arbol)->izq);
        eliminarArbol(&(*arbol)->der);

        free(*arbol);
        *arbol=NULL;
    }
}
void nodoEliminar(t_nodo* arbol,int valor){/**INORDER**/
    if(*arbol!=NULL){
        nodoEliminar(&(*arbol)->izq,valor);
        if((*arbol)->valor==valor){
            eliminarArbol(arbol);
        }
        if(*arbol!=NULL){
            nodoEliminar(&(*arbol)->der,valor);
        }
    }
}
int niveles(t_nodo arbol){
    int izq,der;
    if(arbol!=NULL){
        izq=niveles(arbol->izq);
        der=niveles(arbol->der);
        if(izq>der){
            return 1+izq;
        }
        else{
            return 1+der;
        }
    }
    else{
        return 0;
    }
}
