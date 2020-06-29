#include <stdio.h>
#include <stdlib.h>
/*    podria poner una condicion if dentro del while
      que si i+1 es cero entonces arrranque es fjdsfasfds
SI DIMENSION ES>
>> 3  ENTONCES i<3-2 o i<4-3  i<1
>> 4  ENTONCES i<4-2          i<2
>> 5  ENTONCES i<5-3          i<2
>> 6  ENTONCES i<6
*/
int main()
{
    printf("Hello world!\n");
    int tamdim[5]={1,1,1,1,1};
    int arranque=tamdim[0],i=0;
    while (i<2){
            printf("\n%d",arranque);
            arranque=arranque+arranque*tamdim[i+1];
            i++;
    }
    printf("\nFINAL:   %d",arranque);
    return 0;
}
