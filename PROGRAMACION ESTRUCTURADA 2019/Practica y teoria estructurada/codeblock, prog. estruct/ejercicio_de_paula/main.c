#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define C 5
#define F 5
void cargarText(char matT[F][C],int f);
void cargarMatText(char matT[F][C]);
void imprimirMat(char matT[F][C]);

int main()
{
    char matT[F][C];
    cargarMatText(matT);
    imprimirMat(matT);
    return 0;
}

void cargarText(char matT[F][C],int f){
    int i=0;
    int c=0;
    c=getche();
    while(i<C-1 && c!='\r'){
        matT[f][i]=c;
        i++;
        c=getche();
    }
    matT[f][i]='\0';
    printf("\n");
}
void cargarMatText(char matT[F][C]){
    int f=0;
    cargarText(matT,f);
    for(f=1;f<=F-1;f++){
        cargarText(matT,f);
    }
    matT[f][0]='\0';
}
void imprimirMat(char matT[F][C]){
    printf("\n matriz impresa \n");
    int f=0;
    int i=0;
    for(f=0;matT[f][0]!='\0';f++){
        for(i=0;matT[f][i]!='\0';i++){
            printf("%c",matT[f][i]);
        }
        printf("\n");
    }
    printf("\n");
    getche();
}
