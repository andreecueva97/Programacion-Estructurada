#include <stdio.h>
#include <stdlib.h>
#define T 10
typedef struct sVenTar
{
    int codVen;
    char mesVenta[25];
    int canTar;
}tVenTar;

int cerrarArchivo(FILE* fp);
FILE* abrirArchivo(char nombre[30],char modo[3]);
int escribirArchivo(FILE* fichero);
int leerArchivo(FILE* fichero);

int main()
{
    FILE* fichero;
    char nombre[30] = "ventasTarjetas.dat";
    char modo[4]="w+b";

    fichero= abrirArchivo(nombre,modo); /** Abrir archivo*/

    escribirArchivo(fichero);
    rewind( fichero );
    leerArchivo(fichero);

    cerrarArchivo(fichero);


   return 0;
}
FILE* abrirArchivo(char nombre[30],char modo[3])
{
    FILE* fichero = fopen( nombre,modo );
    printf( "Fichero: %s -> ", nombre );
    if( fichero )
        printf( "creado (ABIERTO)\n" );
    else
    {
        printf( "Error (NO ABIERTO)\n" );
        return 1;
    }
    return fichero ;
}

int cerrarArchivo(FILE* fichero)
{
    if( !fclose(fichero) )
        printf( "\nFichero cerrado\n" );
    else
    {
        printf( "\nError: fichero NO CERRADO\n" );
        return 1;
    }
    return 0;
}

int escribirArchivo(FILE* fichero)
{
    /** cargar el arreglo de tVenTar con datos validos*/
    tVenTar venTar[T]={{ 1, "Enero", 91},
                        { 1, "Febrero", 60},
                        { 1, "Marzo", 60},
                        { 3, "Febrero", 60},
                        { 6, "Marzo", 76},
                        { 1, "Enero", 90},
                        { 7, "Febrero", 60},
                        { 7, "Marzo", 62},
                        { 8, "Febrero", 60},
                        { 8, "Marzo", 96}
                      };

    int i;

    printf( "Escribiendo cantidades:\n\n" );
    for( i=0; i<T; i++ )
    {
        printf( "%d \t%s\t%d\t\n", venTar[i].codVen,venTar[i].mesVenta,venTar[i].canTar);
        fwrite( &venTar[i], sizeof(tVenTar), 1, fichero );
    }

}
int leerArchivo(FILE* fichero)
{
    int  i;
    tVenTar leer[T]={0};
    printf( "\nLeyendo los datos del fichero \n" );
    int l=0;
    i=0;

    fread( &leer[i], sizeof(tVenTar), 1, fichero );
    while(!feof(fichero))
    {
        printf("%d\t%s\t%d\t\n", leer[i].codVen,leer[i].mesVenta,leer[i].canTar);
        i++;
        fread( &leer[i], sizeof(tVenTar), 1, fichero );
    }

    /**
    //sin feof, utilizando el retorno de bytes leidos de fread
    l=fread( &leer[i], sizeof(tVenTar), 1, fichero );


    while(l!=0 )
    {
        printf("%d\t%s\t%d\t\n", leer[i].codVen,leer[i].mesVenta,leer[i].canTar);
        i++;
        l=fread( &leer[i], sizeof(tVenTar), 1, fichero );
    }
    */

}
