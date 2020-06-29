#include <stdio.h>
#include <stdlib.h>

struct sPalabra{
    int inicio;
    int fin;
};typedef struct sPalabra tPalabra;

struct sNodo{
    int linea;
    int inicio;
    int fin;
    struct sNodo* sig;
};typedef struct sNodo* tNodo;

tPalabra buscarSub(char* str,char* sub);
tNodo indices(char* sub);
void agregar(tNodo* lista,int ini,int fin,int linea);
void recorrer(tNodo nodo);

int main()
{
    char* sub="da";
    char* str="La verdad absoluta no existe, y esto es absolutamente cierto";
    tPalabra palabra=buscarSub(str,sub);
    printf("Ej 1:\n(%d,%d)\n",palabra.inicio,palabra.fin);
    printf("\nEj 2:\n");
    tNodo lista=indices(sub);
    recorrer(lista);
    return 0;
}

tPalabra buscarSub(char* str,char* sub){
    int i,j;
    tPalabra palabra;
    for(j=0;*(str+j)!='\0';j++){
        if(*(str+j)==*(sub)){
            int ban=0;
            for(i=0;*(sub+i)!='\0';i++){
                if(*(str+j+i)!=*(sub+i))
                    ban=1;
            }
            if(ban==0){
                palabra.inicio=j;
                palabra.fin=j+i-1;
                return palabra;
            }
        }
    }
    palabra.inicio=-1;
    palabra.fin=-1;
    return palabra;
}

tNodo indices(char* sub){
    FILE* arch=fopen("frases.txt","r");
    tPalabra palabra;
    tNodo lista=NULL;
    char c,*pal;
    int i,linea=0;
    c=fgetc(arch);
    while(!feof(arch)){
        pal=malloc(sizeof(char));
        for(i=0;c!='\n';i++){
            *(pal+i)=c;
            pal=realloc(pal,sizeof(char)*(i+2));
            c=fgetc(arch);
        }
        *(pal+i)='\0';
        palabra=buscarSub(pal,sub);
        if(palabra.inicio!=-1)
            agregar(&lista,palabra.inicio,palabra.fin,linea);
        linea++;
        free(pal);
        c=fgetc(arch);
    }
    return lista;
}

void agregar(tNodo* lista,int ini,int fin,int linea){
    if (*lista==NULL){
        *lista=malloc(sizeof(tNodo));
        (*lista)->linea=linea;
        (*lista)->inicio=ini;
        (*lista)->fin=fin;
        (*lista)->sig=NULL;
    }
    else{
        agregar(&(*lista)->sig,ini,fin,linea);
    }
}

void recorrer(tNodo nodo){
	if (nodo!=NULL){
		printf("(%d,%d,%d)\n",(*nodo).linea,(*nodo).inicio,(*nodo).fin);
		recorrer(nodo->sig);
	}
}
