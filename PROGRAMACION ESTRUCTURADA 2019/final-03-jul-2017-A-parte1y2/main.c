#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/**                    1.1                           **/
/**
void cargarString(char** str){
    int i=0;char aux;
    *str=malloc(sizeof(char));
    aux=getche();
    while(aux!='\r'){
        *(*str+i)=aux;
        i++;
        *str=realloc(*str,sizeof(char)*(i+2));
        aux=getche();
    }
    *(*str+i)='\0';
}           **/
/**                   1.2                            **/
/**
void ordenar(t_per** per){
    int i=0,j=0;t_per aux;
    for(i=0;(*(*per+i))->dni!=0;i++)
    {
        for(j=i+1;*(*per+j))->dni!=0;j++)
        {
            if(((*(*per+i))->dni)<((*(*per+i))->dni)){
                aux=*per+i;
                *per+i=*per+j;
                *per+j=aux;

            }
        }
    }
}**/
/**                       2.1               h) **/
/**
int foo(int n, int m){
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
/**                        2.2    a)(0,0) **/
/**
int main(){
    char*s[5];int i=0;
    char c='2';
    s[i]=&c;         //0 false y 1 true
    for(i=0;i<5;i++){
        s[i]=&c;
        c=c+1;
    }
    printf("%d,%d",(c=='2'),!(s[0]==&c));
    return 0;
}**/
/**                 2.3         f)error ejecucion     **/
/**
int main(){
    char* s=NULL; int i;
    for(i=0;i<4;i++){
        *(s+i)='a'+i;
    }
    s[i]='\0';
    printf("%s",s); ///esto es valido OJOOOO!!!
    return 0;
}**/
/**2.4                        e)0         **/
/**
int foo(unsigned char n, unsigned char filter){
    return n& ( (255&(filter<<n+n))>1);
}
int main(){
    printf("%u",foo(3,4));
    return 0;
}
**/





