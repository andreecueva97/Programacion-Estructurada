#include <stdio.h>
#include <stdlib.h>
#define F 5
#define C 5

void cargarMatText(char mat[F][C]);
void imprimirMatText(char mat[F][C]);

int main()
{
    char mat[F][C]={0};
    cargarMatText(mat);
    imprimirMatText(mat);
}

void cargarMatText(char mat[F][C]){
    int f,c;
    char aux;
    aux=getche();
    for (f=0; f<F-1&& aux!='\r'; f++){
        for(c=0; c<C-1 && aux!='\r'; c++){
            mat[f][c]=aux;
            aux=getche();

        }
        mat[f][c]='\0';
        printf("\n");
        aux=getche();

    }
    mat[f][c]='\0';
}
void imprimirMatText(char mat[F][C]){
    int f;
    for (f=0;mat[f][0]!='\0'; f++){
        printf("\n%s", mat[f]);
    }

}

/**
void leer(char arrC[]);
void reemplazar(char arrC[T], char ori, char susti);


int main()
{
    char arr[T]={0};
    leer(arr);
    char or, su;
    printf("\nIngrese el valor a buscar: ");
    or = getche();
    printf("\nIngrese el valor de reemplazo: ");
    su = getche();
    reemplazar(arr, or, su);
    printf("\n%s", arr);
    return 0;
}


void leer(char arrC[T]){
    int i;
    char ent;
    printf("Ingresar: ");
    i=0;
    ent=getche();
    while(ent!='\r'&& i<T-1){
        arrC[i]=ent;
        i++;
        ent=getche();
    }
     arrC[i]='\0';

}
void reemplazar(char arrC[], char ori, char susti){
    int i;

    for (i=0;arrC[i]!='\0';i++){
        if(arrC[i]==ori){
            arrC[i]=susti;

        }
    }
}
*/
