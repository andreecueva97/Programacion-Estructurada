#include <stdio.h>
#include <stdlib.h>
#define T 10
#define KEY_ESC 27
/**


  CREA UN ARCHIVO BINARIO Y PERMITE ESCRIBIR el
  CONTENIDO DE UN ARREGLO EN EL ARCHIVO.
  LUEGO SE LEE EL ARCHIVO Y SE IMPRIME EL ARREGLO.

*/

FILE* abrirArchivo(char nomArch[T],char modo[]);
int escribirArchivo(FILE* fp, unsigned int datos[T]);
int leerArchivo(FILE* fp, unsigned int datos[T]);
int cargarVector(char arr[]);
int imprimirVector(unsigned int arr[T]);
int cerrarArchivo(FILE* fp);

int main()
{
    unsigned int datosFuente[T] = { 25, 12, 45, 345, 512, 345, 654, 287, 567, 124 };
    unsigned int datosDestino[T] = {0};

    FILE* fp;                       /** DECLARACION de un puntero al archivo*/
    char nombre[11] = "prueba.dat"; /** DECLARACION nombre del archivo*/

    fp=abrirArchivo(nombre,"w+b");  /** ABRIR  el archivo de (W+b):escritura / lectura Binario*/

    printf( "Escribiendo en el archivo las cantidades:\n\n" );
    imprimirVector(datosFuente);    /** Imprimir el vactor para ver el pantalla lo que se cargará en e archivo*/
    escribirArchivo(fp,datosFuente);/** Grabar en archivo el contenido de datosFuente*/

    rewind(fp);                   /** vuelve el puntero del archivo al inicio */

    printf( "\n\n\nLeyendo los datos del archivo :\n\n");
    leerArchivo(fp, datosDestino);
    imprimirVector(datosDestino);

    cerrarArchivo(fp);             /** SIEMPRE se debe cerrar el archivo */

    return 0;
}

FILE* abrirArchivo (char nomArch[T],char modo[])
{
     return fopen(nomArch, modo); /** ABRE el descriptor de un archivo y en un modo determinado*/
}

int escribirArchivo(FILE* fp, unsigned int datos[T])
{    /** escribe en un archivo binario (pasado el puntero del descriptor por parámetro)
         el contenido leido de un arreglo (pasado por parametro)
    */

    fwrite( datos, sizeof(unsigned int), T, fp ); /** fwrite: permite escribir archivos */
    /**
        Parametros "fwrite"
        1) datos: puntero de los Valores a leer (¡es la fuente de datos!!)
        2) Tamanio en byte de cada elemento a escribir
        3) cantidad de elementos a escribir
        4) puntero del archivo a escribir (¡es el destino de los datos!!)
    */
    return 0;
}
int leerArchivo(FILE* fp, unsigned int datos[T])
{
   /** leer en un archivo binario (pasado el puntero del descriptor por parámetro)
        y escribir el contenido en un arreglo (pasado por parametro)
    */
    fread(datos, sizeof(unsigned int), T, fp ); /** fread: Permite leer archivos */
    /**
        Parametros
        1) datos: puntero de los Valores a escribir (¡es el destino de los datos!!)
        2) Tamanio en byte de cada elemento a leer
        3) cantidad de elementos a leer
        4) puntero del fichero a leer (¡es la fuente de datos!!)
    */
}

int imprimirVector(unsigned int arr[T])
{
    int i;
    for( i=0; i<10; i++ )
        printf( "%d\t", arr[i] );

    return 0;
}

int cerrarArchivo(FILE* fp)
{
    fclose(fp); /** CIERRA el descriptor de un archivo*/
    return 0;
}
