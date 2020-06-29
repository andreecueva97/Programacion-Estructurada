#include <stdio.h>
#include <stdlib.h>
//2017 diciembre 21
//int* minimoDir(int *v);

//int bit(unsigned int n);

//void sum(int arr[]);
//void resta(int a);


//void f();
int foo(int n,int m);
int main()
{
    printf("Hello world!\n");
    //MINIMODIR
    /*int *v=malloc(sizeof(int)*4);
    *v=1;*(v+1)=3;*(v+2)=2;*(v+3)=0;
    printf("el primer numero es %d",*v);
    printf("\nel primer numero es%d",*(minimoDir(v)));

    //BIT
    int n=3;
    printf("\nbit es %d\n",bit(n));
    return 0;
*/
    //choice 2.1        opcion e) 6
    //int a[3]={3,2,3};int num=0;
    //sum(a);
    //resta(num);
    //printf("\n %d",a[0]+num);
    //choice 2.2
    //f();
    //choice 2.3 e)error ejecucion le faltap=malloc(sizeof(char));
    /*int *p=NULL;

    (*p)=10;
    printf("%d",*(p)+1);*/
    //printf("%d",foo(3,4));
    return 0;
}
//choice 2.2     e)14
/*void f(){
    int b=13,a=3;
    int *bb,**cc;
    bb=&b;
    cc=&bb;
    printf("%d",*bb+1);
    printf("\n%d",cc);
}*/
/* choice 2.4             e)81
int foo(int n,int m){
    int miFoo=1;
    if(m>0){
        miFoo=n*foo(n,m-1);
    }
    return miFoo;
}

*/


//choice 2.1
//void sum(int arr[]){
//    arr[0]=arr[0]+3;
//}
//void resta(int a){
//    a=a-4;
//}
/*
int* minimoDir(int*v){
    int *valactual=v;
    int *valdevolver=NULL;
    int *valanterior=NULL;
    if(*v!=0){
        valanterior=minimoDir(v+1);
        if(valanterior==NULL){
            valdevolver=valactual;
        }
        else{
            if(*valactual>*valanterior){
                valdevolver=valanterior;
            }
            else{
                valdevolver=valactual;
            }
        }
    }
    return valdevolver;
}

int bit(unsigned int n){
    unsigned int mask1=1^(1<<1);
    printf("\n%d",mask1);
    unsigned int mask2=3<<23;//cuidado con los bits
    printf("\n%d",mask2);
    printf("\n%d",mask1^mask2);
    if((mask1^mask2)==n)//si es correcto
        return 1;
    else
        return 0;
}*/
