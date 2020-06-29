#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* arch=fopen("arch.txt","r");
    int i, r,a,b;
    char c;

    r=fscanf(arch,"%d,%d\n",&a,&b);
    printf("%d: %d,%d\n",r,a,b);
    while(!feof(arch))
    {
        r=fscanf(arch,"%d,%d\n",&a,&b);
        printf("%d: %d,%d\n",r,a,b);
    }

    rewind(arch);
    printf("----\n");
    r=fscanf(arch,"%d,%d\n",&a,&b);
    while(r!=EOF)
    {
        printf("%d: %d,%d\n",r,a,b);
        r=fscanf(arch,"%d,%d\n",&a,&b);

    }

    rewind(arch);
    printf("\n");
    r=fread(&c,1,1,arch);
    printf("%c",c);
    while(!feof(arch))
    {
        r=fread(&c,1,1,arch);
        printf("%c",c);
    }

    rewind(arch);
    printf("\n");
    r=fread(&c,1,1,arch);
    while(!feof(arch))
    {
        printf("%c",c);
        r=fread(&c,1,1,arch);

    }

    return 0;
}
