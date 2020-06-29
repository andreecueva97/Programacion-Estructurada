#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    struct s_fecha
    {
        int dia,mes,anio;
    };

    typedef struct s_fecha t_fecha;

struct s_empleado
    {
        int legajo;
        char nombre[25];
        char apellido[25];
    };

    typedef struct s_empleado t_empleado;

int main()
{
    t_empleado juan;
    strcpy(juan.nombre, "Juan"); /*juan.nombre[0] = 'J'(primera letra);*/
    strcpy(juan.apellido, "Larrapato");
    juan.legajo = 21601231;
    printf("Nombre: %s\nApellido: %s \nLegajo: %d",juan.nombre, juan.apellido, juan.legajo);
    return 0;
}
