#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    tNodoBin arbol;
    FILE*fVende=fopen("vendedores.txt");
    cargarArbolVendedores(&arbol,&fVende);
    return 0;
}
int cargarArbolVendedores(tNodoBin*arbol,FILE *fVende){
    tvendedores* vend=NULL;
    ///...
    if(*arbol==NULL){
            arbol=malloc(sizeof(struct sNodoBin));
            (*arbol)->valor=

    }else{

    }









    return 0;
}
