#include <stdio.h>
#include <stdlib.h>
/**Pasaje de variables por referencia*/
void suma(int a, int b, int* resu);
int main(){
   int res = -1;
   suma(10,20,&res);
   printf("%d",res);
    return 0;
}
void suma(int a, int b, int* resu){
    *resu = a + b;
}
