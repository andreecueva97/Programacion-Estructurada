#include <stdio.h>
#include <stdlib.h>
#define T 10
char* cargarArrDC();
void cargarArrDC2(char**  arrDC);
int main()
{
    char* arrMain=NULL;

    //arrMain = cargarArrDC();
    cargarArrDC2(&arrMain);
    printf("\n%s",arrMain);
    return 0;
}
char* cargarArrDC(){

    char* arrDC=NULL;       /** (memoria dinamica)se puede modificar tamaño en tiempo de ejecución */
    arrDC=malloc(sizeof(char)*1); // arrDC=malloc(10);
    int i=0;
    char c=getche();
    while(c!='\r' ){   // (c!='\r' && i<T-1)
        *(arrDC+i)=c;
        i++;
        arrDC = realloc( arrDC, sizeof(char)*(i+1));
        c=getche();
    }
    *(arrDC+i)='\0';
    return arrDC;
}

void cargarArrDC2(char** arrDC){
    *arrDC=malloc(sizeof(char)*1); // arrDC=malloc(10);
    int i=0;
    char c=getche();
    while(c!='\r' ){   // (c!='\r' && i<T-1)
        *((*arrDC)+i)=c;
        i++;
        *arrDC = realloc( *arrDC, sizeof(char)*(i+1));
        c=getche();
    }
    *((*arrDC)+i)='\0';
    return arrDC;
}
