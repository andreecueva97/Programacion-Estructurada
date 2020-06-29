#include <stdio.h>
#include <stdlib.h>
void fun2(char*frase);
int main()
{
    /*
    //a=a<<2+3   primero hace 2+3 luego hace el desplazamiento
    unsigned int a=1;unsigned char b='1';//puedo usar char y tambien funciona

    printf("%d\n",b+b);
    a=a<<(b+b); //a<< 2   devuelve 4.

    //a=a<<b me da cualquier numero porque toma a b como un char!!!
    printf("%d\n",a);
    */
    /*int*arr;arr=malloc(sizeof(int));
    *arr=5;
    printf("el numero es %d\n",*(arr+0));
    printf("el numero es %d",*arr);
    */
    char* frase="hola";
    fun2(frase);
    return 0;
}
void fun2(char*frase){
    printf("%c",*(frase+1)+(frase[2]-frase[3]));
}
