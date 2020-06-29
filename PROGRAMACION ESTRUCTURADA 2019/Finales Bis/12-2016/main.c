#include <stdio.h>
#include <stdlib.h>

struct s_comision{
    int nro_registro;
    char* nombre;
    char* apellido;
};
typedef struct s_comision t_comision;

int main()
{
    printf("Hello world!\n");
    return 0;
}

void unificar(char* AM,char* BM){
    FILE* archA=fopen(AM,"r");
    FILE* archB=fopen(BM,"r");
    int reg,i;
    char* ap,*nom;
    t_comision comA;
    fscanf(archA,"%d,",&reg);
    while(!feof(archA)){
        nom=malloc(sizeof(char));
        c=fgetc(archA);
        for(i=0;c!=',';i++){
            *(nom+i)=c;
            c=fgetc(archA);
            nom=realloc(nom,sizeof(char)*(i+2));
        }
        *(nom+i)='\0';
        ap=malloc(sizeof(char));
        c=fgetc(archA);
        for(i=0;c!='\n';i++){
            *(ap+i)=c;
            c=fgetc(archA);
            ap=realloc(ap,sizeof(char)*(i+2));
        }
        *(ap+i)='\0';
        comA.nro_registro=reg;
        comA.nombre=nom;
        comA.apellido=ap;
        agregar();
        fscanf(archA,"%d,",&reg);
        free(nom);
        free(ap);
    }
    fscanf(archB,"%d,",&reg);
    while(!feof(archB)){
        nom=malloc(sizeof(char));
        c=fgetc(archB);
        for(i=0;c!=',';i++){
            *(nom+i)=c;
            c=fgetc(archB);
            nom=realloc(nom,sizeof(char)*(i+2));
        }
        *(nom+i)='\0';
        ap=malloc(sizeof(char));
        c=fgetc(archB);
        for(i=0;c!='\n';i++){
            *(ap+i)=c;
            c=fgetc(archB);
            ap=realloc(ap,sizeof(char)*(i+2));
        }
        *(ap+i)='\0';
        comA.nro_registro=reg;
        comA.nombre=nom;
        comA.apellido=ap;
        if(esta()==0){
            agregar();
        }
        fscanf(archA,"%d,",&reg);
        free(nom);
        free(ap);
    }
    fclose(archA);
    fclose(archB);
}

void inorder(t_nodo_bin arbol,FILE* arch){
    if (arbol!=NULL){
        inorder(arbol->izq);
        fprintf(arch,"%d,",(arbol->valor).nro_registro);
        fwrite((arbol->valor).nombre,sizeof(char),1,arch);
        fprintf(arch,",");
        fwrite((arbol->valor).apellido,sizeof(char),1,arch);
        fprintf(arch,"\n");
    }
}
