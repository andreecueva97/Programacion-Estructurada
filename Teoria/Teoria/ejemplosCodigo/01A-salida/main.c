#include <stdio.h>                  /** Librer�a: https://es.wikipedia.org/wiki/Stdio.h */
#include <stdlib.h>                 /** Librer�a: https://es.wikipedia.org/wiki/Stdlib.h */

int main()                          /** Funci�n principal "main" (main es una palabra reservada) */
{                                   /** Llave de apertura de la funci�n principal main*/
/** CUERPO DE LA FUNCI�N PRINCIPAL - AQUI VA EL CODIGO A EJECUTAR */

printf("\n---------------------------------------\n");
printf("Hola Mundo ...");           /** printf: funci�n del lenguaje que inprime en pantalla la cadena pasada por par�metro */
printf("abc");                      /** printf: https://es.wikipedia.org/wiki/Printf */
printf("\n");
printf("155778");
printf("12345\n6789");

printf("\n---------------------------------------\n");
printf("Cadena: %s, caracter: %c, entero: %d, flotante: %4.2lf ","Lenguaje",'C', 2019,3.1418);
printf("\n---------------------------------------\n");
printf("\n");
printf("'Imprimir dentro de un tamanio especificado y con alineacion'\n");
printf("Pais: %30s\n","Republica Argentina");           /** string(cadena) alineado a derecha*/
printf("Pais: %-30s\n","Republica Argentina");          /** string(cadena) alineado a izquierda*/

printf("Cantidad Mensajes: %10d\n",203);                /** numero entero alineado a derecha*/
printf("Cantidad Mensajes: %-10d\n",203);               /** numero entero alineado a izquierda*/

printf("Longuitud: %6.1lf\n",54.7);                     /** numero flotante (Real) alineado a derecha*/
printf("Longuitud: %-6.2lf\n",12.4567);                 /** numero flotante (Real) alineado a izquierda*/

printf("\n---------------------------------------\n");

printf("%-10s%-10s%10s\n","Nombre", "Apellido", "DNI");
printf("%-10s%-10s%10s\n","......", ".........", "....");
printf("%-10s%-10s%10s\n","Carla", "Hudson", "12345");
printf("%-10s%-10s%10s\n","Arturo", "Ensenada", "444");
printf("%-10s%-10s%10s\n","Clara", "Bell", "5667");


    return 0;                       /** Retorno de la funci�n principal "main" */
}                                   /** Llave de cierre de la funci�n principal main*/
