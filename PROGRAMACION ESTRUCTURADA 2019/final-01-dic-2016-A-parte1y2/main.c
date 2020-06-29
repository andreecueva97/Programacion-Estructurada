#include <stdio.h>
#include <stdlib.h>
/**                           1.1 **/
/**
int sumPares(int*arr);
int*cargarArr();
int main()
{
    printf("FINAL-01-DIC-2016A!\n");
    int*arregloNum;
    arregloNum=cargarArr();
    printf("\n imprimo la 1 posicion es %d",*arregloNum);
    printf("\n\n");
    printf("\n imprimo sumPares que es %d",sumPares(arregloNum));
    return 0;
}
int* cargarArr(){
    int *arr=NULL,i=0,n=0;
    arr=malloc(sizeof(int));//NO es necesario usar (*int)malloc...
    printf("ingrese numeros: ");
    scanf("%d",&n);
    *(arr+i)=n;
    while(n!=0){
        printf("ingrese numeros");
        scanf("%d",&n);
        i++;
        arr=realloc(arr,sizeof(int)*(i+2));
        *(arr+i)=n;
    }
    return arr;
}
            //               1.2
int sumPares(int *arr){
    if((*arr)!=NULL){
        if((*arr)%2==0){
            return *arr+sumPares(arr+1);
        }
        else{
            return 0+sumPares(arr+1);
        }
    }
    return 0;
}
**/
/**                          2.1        e ) 0      **/
/**
int main(){
    unsigned char a=1;
    unsigned int i;

    for(i=0;i<8;i++){
        a=a&(1<<i);
    }
    printf("\n%d",a);
}
**/
/**                          2.2            a)   b      **/
/**
char f(char a){
    if(a<'c'){
        f(a+1);
    }
    else{
        if(a=='b')
            f(a+1);
    }
    return a;
}
void main(){
    printf("%c",f('b'));
}
**/
/**                           2.3     e) error             **/
/**
int main(){
    int*p=NULL;              //no pedi malloc
    (*p)=10;
    printf("%d",*(p)+1);
    return 0;
}
**/
/**                          2.4      e)  14               **/
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
