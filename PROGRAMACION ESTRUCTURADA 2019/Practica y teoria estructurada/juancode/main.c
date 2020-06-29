#include <stdio.h>
#include <stdlib.h>

struct s_indice{
    int inicio;
    int fin;
};
typedef struct s_indice t;

t buscar(char* str, char* sub);

int main()
{
    char* str="La verdad absoluta no existe";
    char* sub="r";
    printf("%d",buscar(str,sub).inicio);
    return 0;
}

t buscar(char*str,char*sub){
    t arr;
    int len,ini,fin,ban,i,j;
    for(len=0;*(sub+len)!='\0';len++){};
    for(i=0;*(str+i)!='\0';i++){
        if(*(str+i)==*sub){
            ban=0;
            for(j=0;*(sub+j)!='\0';j++){
                if(*(str+i+j)!=*(sub+j))
                    ban=1;
            }
            if(ban==0)
                ini=i;
        }
    }
    fin=ini+len-1;
    arr.inicio=ini;
    arr.fin=fin;
    return arr;
}

