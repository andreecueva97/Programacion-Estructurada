#include <stdio.h>
#include <stdlib.h>
/**                   1.1                  **/
/**
int*minimoDir(int *v);
int* cargarArr();
int main()
{
    printf("final-02-dic-2017-B-parte1y2!\n");
    int*arr;
    arr=cargarArr();
    printf("hola");
    printf("\nEl valor de minima direccion es %d ",*(minimoDir(arr)));
    printf("\nLa minima direccion es %p ",minimoDir(arr));
    return 0;
}
int* cargarArr(){
    int*aux=NULL;
    int n,i=0;
    printf("\ningrese un numero:");
    scanf("%d",&n);
    aux = malloc(sizeof(int));
    *(aux+i)=n;
    while(n!=0){
        aux=realloc(aux,sizeof(int)*(i+2));
        printf("\ningrese un numero:");
        scanf("%d",&n);
        i++;
        *(aux+i)=n;
    }
    return aux;
}
int*minimoDir(int *v){
    int *actual;actual=v;
    int *ant=NULL;
    int *devolver=NULL;
    if(*v!=0){
        ant=minimoDir(v+1);
        if(ant==NULL){
            devolver = actual;
        }else{
            if(*ant<*v){
                devolver=ant;
            }
            else{
                devolver=actual;
            }
        }
    }
    return devolver;
}
**/
/**                         1.2                    **/
/**
int bit(unsigned int n);
int main(){
    printf("%d",bit(0));
    return 0;
}
int bit(unsigned int n){
    unsigned int mask1=3;
    unsigned int mask2=3<<30;
    if(((mask1|mask2)^n)==0)   o  ((mask1|mask2)==n)
        return 1;
    else
        return 0;
}
**/
/**                 2.1          e) 6       **/
/**
void sum(int arr[]){
    arr[0]=arr[0]+3;
}
void resta(int a){
    a=a-4;
}
int main(){
    int a[3]={3,2,13};int num=0;
    sum(a);
    resta(num);
    printf("%d",a[0]+num);
    return 0;
}**/
/**                2.2           e)14        **/
/**
void f(){
    int a=9,b=13;
    int *bb,**cc;
    bb=&b;
    cc=&bb;
    printf("%d",*bb+1);
}
int main(){
    f();
    return 0;
}**/
/**               2.3      e)error ejecucion  **/
/**
int main(){
    int* p=NULL;
    (*p)=10;
    printf("%d",*(p)+1);
    return 0;
}**/
/**               2.4        e) 81  **/
/**int foo(int n, int m){
    int miFoo=1;
    if(m>0){
        miFoo=n*foo(n,m-1);
    }
    return miFoo;
}
int main(){
    printf("%d",foo(3,4));
    return 0;
}**/



