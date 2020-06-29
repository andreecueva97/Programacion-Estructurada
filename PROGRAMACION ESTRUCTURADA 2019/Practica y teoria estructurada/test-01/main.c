#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    char *arr=malloc(sizeof(char)*3);
    arr[0]='a';arr[1]='v';arr[2]='\0';
    printf("%s",arr);
    return 0;
}
