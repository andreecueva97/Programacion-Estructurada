#include <stdio.h>
#include <stdlib.h>
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
