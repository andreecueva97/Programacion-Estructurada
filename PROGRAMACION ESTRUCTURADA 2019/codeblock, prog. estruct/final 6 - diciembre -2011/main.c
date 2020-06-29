//#include <stdio.h>
//#include <stdlib.h>
/**
#define FILA 12
#define COLS 9
int main()
{
    printf("Hello world!\n");
    return 0;
}
void procesar(int matriz[filas][cols])
{
    int fila,col;
    for(col=0;col<COLS;col++)
    {
        for(fila=0;fila<FILAS; fila++)
        {
            if(col==0){
                printf("%u",(matriz[fila][col])&matriz[fila][col]);
            }
            else{
                printf("%u",(matriz[fila][col])&matriz[fila][col-1])
                }
            }
        }
    }
    for()
    {
        for(col=0;col<COLS; col++)
        {


        }
    }
    for()
    {
        for()
        {


        }
    }


} **/
/**2.1           c)9    **/
/**
int main(){
    int a=9,b=13,c=-3,d=8;
    int *bb,**cc;
    bb=&a;  //9
    cc=&bb; //9
    (*bb)++;//10
    a=5;
    **cc=**cc+4;
    cc=&d;
    printf("%d",*bb);
    return 0;
}
**/
/**  2.2   e) wwww       **/
/**char x(char a)   //1)'u'            //2)'u'
{
    if(a<='w')   //1)si
        printf("%c",x(a+1));//1)
    return 'w';  //1)'w'
}
void main(){
    printf("%c",x('u'));// u v w x y z
}**/
/**2.3    b) 893456789 **/
/**
int main(){
    char *b="3456789";
    char * p=b;
    p+=5;//p=p+5
    printf("%s%s",p,b);
}**/
/** 2.4  d)15   **/
int main(){
    unsigned char a;
    a=~((~0)<<(1<<2));
    printf("%d",a);
}
