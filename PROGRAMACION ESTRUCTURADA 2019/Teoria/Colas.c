#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct s_nodo
{
    int valor;
    int dato;
    struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;

struct s_cola
{
    t_nodo frente;
    t_nodo final;
};
typedef struct s_cola t_cola;

void queue(t_cola*, int);
int dequeue(t_cola*);

int main()
{
    int val;
    t_cola cola = { NULL, NULL };
    do
    {
        printf("Ingrese valores, con 0 finaliza: ");
        scanf("%d", &val);
        if (val != 0)
            queue(&cola, val);
    } while ( val != 0);

    printf("\nDatos ingresados: ");
    while (cola.frente != NULL)
    {
        val = dequeue(&cola);
        printf("%d -", val);
    }
    printf("\n");
    return 0;
}

void queue(t_cola* cola, int valor)
{
    t_nodo aux = (t_nodo) malloc(sizeof(struct s_nodo));
    aux->valor = valor;
    aux->sig = NULL;
    if (cola->frente == NULL && cola->final == NULL)
    {
        cola->frente = aux;
        cola->final = aux;
    }
    else
    {
        cola->final->sig = aux;
        cola->final = aux;
    }
}


int dequeue(t_cola* cola)
{
    int valor;
    t_nodo aux = cola->frente;
    cola->frente = cola->frente->sig;
    valor = aux->dato;
    free(aux);
    if (cola->frente == NULL)
    {
        cola->final = NULL;
    }
    return valor;
}
