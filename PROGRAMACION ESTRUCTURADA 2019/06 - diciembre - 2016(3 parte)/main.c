#include <stdio.h>
#include <stdlib.h>/**
int doble(double valor);
int main()
{
    printf("%d\n",doble(1.7));
    return 0;
}
int doble(double valor){
    int entero;

    entero=(((unsigned int)((int)valor-valor)&(((int)valor)<<16))>>8)<<24;

    return entero;
}**/
/**              error ejecucion
int main(){
    char*ptrA="Juan";
    char*ptrB="Pedro";

    ptrA=ptrA+ptrB;

    printf("%s",ptrA);
}**//**
void funcion(int matriz[3][3])
{
    int f,c;

    for(f=0;f<3;f++){
        for(c=f;c<3;c++){
            matriz[f][c]=matriz[c][f];
        }
    }

}
int main(){
    int matriz[3][3]={{1,2,3},{3,4,5},{5,6,7}};
    funcion(matriz);
    int f,c;
    for(f=0;f<3;f++){
        for(c=0;c<3;c++){
            printf("%d",matriz[c][f]);
        }
    }
    return 0;
}**//**
int recursion(int valor){
    if(valor>0){
        return recursion(valor-1)+1;
    }
    else{
        return 0;
    }
}
int main(){
    int a=3;
    printf("%d",recursion(a));
    return 0;
}**/
/**               3.1       FUNCIONA         **/
/**
struct svende{
    int cod;
    char nombre[30];
    int obj;
    double sueldoAnual;
};
struct s_nodo{
    struct svende vendedor;
    struct s_nodo*izq;
    struct s_nodo*der;
};typedef struct s_nodo* t_nodo;
void agregar(t_nodo* arbol,struct svende vendedores);
void cargarArbolVendedores(t_nodo*arbol,FILE* arch){
    struct svende vendedores;
    int cod,r,i,c;double s;
    r= fscanf(arch,"%d,",&cod);
    vendedores.cod=cod;
    while(r!=EOF){
        c=fgetc(arch);i=0;
        while(c!=','){
            (vendedores.nombre)[i]=c;
            c=fgetc(arch);
            i++;
        }
        (vendedores.nombre)[i]='\0';
        r= fscanf(arch,"%d,",&cod);
        vendedores.obj=cod;
        fscanf(arch,"%lf\n",&s);
        vendedores.sueldoAnual=s;
        agregar(arbol,vendedores);
        r= fscanf(arch,"%d,",&cod);
    }
    fclose(arch);
}

void agregar(t_nodo* arbol,struct svende vendedores){
    if(*arbol==NULL){
        arbol=malloc(sizeof(struct s_nodo));
        (*arbol)->vendedor=vendedores;
        (*arbol)->izq=NULL;
        (*arbol)->der=NULL;
    }
    else{
        if(vendedores.cod <((*arbol)->vendedor).cod){
            agregar(&(*arbol)->izq,vendedores);
        }else{
            agregar(&(*arbol)->der,vendedores);

        }
    }
}
**/
/**             3.2         FUNCIONA    **/
/**
struct svende{
    int cod;
    char nombre[30];
    int obj;
    double sueldoAnual;
};
struct s_nodo{
    struct svende vendedor;
    struct s_nodo*izq;
    struct s_nodo*der;};
typedef struct s_nodo* t_nodo;
void buscar(t_nodo arbol,int idVen);
void liquidar(t_nodo arbol,int idVen){
    FILE* archbinario;
    archbinario=fopen("ventasTarjetas.dat","rb");
    int sumTarj=0,cod,sum=0;char m[15];
    fread(&cod,sizeof(int),1,archbinario);
    while(!feof(archbinario)){
        fread(&m,sizeof(char),15,archbinario);
        fread(&sumTarj,sizeof(int),1,archbinario);
        if(cod==idVen)
        {
            sum=sum+sumTarj;
        }
        fread(&cod,sizeof(int),1,archbinario);
    }
    printf("total de tarjetas vendidas %d",sum);
    buscar(arbol,idVen);
}
void buscar(t_nodo arbol,int idVen){
    if(arbol!=NULL){
        buscar((arbol)->izq,idVen);
        buscar((arbol)->der,idVen);
    }
    else if(idVen==((arbol)->vendedor).cod){
        printf("hola soy marcos");//
    }

}**/
