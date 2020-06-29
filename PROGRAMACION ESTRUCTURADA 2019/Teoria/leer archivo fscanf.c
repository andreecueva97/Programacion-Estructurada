#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    int r;

    FILE* arch;
    arch=fopen("arch.txt","r");

    if(arch==NULL)
        return -1;

    r=fscanf(arch,"%d,%d,%d\n",&a,&b,&c);
    while(r!=EOF)
    {
        printf("%2d: %2d,%2d,%2d\n",r,a,b,c);
        r=fscanf(arch,"%d,%d,%d\n",&a,&b,&c);
    }
    printf("EOF= %d\n",r);
    printf("EOF= %d\n",EOF);
    fclose(arch);
    return 0;
}
