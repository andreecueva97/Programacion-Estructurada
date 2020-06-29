#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct s_nodo
{
    int valor;
    struct s_nodo* sig;
    int dato;
};
typedef struct s_nodo* t_nodo;

void push(t_nodo*, int);
int pop(t_nodo*);

int main()
{
    int val;
    t_nodo pila = NULL;
    do
    {
        printf("Ingrese un valor, con 0 finaliza: ");
        scanf("%d", &val);
        if (val != 0)
            push(&pila, val);
    } while ( val != 0);

    printf("\nLos elementos de la pila, desapilados, son:\n");
    while (pila != NULL)
    {
        val = pop(&pila);
        printf("%d -", val);
    }
    printf("\n");
    return 0;
}

void push(t_nodo* pila, int valor)
{
    t_nodo aux = (t_nodo)malloc(sizeof(struct s_nodo));
    aux->dato = valor;
    aux->sig = *pila;
    *pila = aux;
}

int pop(t_nodo* pila)
{
    int valor;
    t_nodo aux = *pila;
    valor = aux->dato;
    *pila = aux->sig;
    free(aux);
    return valor;
}
