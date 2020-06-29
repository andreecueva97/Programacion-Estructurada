#include <stdio.h>
#include <stdlib.h>
/**
struct datos{
    int id;
    char nombre[200];
    int promedio;
    int minalt;
    int maxalt;
};
struct max{
    struct datos a;
    struct max* sig;
};
typedef struct max* m;
int sum(t_altu listaalturas);
int promedio(t_altu listaalturas);
void maxCinco(int n,int anio);
void maxCinco(int n,int anio){
    m* lista;
    FILE *archalturas=fopen("dfasdf","r");
    FILE *archcotas;
    FILE *archlocalidades;
    int id,id2,sum,cantidad,altura,amd;double prom;char*arr,*arrguarda;
    fscanf(archalturas,"%d,",&id);
    while(!feof(archalturas)){
        archcotas=fopen("dfasdf","r");
        archlocalidades=fopen("dfasdf","r");
        sum=0;cantidad=0;
        if(lista==NULL || estaenlista(lista,id)==false){
            while(!feof(archalturas)){
                fscanf(archalturas,"%d,",&altura);
                fscanf(archalturas,"%d\n",&amd);
                if(anio==((amd<<2)){
                    sum=sum+altura;
                    cantidad++;
                }
                fscanf(archalturas,"%d,",&id);
            }
        }
        prom=sum/cantidad;
        fscanf(archlocalidades,"%d,",&id2);
        while(!feof(archlocalidades)){
            fscanf(archlocalidades,"%s\n",&arr);
            if(id==id2){
               arrguarda=arr;
            }
            fscanf(archlocalidades,"%s\n",&arr);
            fscanf(archlocalidades,"%d,",&id2);
        }
        fscanf(archcotas,"%d,",&id2);
        while(!feof(archlocalidades)){
            fscanf(archlocalidades,"%d,",);
            if(id==id2){
               arrguarda=arr;
            }
            fscanf(archlocalidades,"%d\n",&arr);
            fscanf(archlocalidades,"%d,",&id2);
        }
        insertar(&lista,);
        fclose(archcotas);
        fclose(archalturas);
        fclose(archlocalidades);
    }
}
**/
struct tupla{
    int ini;int fin;
};
struct tupla buscarSub(char* str, char* sub){
    struct tupla a;
    int ini=0,fin=0;
    int i=0,band=0;
    int ta,tam;
    for(tam=0;str[tam]!='\0';tam++);
    for(ta=0;sub[ta]!='\0';ta++);
    while(str[i]!='\0'){
        if(str[i]==sub[i]){
            ini=i;
            i++;
        }
        else{
            fin=i;
            band=1;
            i++
        }
        if(band==0){
            a.ini
        }
    }
}
