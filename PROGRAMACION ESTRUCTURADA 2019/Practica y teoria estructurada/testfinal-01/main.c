#include <stdio.h>
#include <stdlib.h>
/**   1.1 y 1.2 - 6 diciembre 2016
int* cargarArr();

int sumPares(int *arr);
int main()
{
    printf("Hello world!\n");
    int*arr=NULL;
    arr=cargarArr();
    printf("%d",sumPares(arr));
    printf("%d",arr[0]);
    return 0;
}

int* cargarArr(){
    int* arr=NULL,i=0,n=0;
    arr=malloc(sizeof(int));
    printf("\ningrese numeros: ");
    scanf("%d",&n);
    *(arr+i)=n;
    while(n!=0){
        printf("\ningrese numeros: ");
        scanf("%d",&n);
        i++;
        arr=realloc(arr,sizeof(int)*(i+1));
        *(arr+i)=n;
    }
    return arr;
}
int sumPares(int *arr){
    if((*arr)!= 0){
        if((*arr)%2==0){
            return 1+sumPares(arr+1);
        }
        else{
            return 0+sumPares(arr+1);
        }
    }
    return 0;
}**/
/** 2.1  e)0

    2.2  a)b

    2.3  e)error de ejecucion

    2.4  e)14

**//**
int* cargarArr();
int* minimoDir(int *v);
int main()
{
    printf("Hello world!\n");
    int*arr=NULL;
    arr=cargarArr();
    printf("%d",*(minimoDir(arr)));
    return 0;
}

int* cargarArr(){
    int* arr=NULL,i=0,n=0;
    arr=malloc(sizeof(int));
    printf("\ningrese numeros: ");
    scanf("%d",&n);
    *(arr+i)=n;
    while(n!=0){
        printf("\ningrese numeros: ");
        scanf("%d",&n);
        i++;
        arr=realloc(arr,sizeof(int)*(i+1));
        *(arr+i)=n;
    }
    return arr;
}

int* minimoDir(int *v){
    int*min,*actual;
    actual=v;
    min=v;
    if(*v!=0){
        min=minimoDir(v+1);
        if(*min==0){
            min=actual;
        }
        else{
            if(*actual<*min)
                min=actual;
        }
    }
    return min;
}**//**
int bit(unsigned int n);
int main(){
    printf("%d",bit(1));
    return 0;
}
int bit(unsigned int n){
    unsigned int mask1=3;
    unsigned int mask2=3<<30;
    if(n&(mask1|mask2)==(mask1|mask2)
        return 1;
    else
        return 0;
}**/
/**2,1 e)6

   2,2 e)14

   2,3 e)error ejecucion

   2,4 e)81
**/
/****/
/**
void cargarString(char** str){
    int i=0;char aux="";
    *str=malloc(sizeof(char));
    aux=getche();
    while(aux!='\r'){
        *(str[i])=aux;
        i++;
        *str=realloc(*str,sizeof(char)*(i+1));
        aux=getche();
    }
    *(str[i])='\0';
}
void ordenar(t_per** per){
    int i=0;j=0;t_per aux;
    for(i=0;*(per[i]).dni!=0;i++){
        for(j=i+1;*(per[j]).dni!=0;j++){
            if(*(per[i]).dni<*(per[j]).dni){
                aux=per[i];
                per[i]=per[j];
                per[j]=aux;
            }
        }
    }
}
**/
/**
    2.1)27

    2.2)1,0

    2.3)no imprime

    2.4)0

**//**
int*minimoDir(int* v){
    int *min,*x,*m;
    x=v;
    min=x;
    if(*v!=0){
        v++;
        m=minimoDir(v);
        if(*m<*min && *m!=0){
            min=m;
        }
    }
    return min;
}
int bit(unsigned int n){
    unsigned int mask1=7;
    unsigned int mask2=7<<29;
    if(n&(mask1|mask2) == (mask1|mask2))
        return 1;
    else
        return 0;
}

    2.1)   7

    2.2)   22

    2.3)   ejecucion

    2.4)   h

**//**
int main()
{

int a=1;
int *uno=NULL, dos=0;
uno = a;
//dos= *(uno + *uno);
printf("dos: %d\n",*uno);
return 0;
}**/
struct datos{
    int cod;
    char peli[80];
    int anio;
};
void trabajaronjuntos(int actor1,int actor2){
    int*arr=NULL;int*arr2=NULL,int*arr3=NULL;
    arr=malloc(sizeof(int));
    int n,m,i=0;
    FILE*arch3=fopen("peliculas_Actores.txt","r");
    fscanf("%d,%d\n",&n,&m);
    while(!feof(arch3)){
        if(m==actor1){
            arr[i]=n;
            arr=realloc(arr,sizeof(int)*(i+2));
        }
        i++;
        fscanf("%d,%d\n",&n,&m);
    }
    arr[i]=0;
    rewind(arch3);
    i=0;
    fscanf("%d,%d\n",&n,&m);
    while(!feof(arch3)){
        if(m==actor1){
            arr2[i]=n;
            arr2=realloc(arr2,sizeof(int)*(i+2));
        }
        i++;
        fscanf("%d,%d\n",&n,&m);
    }
    arr2[i]=0;
    fclose(arch3);
    i=0;
    arr3=malloc(sizeof(int));
    int k=0;
    while(arr[i]!=0){
        e=i;
        while(arr2[e]!=0){
            if(arr2[e]==arr[i]){
                arr3[k]=arr2[e];
                arr3=realloc(arr3,sizeof(int)*(k+2));
                k++;
            }
        }
    }
    arr[k]=0;
    i=0;
    FILE*peli=NULL;peli=fopen("peliculas.dat","rb");
    struct datos datos;
    fread(&datos,sizeof(struct datos),1,peli);
    while(arr[i]!=0){
        if(datos.cod==arr[i]){
            //imprime
            i++;
            rewind(peli);
            fread(&datos,sizeof(struct datos),1,peli);
        }
        else{
            fread(&datos,sizeof(struct datos),1,peli);
        }

    }
    fclose(peli);
}

