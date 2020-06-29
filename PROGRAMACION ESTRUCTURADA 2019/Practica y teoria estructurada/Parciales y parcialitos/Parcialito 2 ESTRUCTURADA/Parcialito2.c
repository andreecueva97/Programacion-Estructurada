#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define N 20
#define L 50

typedef struct{
    char nombre[N];
    unsigned int color;
    unsigned char R,G,B;
}paleta;

void cargar_colores(char m[L], paleta p[N]);
void descomponer_colores(paleta P[N]);
void imprimir_colores(paleta p[N]);




int main()
{
    char archivo[L] ="cromatico.txt";

    paleta colorido[N]= {{{0}}};

    cargar_colores(archivo,colorido);//carga el archivo en el arreglo p.

    descomponer_colores(colorido); //Completa los RGB del arreglo p

    imprimir_colores(colorido); //imprime el arreglo p


    return 0;
}



void cargar_colores(char m[L], paleta p[N])
{
    FILE* archivo;
    archivo = fopen(m,"r");

    if(archivo == NULL){
        exit(1);
    }

    int r,cont1,cont2,color1;
    char car;


    cont1 = 0;
    car = 0;
    while(r != EOF && car!=EOF)
    {
        car = fgetc(archivo);
        cont2 = 0;
        while(car != EOF && car != ',' && cont2 < N)
        {
            p[cont1].nombre[cont2] = car;
            car = fgetc(archivo);
            cont2 ++;
        }
        p[cont1].nombre[cont2] = '\0';

        r = fscanf(archivo,"%d\n",&color1);

        p[cont1].color = color1;

        cont1 ++;
    }

    p[cont1].nombre[0] = '\0';

    return;
}

void descomponer_colores(paleta p[N])
{
    int maskR, maskG, maskB,cont;

    maskR = (255)<< 16;
    maskG = (255)<< 8;
    maskB = 255;

    cont = 0;
    while(p[cont].nombre[0] != '\0')
    {
        p[cont].R = ( p[cont].color & maskR )>>16;
        p[cont].G = ( p[cont].color & maskG )>>8;
        p[cont].B = ( p[cont].color & maskB );

        cont ++;
    }
    return;
}

void imprimir_colores(paleta p[N])
{
    int cont;

    cont = 0;
    while(p[cont].nombre[0] != '\0')
    {

    printf("%s - ",p[cont].nombre);

    printf("%d - ",p[cont].color);

    printf("%d - ",p[cont].R);
    printf("%d - ",p[cont].G);
    printf("%d\n",p[cont].B);
    cont++;
    }

    return;
}
