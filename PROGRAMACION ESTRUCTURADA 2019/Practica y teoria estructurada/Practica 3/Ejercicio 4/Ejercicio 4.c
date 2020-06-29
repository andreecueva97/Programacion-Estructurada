#include <stdio.h>
#include <stdlib.h>

typedef struct{int numero, valor; char palo;} t_carta;

void ordenar(t_carta *p,t_carta *q,t_carta *w);

int main()
{
    t_carta a = {7,1,'E'};
    t_carta b,c;
    b.numero = 1;
    b.valor = 2;
    b.palo = 'B';
    c.numero = 1;
    c.valor = 3;
    c.palo = 'E';
    ordenar(&a,&b,&c);
    printf("Ordenado por valor:\n");
    printf("N | P | V\n");
    printf("---------\n");
    printf("%d | %c | %d\n",a.numero, a.palo,a.valor);
    printf("%d | %c | %d\n",b.numero, b.palo,b.valor);
    printf("%d | %c | %d\n",c.numero, c.palo,c.valor);
    return 0;
}

void ordenar(t_carta *a,t_carta *b,t_carta *c)
{
    t_carta aux,aux2;
    if ((*c).valor > (*a).valor && (*c).valor > (*b).valor)
    {
        if ((*a).valor > (*b).valor)
        {
            aux = *a;
            aux2 = *b;
            *a = *c;
            *b = aux;
            *c = aux2;
        }
        else if ((*a).valor < (*b).valor)
        {
             aux = *a;
             aux2 = *b;
            *a = *c;
            *b = aux2;
            *c = aux;
        }
    }
    else{
        printf("No rompas las bolas\n");
    }
}
