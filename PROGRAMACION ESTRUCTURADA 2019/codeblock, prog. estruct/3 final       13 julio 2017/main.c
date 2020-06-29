#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/* 1.1
void cargarString(char** str);
int main()
{
    char *palabra=NULL;
    int i=0;
    printf("Hello world!\n");
    cargarString(&palabra);
    printf("\n");


    while(*(palabra+i)!='\0')
    {
        printf("%c",*(palabra+i));
        i++;
    }
    printf("%c",*(palabra+i));
    return 0;
}

void cargarString(char** str)
{
    int i=0;char aux;
    *str=malloc(sizeof(char));
    aux=getche();
    while(aux!='\r')
    {
        *(*str+i)=aux;
        *str=realloc(*str,sizeof(char)*(i+2));
        i++;
        aux=getche();
    }
    *(*str+i)='\0';
}
*/
/* 1.2
void ordenar(t_per** per){
    int i=0,j=0;t_per aux;
    for(i=0;*(*(per+i))!=0;i++)
    {
        for(j=i+1;*(*per+j);j++)
        {
            if(*(*per+j)<*(*per+i))
            {
                aux=*(*per+j);
                *(*per+j)=*(*per+i);
                *(*per+i)=aux;
            }

        }
    }
}
*/
/*     2.1        h )ninguna de las anteriores
int main(){
    printf("%d",foo(3,4));
    return 0;
}
int foo(int n, int m){
    int miFoo=1;
    if(m>0){
        miFoo=n*foo(n,m-1);
    }
    return miFoo;
}
*/
// 2.2         (0,0)  funciona
/*int main(){
    char* s[5];int i=0;
    char c='2';
    s[i]=&c;
    for(i=0;i<5;i++){
        s[i]=&c;
        c=c+1;
    }
    printf("(%d,%d)",(c=='2'),!(s[0]==&c));
    return 0;
}
*/
/*2.3     f)error de ejecucion*/
/*int main(){
    char*s=NULL;int i;
    for(i=0;i<4;i++){
        *(s+i)='a'+i;
    }
    s[i]='\0';
    printf("%s",s);
    return 0;
}
*/
//2.4     e)0
/*int foo(unsigned int n,unsigned int filter);
int main(){
    printf("%d",foo(3,4));
}
int foo(unsigned int n,unsigned int filter){
    return n&((255&(filter<<n+n))>1);
}
*/
