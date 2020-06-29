#include <stdio.h>
#include <stdlib.h>

/**                    3.1  febrero 2013**/
/**
struct s_usuarios{
    int ID_usuario;
    char nombre[60];
    char sexo;
    int edad;
};
struct sArbol{
    struct s_usuarios a;
    struct sArbol* izq;
    struct sArbol* der;
};
typedef struct sArbol* tArbol;
void insertarenarbol(tArbol* arbol,struct s_usuarios amigo);
void agregarArbolF(int id,char sexo,tArbol* arbol);
void agregarArbolF(int id,char sexo,tArbol* arbol){
    FILE*arch=NULL;//rewind(archB)
    FILE*archB=NULL;
    arch=fopen("amigos.txt","r");
    archB=fopen("usuarios.dat","rb");
    //arhivo normal
    int c,c2;
    struct s_usuarios amigo;
    fscanf(arch,"%d,",&c);
    while(c!=EOF){
        fscanf(arch,"%d\n",&c2);
        if(c==id || c2==id)
        {
            if(c==id){//c necesita un amigo que es C2
                fread(&amigo,sizeof(struct s_usuarios),1,archB);
                while(!feof(archB)){
                    if(amigo.ID_usuario==c2){
                        if(amigo.sexo==sexo){
                            insertarenarbol(arbol,amigo);
                        }
                    }
                    fread(&amigo,sizeof(struct s_usuarios),1,archB);
                }
            }
            else{//c2 necesita un amigo que es C
                fread(&amigo,sizeof(struct s_usuarios),1,archB);
                while(!feof(archB)){
                    if(amigo.ID_usuario==c){
                        if(amigo.sexo==sexo){
                            insertarenarbol(arbol,amigo);
                        }
                    }
                    fread(&amigo,sizeof(struct s_usuarios),1,archB);
                }
            }
            rewind(archB);
        }
    }
}
void insertarenarbol(tArbol* arbol,struct s_usuarios amigo){
    if(*arbol==NULL){
        arbol=malloc(sizeof(tArbol));
        (*arbol)->a=amigo;
        (*arbol)->izq=NULL;
        (*arbol)->der=NULL;
    }else{
        if(((*arbol)->a).ID_usuario<amigo.ID_usuario){
            insertarenarbol(&(*arbol)->izq,amigo);
        }else{
            insertarenarbol(&(*arbol)->der,amigo);
        }
    }
}
**/
/**                     3.2 un while que va comparando si mis amigos son amigos de mis amigos         **/
