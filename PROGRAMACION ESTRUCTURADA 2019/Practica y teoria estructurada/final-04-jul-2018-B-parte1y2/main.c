#include <stdio.h>
#include <stdlib.h>
/**                        1.1                 **/
/**
int*cargar();
int*minimoDir(int*v);
int main()
{
    printf("Hello world!\n");
    int*arr=NULL;
    arr=cargar();
    printf("\n%d",*(minimoDir(arr)));
    return 0;
}
int*cargar(){
    int n,i=0;
    int*a=NULL;
    a=malloc(sizeof(int));
    printf("\ningrese numero:");
    scanf("%d",&n);
    *(a+i)=n;
    while(n!=0){
        a=realloc(a,sizeof(int)*(i+2));
        printf("\ningrese numero:");
        scanf("%d",&n);
        i++;
        *(a+i)=n;
    }
    return a;
}
int*minimoDir(int*v){
    int*min,*x,*m;
    x=v;
    min=x;
    if(*v!=0){
        v++;
        m=minimoDir(v);
        if((*m)<(*min) && (*m)!=0){
            min=m;
        }
    }
    return min;
}**/
/**                      1.2              **//**
int bit(unsigned int n){
    unsigned int mask1= 7;
    unsigned int mask2= 7<<29;
    if((n&(mask1|mask2))== (mask1|mask2))
        return 1;
    else
        return 0;
}
int main(){
    printf("%d",bit(1));
    return 0;
}**/
/**2.1 d)7   **/
/**2.2 e)22  **/
/**2.3 e)error ejecucion LE FALTO EL MALLOC   **/
/**2.4 h)ninguno de los anteriores DA 0**/






