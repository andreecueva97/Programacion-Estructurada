#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
int* minimoDir(int *v){




    if(*v!=0){
        if(*v>*(v+1)){
            return minimoDir(v+1);
        }




    }

    return v;
}
