#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
struct s_indice{
    int inicio;
    int fin;
};typedef struct s_indice t_indice;

t_indice busSub(char* str,char* sub);

int main()
{
    printf("Hello world!\n");
    char*str="la verdad absoluta";
    char*sub="r";
    t_indice a=busSub(str,sub);
    printf("%d %d",a.inicio,a.fin);
    return 0;
}
t_indice busSub(char* str,char* sub){
    t_indice a;
    int i=0,esta=0,j,tam;char*aux=NULL;
    for(tam=0;sub[tam]!='\0';tam++);
    while(*(str+i)!='\0'){
        aux=malloc(sizeof(char));
        j=0;
        while(j<tam){
            *(aux+j)=*(str+j);
            aux=realloc(aux,sizeof(char)*(j+2));
            j++;
        }
        *(aux+j)='\0';
        printf("%s",aux);
        if(strcmp(aux,sub)==0){
            a.inicio=i;
            a.fin=i+j-1;
            return a;
        }
        i++;
        free(aux);
    }
    if(esta==0){
        a.inicio=-1;
        a.fin=-1;
    }
    free(aux);
    return a;
}**/
fopen(arch)
int i=0;char*linea;
!feof(arch)
    linea=
