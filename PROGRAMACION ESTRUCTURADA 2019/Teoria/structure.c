#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    struct s_punto
    {
        int x,y;
        char nom[10];
    };

    typedef struct s_punto t_punto; /*Construccion de dato, typedef le encuentra struct s_punto un alias,
    en este caso t_punto (Nombre del tipo de dato)*/


int main()
{
    t_punto a,b;
    a.x = 10;
    a.y = 20;
    /*b = a; Solo se puede hacer si las variables no son punteros(arreglos)*/
    strcpy(a.nom,"Arreglo"); /*Asignacion de arreglo*/
    printf("- a.x: %d         -  a.y: %d",a.x,a.y);
    printf("\n- b.x: %d         -  b.y: %d",b.x,b.y); /*Se le asigna basura al b ya que no tiene asignado valores*/
    printf("\n- a.nom: %s  -  b.nom: %s\n",a.nom);
    return 0;
}
