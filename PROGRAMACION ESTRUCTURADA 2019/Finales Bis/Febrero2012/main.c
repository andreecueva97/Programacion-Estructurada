#include <stdio.h>
#include <stdlib.h>

struct s_indice{
    int ini;
    int fin;
};typedef struct s_indice t_indice;

struct s_indices{
    int fila;
    int ini;
    int fin;
};typedef struct s_indices t_indices;

struct s_nodo{
    t_indices valor;
    struct s_nodo* sig;
};typedef struct s_nodo* t_nodo;
void agregar(t_nodo* lista, t_indices* indice);

t_indice buscarSub(char* str,char* sub){
    int lenSub,i,j;
    t_indice arr;
    arr.ini=-1;
    for(lenSub=0;*(sub+lenSub)!='\0';lenSub++);
    for(i=0;*(str+i)!='\0';i++){
        if (*(str+i)==*sub){
                int ban=0;
                for(j=0;j<lenSub;j++){
                    if (*(str+i+j)!=*(sub+j))
                        ban=1;
                }
                if (ban==0){
                    arr.ini=i;
                    arr.fin=(arr.ini)+lenSub-1;
                    return arr;
                }
        }
    }
    arr.fin=-1;
    return arr;
}

int main(){
    char* str="La verdad absoluta no existe";
    char* sub="d ab";
    printf("%d",buscarSub(str,sub).fin);
}

void indices(char* sub){
    char c;
    int i,j=0;
    char* str;
    str=malloc(sizeof(char));
    t_indices* arr=NULL;
    t_indice arrV;
    t_nodo lista;
    arr=malloc(sizeof(struct s_indices));
    FILE* arch=fopen("frases.txt","r");
    c=fgetc(arch);
    while(!feof(arch)){
        for(i=0;c!='\n';i++){
            *(str+i)=c;
            str=realloc(str,sizeof(char)*(i+1));
            c=fgetc(arch);
        }
        arrV=buscarSub(str,sub);
        if(arrV.ini!=-1){
            (*(arr+j)).fila=j;
            (*(arr+j)).ini=arrV.ini;
            (*(arr+j)).fin=arrV.fin;
            agregar(&lista,arr);
        }
        j++;
        c=fgetc(arch);
    }
}
void agregar(t_nodo* lista, t_indices* indice)
{
    if(*lista==NULL)
    {
        *lista=malloc(sizeof(t_indices));
        (*lista)->valor=(*indice);
        (*lista)->sig=NULL;
    }
    else agregar(&(*lista)->sig,indice);
}
