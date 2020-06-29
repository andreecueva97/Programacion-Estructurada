#include <stdio.h>
#include <stdlib.h>
/**
int es_palindromo(char* palabra);

int main()
{
    char *palabra="allass";
    printf("%d",es_palindromo(palabra));

    return 0;
}

int es_palindromo(char* palabra){
    int i,ini,fin,res=1;

    for(i=0;*(palabra+i)!='\0';i++);

    ini= 0;

    fin= i-1;
    printf("%d",i);
    //palabra[ini]!='\0'
    while((i/2)!=ini){
       if(palabra[ini] != palabra[fin]){
            res= 0;
       }
        ini++;
        fin--;

    }
    return res;
}
**//**
int cantidad_niveles(t_nodo_bin_ptr pNodo)
{
    int izq,der;
    if(pNodo != NULL)
    {
        izq= cantidad_niveles(pNodo->pIzq);
        der=cantidad_niveles(pNodo->pDer);

        if()
        {
            return 1+izq;
        }
        else
        {
            return 1+der;
        }
    }
    else
        return 0;
}**/
/**
int main()
{
    char a;
    a=((((1)<<(1<<2))>>4)& 255)<<7;
    printf("%d",a);

}
**//**
int main(){

    char *b="12345";
    char * p=b;//0 apunta
    int i;

    for(i=0;*(p+i)!='\0';p++);//p=p+1;

    printf("%s%s",p,b);//12345
}**/
/**
int main(){
    unsigned int i=0;

    for(i=1;i<10;i=i<<1){
        printf("%d",i);
    }
}
**/
/****//**
char x(char a){
    if(a<='D')              //A B C D       E  ---->   E D D C B A
        printf("%c",x(a+1));
    else
    {
        printf("%c",a);
        return a-1;
    }
    return a;
}
void main(){

    printf("%c",x('A'));

}**//**
struct parcela{
    int idcate;
    int idparcela;
    int tamanio;
    double valor;
};
struct s_nodo{
    int idcate;
    char descrip[50];
    int cantparcelas;
    struct s_nodo* izq;
    struct s_nodo* der;
};typedef struct s_nodo* t_nodo;

int estaModifica(t_nodo* arbol,int idcate);

void agregar(t_nodo* arbol,int valor){
    if(*arbol==NULL){
        *arbol=malloc(sizeof(t_nodo));
        (*arbol)->idcate=valor;
        (*arbol)->izq=NULL;
        (*arbol)->der=NULL;
    }else{
        if(valor<(*arbol)->idcate){
            agregar(&(*arbol)->izq,valor);
        }
        else{
            agregar(&(*arbol)->der,valor);
        }


    }
}
int estaModifica(t_nodo* arbol,int idcate){
    printf("entra");
    if(*arbol==NULL){
        return 0;
    }
    else{
        if(idcate==(*arbol)->idcate){
            (*arbol)->cantparcelas++;
            return 1;//verdadero
        }
        else{
            if(idcate<((*arbol)->izq)->idcate){
                return estaModifica(&(*arbol)->izq,idcate);
            }
            else{
                return estaModifica(&(*arbol)->der,idcate);
            }
        }
    }
}

t_nodo* carga_suma(){
    t_nodo*arbol=NULL;
    struct parcela parcero;int idcate=3;
    FILE* parcelas=fopen("parcelas.txt","r");
    //FILE* categorias=fopen("categorias.dat","rb");
    fread(&parcero,sizeof(struct parcela),1,parcelas);
    while(!feof(parcelas)){
        if(estaModifica(arbol,idcate)==0)
        {
            agregar(arbol,idcate);
        }
        fread(&parcero,sizeof(struct parcela),1,parcelas);
    }
    return arbol;
}
**/
/****/
/**2 FACIL, ES LA FUNCION ESTA MODIFICARLA DEVUELTA**/
/****//**
int* minimoDir(int* v);
int main(){
    int*arr=malloc(sizeof(int)*3);
    arr[0]=3;arr[1]=1;arr[2]=0;
    printf("%d",*(minimoDir(arr)));
    return 0;
}
int* minimoDir(int* v){
    int *min,*m,*x;
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
}**/
/****//**
int main(){
    printf("%d",bit(3758096391));
    return 0;
}
int bit(unsigned int n){
    unsigned int mask1=7;
    unsigned int mask2=7<<29;
    if(n&(mask1|mask2)== n)
        return 1;//true
    else
        return 0;//false
}
**/
/**
void sum (int arr[]){
*arr = *arr +3;
}
void resta (int a){
a= a - 4 ;
}
int main(){
int a[3]={3,2,13}; int num=1;
sum(a);
resta(num);
printf("%d",*a + num);
return 0;
}
**//**
void f(){
int a=9, b=13;
int* ar[2];
ar[0]=&a;
ar[1]= &b;
printf("%d", *ar[0]+*ar[1]);
}
int main(){
f();
return 0;
}**//**
int main(){
    int* p=NULL;//vaciooooooooooooooooooooooooooooooooo
    (*p)=10;
    printf("%d",*(p)+1);
    return 0;
}**/
int foo(int n,int m);
int main(){
    printf("%d",foo(3,4));
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
