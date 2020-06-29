#include <stdio.h>
#include <stdlib.h>
//1.1
/*
int *cargarArr();
int* minimoDir(int*);
int main()
{
    printf("Hello world!\n");
    printf("\n");
    int *v;
    v=cargarArr();
    //int *v=malloc(sizeof(int)*4);
    printf("%d",*minimoDir(v));
    return 0;
}

int* minimoDir(int*v){
    int *min,*x,*m;
    x=v;
    min=x;
    if(*v!=0){
        v++;
        m=minimoDir(v);
        if((*x>*m) && (*m!=0)){
            min=m;
        }
    }
    return min;
}
int *cargarArr(){
    int *arr=NULL,i=0,n=0;
    arr=malloc(sizeof(int));
    printf("Ingrese numeros: ");
    scanf("%d",&n);
    *(arr)=n;
    while (n!=0){
        printf("Ingrese numeros: ");
        scanf("%d",&n);
        i++;
        arr=realloc(arr,sizeof(int)*(i+1)) ;
        *(arr+i)=n;
    }
    return arr;
}
*/
/*   1.2
int bit(unsigned int);
int main()
{
    printf("Hello world!\n");
    printf("\n%d",bit(29360136));
    return 0;
}


int bit(unsigned int n){//3 unos a la derecha 3 unos de la izq
    unsigned int mask1=3 ^(1<<2);     //00000000000111
    unsigned int mask2=(3<<23) ^(1<<22);//11100000000000
    if(n&(mask1|mask2)== n){
        return 1;
    }
    else{
        return 0;
    }
}
*/
//  2.1       d)7
/*
void sum(int arr[]);
void resta(int a);

int main(){
    int a[3]={3,2,13};int num=1;
    sum(a);        //arr[0]=6;
    resta(num);   //no sirve de nada porque no guarda en ningun lado
    printf("%d",*a+num);
    return 0;
}

void sum(int arr[]){
    *arr=*arr+3;  es igual que colocar arr[0]
}
void resta(int a){
    a=a-4;
}
*/
//2.2        e)22
/*
void f(){
    int*ar[2];  //asigno dos posiciones de memoria
    int a=9,b=13;
    ar[0]=&a;
    ar[1]=&b;
    printf("%d",*ar[0]+*ar[1]);
}
int main(){
    f();
    return 0;
}
*/
//2.3     e) error ejecucion poruqe no hay malloc;
/*int main(){
    int* p=NULL;
    (*p)=10;
    printf("%d",*(p)+1);
    return 0;
}
*/
//     2.4    h)ninguna de las anteriores, devuelve cero pq' ultima recursiva devueelve cero miFoo
/*int main(){
    printf("%d",foo(3,4)); //devuelve cero
    return 0;
}
int foo(int n,int m){
    int miFoo=0;
    if(m<0){
        miFoo=n*foo(n,m-1);
        return miFoo;
    }
    return miFoo;
}
*/
