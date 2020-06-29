#include <stdio.h>
#include <stdlib.h>
struct a{
    char ape[50];
    char nom[50];
    int cod;
}typedef struct a actores;
struct b{
    int codPeli;
    char nomPeli[80];
    int anio;
}typedef struct b peliculas;
struct c{
    int codPeli;
    int codActor;
}typedef struct b peliculas_actores;

int main()
{
    printf("Hello world!\n");
    return 0;
}

void fun(int codActor){
    actores *actoress;
    peliculas *peliculass;
    peliculas_actores *pa;
    int r,i=2,j=1;
    FILE*arch;
    arch=fopen("actores.dat","rb");
    actores=malloc(sizeof(struct a));
    r=fread(actores,sizeof(struct a),1,arch);
    while(!feof(arch)){
        actores=realloc(actores,sizeof(struct a)*i);
        r=fread(actores+j,sizeof(struct a),1,arch);
        i++;j++;
    }
    fclose();
    int *arr=NULL;int cont;
    i=0,e=0,a=0;
    while(*(pa+i).codPeli!=0){
        if(*(pa+i).codActor==codActor){
            cont=0;
            while(*(pa+e).codPeli!=0){
                    if(*(pa+e).codPeli == *(pa+i).codActor){
                        cont++;
                    }
                    e++;
            if (cont==1){
                if(*arr==NULL){
                    arr=malloc(sizeof(char))
                    *arr=*(pa+i).codPeli;
                    a++;
                }
                else{
                    arr=realloc(arr,sizeof(char)*(a+2));
                    *(arr+a)=*(pa+i).codPeli;
                    a++;
                }
            }
        }
        *(arr+a)=0;
    }
    int b=0,t=0;
    while(*(arr+t)!=0){
            while((*(peliculas+b).codPeli!=0){
                if(*(peliculas+b).codPeli==*(arr+t)){
                    printf("%s y %d",//....);
                  }
          }
    }

}

void fun2(char apell[50],int codActor,int anio){
    int i,e;
    for(i=0;(*(pa+i))!=0;i++)
    {
        if(*(pa+i).codActor==codActor){
            for(e=0;(*(peliculass+e))!=0;e++){
                if(*(peliculass+e).codPeli==*(pa+i).codPeli){
                    if(*(peliculass+e).anio>anio){
                        printf()//
                    }
                }
            }
        }

    }
}
