#include <stdio.h>
#include <stdlib.h>

struct sVentas{
    int codigo;
    char mes[15];
    int tarjetas;
};typedef struct sVentas tVentas;

struct sVendedores{
    int codigo;
    char nombre[15];
    int objetivo;
    double sueldo;
};typedef struct sVendedores tVendedores;

struct sNodoBin{
    tVendedores valor;
    struct sNodoBin* izq;
    struct sNodoBin* der;
};typedef struct sNodoBin* tNodoBin;

void crearArchBin();
int liquidar(tNodoBin arbol,int idVen);
void agregar(tNodoBin* arbol,tVendedores valor);
int cargarArbolVendedores(tNodoBin* arbol,FILE* fVende);
void inorder(tNodoBin arbol);
tVendedores esta(tNodoBin arbol,int valor);

int main()
{
    crearArchBin();
    FILE* fVende=fopen("vendedores.txt","r");
    tNodoBin arbol=NULL;
    cargarArbolVendedores(&arbol,fVende);
    inorder(arbol);         //imprimo el arbol ordenado (no es parte del ejercicio, es solo para comprobar que el arbol esta bien)
    printf("\n");
    liquidar(arbol,8);      //le mando el arbol con el codigo del vendedor
    fclose(fVende);
    return 0;
}

int cargarArbolVendedores(tNodoBin* arbol,FILE* fVende){
    tVendedores vendedor;
    int num;
    char c;
    double sueldo;
    fscanf(fVende,"%d,",&num);
    while(!feof(fVende)){
        vendedor.codigo=num;
        c=fgetc(fVende);
        for(num=0;c!=',';num++){
            vendedor.nombre[num]=c;
            c=fgetc(fVende);
        }
        vendedor.nombre[num]='\0';
        fscanf(fVende,"%d,",&num);
        vendedor.objetivo=num;
        fscanf(fVende,"%lf\n",&sueldo);
        vendedor.sueldo=sueldo;
        agregar(arbol,vendedor);
        fscanf(fVende,"%d,",&num);
    }
    return 0;
}

int liquidar(tNodoBin arbol,int idVen){
    FILE* arch=fopen("ventasTarjetas.dat","r+b");
    int cant=0;
    tVentas* ventas;
    ventas=malloc(sizeof(struct sVentas));
    fread(ventas,sizeof(struct sVentas),1,arch);
    while(!feof(arch)){
        if ((*ventas).codigo==idVen)
            cant=cant+(*ventas).tarjetas;
        fread(ventas,sizeof(struct sVentas),1,arch);
    }
    tVendedores vendedor=esta(arbol,idVen);
    printf("Vendedor: %s\n",vendedor.nombre);
    printf("Id: %d\n",idVen);
    printf("total De tarjetas Vendidas (anual): %d\n",cant);
    printf("Objetivo Anual: %d\n",vendedor.objetivo);
    fclose(arch);
    return 0;
}

void agregar(tNodoBin* arbol,tVendedores valor){
    if (*arbol==NULL){
        *arbol=malloc(sizeof(struct sNodoBin));
        (*arbol)->valor=valor;
        (*arbol)->der=NULL;
        (*arbol)->izq=NULL;
    }
    else{
        if (valor.codigo<((*arbol)->valor).codigo)
            agregar(&(*arbol)->izq,valor);
        else
            agregar(&(*arbol)->der,valor);
    }
}

void inorder(tNodoBin arbol){
    if (arbol!=NULL){
        inorder(arbol->izq);
        printf("%d,%s,%d,%.2lf\n",(arbol->valor).codigo,(arbol->valor).nombre,(arbol->valor).objetivo,(arbol->valor).sueldo);
        inorder(arbol->der);
    }
}

tVendedores esta(tNodoBin arbol,int valor){
    if (valor==(arbol->valor).codigo)
        return (arbol->valor);
    else{
        if (valor<(arbol->valor).codigo)
            return esta(arbol->izq,valor);
        else
            return esta(arbol->der,valor);
    }
}

void crearArchBin(){        //Creo el archivo binario, no hace falta completar el mes porque no lo uso
    FILE* archBin=fopen("ventasTarjetas.dat","w+b");
    tVentas* ventas;
    (*ventas).codigo=1;
    (*ventas).tarjetas=21;
    fwrite(ventas,sizeof(struct sVentas),1,archBin);
    (*ventas).codigo=8;
    (*ventas).tarjetas=32;
    fwrite(ventas,sizeof(struct sVentas),1,archBin);
    (*ventas).codigo=3;
    (*ventas).tarjetas=14;
    fwrite(ventas,sizeof(struct sVentas),1,archBin);
    (*ventas).codigo=8;
    (*ventas).tarjetas=58;
    fwrite(ventas,sizeof(struct sVentas),1,archBin);
    fclose(archBin);
}
