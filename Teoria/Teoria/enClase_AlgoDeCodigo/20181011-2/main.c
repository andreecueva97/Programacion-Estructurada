#include <stdio.h>
#include <stdlib.h>
struct s_punto{
int x,y

};
typedef struct s_punto t_punto;


int main()
{
    t_punto* p = NULL;
    p=malloc(sizeof(struct s_punto )* 2);
    (*( p +0)).x =5;
    (*( p +0)).y =7;
    (p+1)->x = 15; /**  (*( p +1)).x =15;  */
    (p+1)->y = 17; /**  (*( p +1)).y =17;  */
    printf("%d, %d", (p+1)->x,(p+1)->y);





    return 0;
}
