#include <stdio.h>
#include <stdlib.h>


/*
int *cargarArr();
int sumPares(int* arr);

int main()
{
    int* arr;
    arr=cargarArr();
    printf("%d",sumPares(arr));
    return 0;
}

*    1.1    *

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

*      1.2     *

int sumPares(int* arr){
    if (*arr!=0){
        if ((*arr)%2==0){
            return *arr + sumPares(arr+1);
        }
        return sumPares(arr+1);
    }
    return 0;
}
*/

/*  2.1
int main(){
    unsigned char a=1;
    unsigned int i;
    for (i=0;i<8;i++){
        a=a&(1<<i);
    }
    printf("\n%d",a);
}
*/

/*  2.2
char f(char a){
    if (a<'c'){
        f(a+1);
    }
    else{
        if (a=='b'){
            f(a+1);
        }
    }
    return a;
}

void main(){
    printf("%c",f('b'));
}
*/

/*  2.3
int main(){
    int* p=NULL;
    (*p)=10;
    printf("%d",*(p)+1);
    return 0;
}
*/

/*  2.4
void f(){
    int a=9,b=13;
    int* bb,**cc;
    bb=&b;
    cc=&bb;
    printf("%d",*bb + 1);
}

int main(){
    f();
}
*/
