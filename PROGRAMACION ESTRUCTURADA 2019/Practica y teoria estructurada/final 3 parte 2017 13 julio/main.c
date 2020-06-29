#include <stdio.h>
#include <stdlib.h>
struct guardar{
    int idlocal;
    char nombre[200];
    int prom;
    int minaltura;
    int maxaltura;
};
struct s_nodo{
    struct guardar valor;
    struct s_nodo* sig;
};
struct s_local{
    int idlocal;
    char nombre[200];
};typedef struct s_local t_local;
struct s_altura{
    int idlocal;
    double altura;
    unsigned int AMD;
};typedef struct s_altura t_altura;
t_local maxCinco(int n,int anio);
int main()
{

    printf("Hello world!\n");

    return 0;
}
t_local maxCinco(int n,int anio){
    FILE* alturas=fopen("alturas.txt","r");

}
