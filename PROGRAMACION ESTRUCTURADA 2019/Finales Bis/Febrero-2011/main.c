#include <stdio.h>
#include <stdlib.h>

struct sPeliculas{
    int codigo;
    char nombre;
    int anio;
};typedef struct sPeliculas tPeliculas;

void peliculas(int codAct);
void crearBinario();

int main()
{
    crearBinario();
    peliculas(5);
    return 0;
}

void peliculas(int codAct){
    FILE* fPeli=fopen("Peliculas.dat","r+b");
    FILE* fPeliAct=fopen("Peliculas_Actores.txt","r");
    tPeliculas pelicula;
    int pel,act,*pAct=NULL,i=0;
    pAct=malloc(sizeof(int));
    int r=fscanf(fPeliAct,"%d,%d\n",&pel,&act);
    while(r!=EOF){
        if (codAct==act){
            *(pAct+i)=pel;
            i++;
            pAct=realloc(pAct,sizeof(int)*(i+2));

        }
        r=fscanf(fPeliAct,"%d,%d\n",&pel,&act);
        printf("%d\n",pel);
    }
    *(pAct+i)=0;
    rewind(fPeliAct);
    for(i=0;*(pAct+i)!=0;i++){
        int ban=0;
        fscanf(fPeliAct,"%d,%d\n",&pel,&act);
        while(!feof(fPeliAct)){
            if(pel==*(pAct+i))
                ban++;
            fscanf(fPeliAct,"%d,%d\n",&pel,&act);
        }
        rewind(fPeliAct);
        if (ban==1){
            tPeliculas pelicula;
            fread(&pelicula,sizeof(tPeliculas),1,fPeli);

            while(!feof(fPeli)){
                if(pelicula.codigo==*(pAct+i)){
                    printf("%c,",pelicula.nombre);
                    printf("%d\n",pelicula.anio);
                }
                fread(&pelicula,sizeof(tPeliculas),1,fPeli);
            }

            rewind(fPeli);
        }
    }
    fclose(fPeliAct);
    fclose(fPeli);
}

void crearBinario(){
    FILE* archBin=fopen("Peliculas.dat","w+b");
    tPeliculas ventas;
    ventas.codigo=1;
    ventas.nombre='J';
    ventas.anio=1998;
    fwrite(&ventas,sizeof(tPeliculas),1,archBin);
    ventas.codigo=8;
    ventas.nombre='P';
    ventas.anio=1997;
    fwrite(&ventas,sizeof(tPeliculas),1,archBin);
    ventas.codigo=3;
    ventas.nombre='T';
    ventas.anio=2000;
    fwrite(&ventas,sizeof(tPeliculas),1,archBin);
    ventas.codigo=9;
    ventas.nombre='C';
    ventas.anio=1990;
    fwrite(&ventas,sizeof(tPeliculas),1,archBin);
    fclose(archBin);
}
