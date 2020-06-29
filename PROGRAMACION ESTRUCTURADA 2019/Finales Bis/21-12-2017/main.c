#include <stdio.h>
#include <stdlib.h>


struct s_nota{
    int valor;
    struct s_nota* sig;
};typedef struct s_nota* t_nota;

struct s_alu{
    char* apellido;
    t_nota lstNota;
    struct s_alu* sig;
};typedef struct s_alu* t_alu;

struct sProm{
    char* apellido;
    double promedio;
};typedef struct sProm* tProm;

struct sComision{
    int registro;
    char* nombre;
    char* apellido;
};typedef struct sComision tComision;

struct sNodoBin{
    tComision dato;
    struct sNodoBin* izq;
    struct sNodoBin* der;
};typedef struct sNodoBin* tNodoBin;

void inorder(tNodoBin arbol,FILE* arch);
void unificar(char* am,char* bm);
void agregar(tNodoBin* arbol,tComision valor);
int esta(tNodoBin arbol,int valor);

int main()
{
    char* am="comisionAM.txt";
    char* bm="comisionBM.txt";
    unificar(am,bm);
    return 0;
}

void unificar(char* am,char* bm){
    FILE* archA=fopen(am,"r");
    FILE* archB=fopen(bm,"r");
    int reg,i;
    char c;
    tNodoBin arbol=NULL;
    tComision comision;
    fscanf(archA,"%d,",&reg);
    while (!feof(archA)){
        comision.registro=reg;
        c=fgetc(archA);
        comision.nombre=malloc(sizeof(char));
        for(i=0;c!=',';i++){
            comision.nombre[i]=c;
            i++;
            comision.nombre=realloc(comision.nombre,sizeof(char)*(i+1));
            c=fgetc(archA);
        }
        comision.nombre[i]='\0';
        c=fgetc(archA);
        comision.apellido=malloc(sizeof(char));
        for(i=0;c!='\n';i++){
            comision.apellido[i]=c;
            i++;
            comision.apellido=realloc(comision.apellido,sizeof(char)*(i+2));
            c=fgetc(archA);
        }
        comision.apellido[i]='\0';
        agregar(&arbol,comision);
        fscanf(archA,"%d,",&reg);
    }
    fclose(archA);
    fscanf(archB,"%d,",&reg);
    while (!feof(archB)){
        comision.registro=reg;
        c=fgetc(archB);
        comision.nombre=malloc(sizeof(char));
        for(i=0;c!=',';i++){
            comision.nombre[i]=c;
            i++;
            comision.nombre=realloc(comision.nombre,sizeof(char)*(i+1));
            c=fgetc(archB);
        }
        comision.nombre[i]='\0';
        c=fgetc(archB);
        comision.apellido=malloc(sizeof(char));
        for(i=0;c!='\n';i++){
            comision.apellido[i]=c;
            i++;
            comision.apellido=realloc(comision.apellido,sizeof(char)*(i+1));
            c=fgetc(archB);
        }
        comision.apellido[i]='\0';
        if(esta(arbol,reg)==0)
            agregar(&arbol,comision);
        fscanf(archB,"%d,",&reg);
    }
    FILE* arch=fopen("comisionABM.txt","w");
    inorder(arbol,arch);
}

void agregar(tNodoBin* arbol,tComision valor){
    if (*arbol==NULL){
        *arbol=malloc(sizeof(struct sNodoBin));
        (*arbol)->dato=valor;
        (*arbol)->izq=NULL;
        (*arbol)->der=NULL;
    }
    else{
        if (valor.registro<((*arbol)->dato).registro)
            agregar(&(*arbol)->izq,valor);
        else
            agregar(&(*arbol)->der,valor);
    }
}

int esta(tNodoBin arbol,int valor){
    if (arbol==NULL)
        return 0;
    else{
        if (valor==((*arbol).dato).registro)
            return 1;
        else{
            if (valor<(((*arbol).dato).registro))
                return esta(arbol->izq,valor);
            else
                return esta(arbol->der,valor);
        }
    }
}

void inorder(tNodoBin arbol,FILE* arch){
    if (arbol!=NULL){
        inorder(arbol->izq,arch);
        fprintf(arch,"%d,",((*arbol).dato).registro);
        int i;
        for(i=0;((*arbol).dato).nombre[i]!='\0';i++)
            fprintf(arch,"%c",((*arbol).dato).nombre[i]);
        fprintf(arch,",");
        for(i=0;((*arbol).dato).apellido[i]!='\0';i++)
            fprintf(arch,"%c",((*arbol).dato).apellido[i]);
        fprintf(arch,"\n");
        inorder(arbol->der,arch);
    }
}

void listado(t_alu alumno){
    tProm promedios;
    promedios=malloc(sizeof(struct sProm));
    int cont=0;
    recorrer(alumno,promedios,cont);

}

void recorrer(tNodo nodo,promedios,cont){
	if (nodo!=NULL){
        int i;
        for(i=0;(nodo->valor).lstNota)
		(nodo->valor).lstNota
		recorrer(nodo->sig);
	}
}
