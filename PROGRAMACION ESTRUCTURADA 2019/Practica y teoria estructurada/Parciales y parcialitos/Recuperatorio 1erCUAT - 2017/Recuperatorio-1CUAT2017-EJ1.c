#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_ciudad
{
int cod;
char* nombre;
unsigned char cod_pai;
};
typedef struct s_ciudad t_ciudad;


t_ciudad* filtrar(t_ciudad arr[3], char cod_pai);

int main()
{
    t_ciudad arr[3];
    t_ciudad* resul = NULL;
    int i;

    arr[0].cod = 1;
    arr[0].cod_pai = 'c';
    arr[0].nombre = "Buenos Aires";

    arr[2].cod = 3;
    arr[2].cod_pai = 'b';
    arr[2].nombre = "Sao Pablo";

    arr[1].cod = 2;
    arr[1].cod_pai = 'c';
    arr[1].nombre = "Cordoba";

    resul = filtrar(arr,'c');

    for(i=0; resul[i].cod != 0; i++)
    {
        printf("%c, %d, %s \n",resul[i].cod_pai,resul[i].cod,resul[i].nombre);
    }

    return 0;
}

t_ciudad* filtrar(t_ciudad arr[3], char cod_pai)
{
    t_ciudad* resultado = NULL;
    int i, longitud;

    resultado = (t_ciudad*) malloc(sizeof(t_ciudad));
    longitud = 0;

    for(i=0; i < 3;i++)
    {
        if(arr[i].cod_pai == cod_pai)
        {
            resultado = realloc(resultado, (1+longitud) * sizeof(t_ciudad));
            (resultado+longitud)->cod = arr[i].cod;
            (resultado+longitud)->cod_pai = cod_pai;
            (resultado+longitud)->nombre = arr[i].nombre;
            longitud++;
        }
    }
     /*CONDICION DE CORTE AL FINAL*/

    resultado = realloc(resultado, (1+longitud) * sizeof(t_ciudad));

    (resultado+longitud)->cod = 0;

    /* ORDENAMIENTO */
    int r, j;
    t_ciudad aux;

    for(r=0; resultado[r].cod != 0;r++)
    {
        for(j = r+1; resultado[j].cod != 0 ; j++)
        {
            if(strcmp( resultado[r].nombre , resultado[j].nombre) > 0) //Si el segundo vale mas que el primero, se intercambian.
            {
                aux.nombre = resultado[r].nombre;
                resultado[r].nombre = resultado[j].nombre;
                resultado[j].nombre = aux.nombre;
            }
        }
    }

    return (resultado);

}





