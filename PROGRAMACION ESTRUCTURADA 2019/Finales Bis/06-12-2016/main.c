#include <stdio.h>
#include <stdlib.h>

struct sVentas{
    int codigo;
    char mes[15];
    int tarjetas;
};typedef struct sVentas tVentas;

struct sVendedores{
    int codigo;
    char vendedor[30];
    int objetivo;
    double sueldo;
};typedef struct sVendedores tVendedores;

struct sNodoBin{
    tVendedores valor;
    struct sNodoBin* izq;
    struct sNodoBin* der;
};typedef struct sNodoBin* tNodoBin;

void agregar(tNodoBin* arbol,tVendedores dato);
void cargarArbolVendedores(tNodoBin* arbol,FILE* fVende);
int liquidar(tNodoBin arbol,int idVen);
void inorder(tNodoBin arbol);
tVendedores esta(tNodoBin arbol,int valor);
void crearBinario();

int main()
{
    FILE* fVende=fopen("vendedores.txt","r");
    tNodoBin arbol=NULL;
    cargarArbolVendedores(&arbol,fVende);
    crearBinario();
    liquidar(arbol,1);
    fclose(fVende);
    return 0;
}

void cargarArbolVendedores(tNodoBin* arbol,FILE* fVende){
    int cod,obj,i;
    double sueldo;
    char c;
    tVendedores vendedores;
    fscanf(fVende,"%d,",&cod);
    while(!feof(fVende)){
        vendedores.codigo=cod;
        c=fgetc(fVende);
        for(i=0;c!=',';i++){
            vendedores.vendedor[i]=c;
            c=fgetc(fVende);
        }
        vendedores.vendedor[i]='\0';
        fscanf(fVende,"%d,",&obj);
        vendedores.objetivo=obj;
        fscanf(fVende,"%lf\n",&sueldo);
        vendedores.sueldo=sueldo;
        agregar(arbol,vendedores);
        fscanf(fVende,"%d,",&cod);
    }
}

int liquidar(tNodoBin arbol,int idVen){
    FILE* archB=fopen("ventasTarjetas.dat","r+w");
    int sum=0;
    tVentas ventas;
    fread(&ventas,sizeof(tVentas),1,archB);
    while(!feof(archB)){
        if(ventas.codigo==idVen)
            sum=sum+ventas.tarjetas;
        fread(&ventas,sizeof(tVentas),1,archB);
    }
    tVendedores vendedor=esta(arbol,idVen);
    printf("Vendedor: %s\n",vendedor.vendedor);
    printf("Id: %d\n",idVen);
    printf("Tarjetas Vendidas: %d\n",sum);
    printf("Objetivo Anual: %d\n",vendedor.objetivo);
    fclose(archB);
    return 0;
}

void agregar(tNodoBin* arbol,tVendedores dato){
    if (*arbol==NULL){
        *arbol=malloc(sizeof(struct sNodoBin));
        (*arbol)->valor=dato;
        (*arbol)->izq=NULL;
        (*arbol)->der=NULL;
    }
    else{
        if (dato.codigo<((*arbol)->valor).codigo)
            agregar(&(*arbol)->izq,dato);
        else
            agregar(&(*arbol)->der,dato);
    }
}

void inorder(tNodoBin arbol){
    if (arbol!=NULL){
        inorder(arbol->izq);
        printf("%d ",((*arbol).valor).codigo);
        inorder(arbol->der);
    }
}

tVendedores esta(tNodoBin arbol,int valor){
    if (valor==((*arbol).valor).codigo){
        return (arbol->valor);
    }
    else{
        if (valor<((*arbol).valor).codigo)
            return esta(arbol->izq,valor);
        else
            return esta(arbol->der,valor);
    }
}

void crearBinario(){
    FILE* archBin=fopen("ventasTarjetas.dat","w+b");
    tVentas ventas;
    ventas.codigo=1;
    ventas.tarjetas=21;
    fwrite(&ventas,sizeof(struct sVentas),1,archBin);
    ventas.codigo=8;
    ventas.tarjetas=32;
    fwrite(&ventas,sizeof(struct sVentas),1,archBin);
    ventas.codigo=3;
    ventas.tarjetas=14;
    fwrite(&ventas,sizeof(struct sVentas),1,archBin);
    ventas.codigo=8;
    ventas.tarjetas=58;
    fwrite(&ventas,sizeof(struct sVentas),1,archBin);
    fclose(archBin);
}

