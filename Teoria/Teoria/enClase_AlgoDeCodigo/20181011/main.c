#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct s_texto{
char * txt;
unsigned int longitud;
};
typedef struct s_texto t_texto;

char* cargarStrDin(){       /** Carga un arreglo dinamico de char (string) y retorna la direccion*/
    int i=0;
    char letra;
    char* arr=NULL;                             /** lo inicalizo en null*/

    letra=getche();                             /** Ingresar caracter desde teclado*/
    if (letra!='\r'){
        arr = (char *) malloc(sizeof(char));    /** Asignar memoria Puntero a char: es un arreglo dinámico de punteros a char*/
        if (arr==NULL){return NULL;}            /** Sale de la funcion si no tiene memoria*/

        while (letra!='\r')                     /** mientras no sea un ENTER ('\r') el valor ingresado desde el teclado*/
        {
            *(arr+i)=letra;                     /** asignar la letra (caracter) ingresada a una posicion del arreglo*/
            i++;                                /** incrementar variable de desplazamiento de direcion */
            arr=(char *) realloc(arr,(i+1)*sizeof(char)); /** Ampliar memoria*/
            if (arr==NULL){return NULL;}
            letra=getche();                     /** Ingresar caracter desde teclado*/
        }
        arr[i]='\0';                            /** Asignar '\0' determina el fin de un string */
    }
    printf("\n");                               /** */
    return arr;                                 /** retorna la direccion de */
}
void cargarStrDin2(char** arr){       /** Carga un arreglo dinamico de char (string) y retorna la direccion*/
    int i=0;
    char letra;
    *(arr) = NULL;                                 /** lo inicalizo en null*/
    letra=getche();                                /** Ingresar caracter desde teclado*/
    if (letra!='\r'){
        *(arr) = (char *) malloc(sizeof(char));    /** Asignar memoria Puntero a char: es un arreglo dinámico de punteros a char*/
        if (*(arr)==NULL){return NULL;}            /** Sale de la funcion si no tiene memoria*/

        while (letra!='\r')                        /** mientras no sea un ENTER ('\r') el valor ingresado desde el teclado*/
        {
            *((*(arr))+i)=letra;                   /** asignar la letra (caracter) ingresada a una posicion del arreglo*/
            //(*arr)[i]=letra;                      /**expresion equivalente a la anterior*/
            i++;                                   /** incrementar variable de desplazamiento de direcion */
            *(arr)=(char *) realloc(*(arr),(i+1)*sizeof(char)); /** Ampliar memoria*/
            if (*(arr)==NULL){return NULL;}
            letra=getche();                        /** Ingresar caracter desde teclado*/
        }
        *((*(arr))+i)='\0';                        /** Asignar '\0' determina el fin de un string */
        //(*arr)[i]='\0';                          /** expresión equivalente a la anterior*/
    }
    printf("\n");                                  /** */

}


int main()
{
    char* arr;
    t_texto frase;
    //frase.txt = cargarStrDin();

    cargarStrDin2(&(frase.txt));
    printf("\n%s",frase.txt);
    frase.longitud = strlen(frase.txt);
    printf("\n%d",frase.longitud);
    return 0;
}
