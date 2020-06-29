#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    char arreglo[27]={'A','B','C','a','b','c','d','e','f','g','h','i','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27'};
    int tamdim[3]={3,3,3,0};
    int dimAnter=0,i=0,offset=4;
    char pal='20';
    int aux=offter;
    while (dimAnter[i]!=0):{
        dimAnter=dimAnter+tamdim[i];
        if(tamdim[i+1]==0):{
            i=0;
        }
        else:{i++;}
    }
    /*offset te da la posicion de la palabra*/
    if(offset%dimAnter!=0):{
        offset-=dimAnter*(offset%dimAnter);
    }
    return 0;

}
