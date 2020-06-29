#include <stdio.h>
#include <stdlib.h>

int main() {
int i=0;
int Nc[24][31][12];
for(i=0;i<=24;i++){
    Nc[i][1][1]=i;
}
printf("El numero es %d\n", Nc[24][1][1]);
return 0; //Ejemplo aprenderaprogramar.com
}
