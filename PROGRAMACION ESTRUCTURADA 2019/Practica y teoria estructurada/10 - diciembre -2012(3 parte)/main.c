#include <stdio.h>
#include <stdlib.h>
struct banda{
    int codbanda;char nombre[30],integrantes[100];int cantdiscos;
};
struct discoxbanda{
    int codbanda,disco;
};
void actualizar(){
    struct banda *datos;
    FILE* archBand=fopen("Bandas.dat","r+b");
    FILE* archDiscoxBanda=fopen("discoxbanda.txt","r");
    datos=malloc(sizeof(struct banda));
    fread(datos,sizeof(struct banda),1,archBand);
    int cont,n,i=0;
    while(!feof(archBand)){
        cont=0;
        while(!feof(archDiscoxBanda)){
            fscanf(archDiscoxBanda,"%d,",&n);
            if(n==datos[i].codbanda){
                cont++;
            }
        }
        datos[i].cantdiscos=cont;
        rewind(archDiscoxBanda);
        i++;
        datos=realloc(datos,sizeof(struct banda)*(i+1));
        fread(datos,sizeof(struct banda),1,archBand);
    }
    //datos[i].codbanda=0;
    fclose(archDiscoxBanda);
    rewind(archBand);
    fwrite(datos,sizeof(struct banda),i-1,archBand);
}
