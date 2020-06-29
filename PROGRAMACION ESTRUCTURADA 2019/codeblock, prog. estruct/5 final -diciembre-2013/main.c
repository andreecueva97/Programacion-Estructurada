#include <stdio.h>
#include <stdlib.h>
/**1.1**/
/**
typedef s_nodo_bin{
    int dato;
    struct s_nodo_bin* izq;
    struct s_nodo_bin* der;
}* t_nodo_bin_ptr;
int descendientes(t_nodo_bin_ptr arb);
void agregar(t_nodo_bin_ptr* arb,int valor);
int main()
{
    t_nodo_bin_ptr arbol;
    agregar(&arbol,4);
    agregar(&arbol,5);
    printf("Hello world!\n");
    return 0;
}
int descendientes(t_nodo_bin_ptr arb)
{
    if(arb!=NULL){
        return 1+descendientes(&(*arb)->);
    }
    else{
        return 0;
    }
}
void agregar(t_nodo_bin_ptr* arb,int valor){
    if(*arb==NULL){
        arb=malloc(sizeof(struct s_nodo_bin));
        (*arb)->dato=valor;
        (*arb)->pizq=NULL;
        (*arb)->pder=NULL;
    }
    else{
        if(valor<(*arb)->valor){
            agregar(&(*arb)->pizq,valor);
        }
        else{
            agregar(&(*arb)->pder,valor);
        }
    }
}
**/
/**1.2**//**
typedef struct s_nodo{
    int valor;
    struct s_nodo* sig;
    struct s_nodo*ant;
}* t_nodo;
void agregar(t_nodo* lista, int valor){
    t_nodo aux;
    if(*lista==NULL)
    {
        *lista=nuevo_nodo(valor);
    }
    else{
        for(aux=*lista;aux->sig !=NULL;aux=aux->sig);
        aux->sig= nuevo_nodo(valor);
        aux->sig->ant=aux;

    }
}**/
/**2.1          c) 0 **/
/**
int doble(int valor);
int main(){
    printf("%d",doble(2));
    return 0;
}
int doble(int valor)
{
    int entero=16;
    entero=(valor<<20)&16;
    return entero;
}                                **/

/**2.2        a) no muestra nada**/
/**
int main()
{
    char*ptrA="Juan";
    char*ptrB="Pedro";

    ptrA=ptrA+4;
    for(;*ptrB!='\0';ptrB++);//NO SE ROMPE

    printf("%c",*ptrA);
}**/
/**2.3               d)128**/
/**
int main(){
    unsigned char a;
    a=~0<<((sizeof(unsigned char)*8)-1);
    printf("%u",a);
}                        **/
/**2.4      d)bzzzz**/
/**
char x (char a)             //a='a'     2)a='b'   3)a='c'
{
    if(a<='c')
        printf("%c",x(a+1));//1)x('b')  2)x('c')  3)imprime 'b'
    else
        printf("b");
    return 'z';
}
void main(){
    printf("%c",x('a'));
}                            **/
