#include <stdio.h>
#include <stdlib.h>

struct s_punto{
    int x,y;
};
typedef struct s_punto t_punto;

void cargar();

int main()
{
    cargar();
    return 0;
}

void cargar()
{
    FILE *arch;
    int c, i = 0;
    arch = fopen("archivo.csv","r");
    t_punto arr[20];

    c = fscanf(arch,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",&arr[0].x, &arr[0].y,&arr[1].x, &arr[1].y,&arr[2].x, &arr[2].y,&arr[3].x, &arr[3].y,&arr[4].x, &arr[4].y,&arr[5].x, &arr[5].y,&arr[6].x, &arr[6].y,&arr[7].x, &arr[7].y,&arr[8].x, &arr[8].y,&arr[9].x, &arr[9].y);
    while (i < 10)
    {
        printf("%d,%d\n",arr[i].x,arr[i].y);
        i++;
    }

}
