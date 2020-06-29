#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 10;
    int* px = NULL;
    char* pa = NULL; // inicializo con NULL
    char a = 64;
    pa = &a;
    printf("\n/**CHAR * * * * * */\n");
    printf("%d <==> %c\n",a,a);
    printf("dir mem de a es: %p \n", &a);
    printf("dir mem de a seguna pa: %p \n", pa);
    printf("contenido de a segun *pa: %c \n", *pa);
    *pa=65;
    printf("\nCON CAMBIOS desde puntero\n");
    printf("%d <==> %c\n",a,a);
    printf("dir mem de a es: %p \n", &a);
    printf("dir mem de a segun pa: %p \n", pa);
    printf("contenido de a segun *pa: %c \n", *pa);

    printf("\n/**INT * * * * * */\n");
    px = &x;
    printf("%d\n",x);
    printf("dir mem de x es: %p \n", &x);
    printf("dir mem de x segun  px: %p ", px);
    printf("contenido de x segun *px: %d ", *px);
    *px=11;
    printf("\nCON CAMBIOS desde punero\n");
    printf("%d\n",x);
    printf("dir mem de x es: %p \n", &x);
    printf("dir mem de x segun  px: %p ", px);
    printf("contenido de x segun *px: %d ", *px);


    return 0;
}


/**

&: dirección de .....
*: contenido de .....

*/
