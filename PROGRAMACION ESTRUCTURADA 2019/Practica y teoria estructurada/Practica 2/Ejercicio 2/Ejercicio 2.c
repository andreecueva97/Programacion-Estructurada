#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct s_punto{
    int x,y;
    char arr[20];
};
typedef struct s_punto t_punto;

void cargar(),imprimir(t_punto arr[20]),imprimirdistmin(t_punto arr[20]),imprimirdistmintot(t_punto arr[20]);

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
    imprimir(arr);
    imprimirdistmin(arr);
    imprimirdistmintot(arr);



}
void imprimir(t_punto arr[20])
{
    int i = 0;
    printf("Puntos:\n");
    printf(" X | Y\n");
    printf(" -----\n");
    while (i < 10)
    {
        printf(" %d | %d\n",arr[i].x,arr[i].y);
        i++;
    }
    printf("\n");
}

void imprimirdistmin(t_punto arr[20])
{
    int i = 0,z = 1;
    double lmin[10], mini = 0;

    for(i = 0; i < 9; i++)
    {
        double pnt1 = sqrt((pow(arr[i].x,2)) + (pow(arr[i].y,2)));
        double pnt2 = sqrt((pow(arr[i+1].x,2)) + (pow(arr[i + 1].y,2)));
        printf("Dif 1: %lf   Dif 2:  %lf\n",pnt1,pnt2);

        if (pnt1 > pnt2)
        {
            lmin[i] = pnt1 - pnt2;
        }
        else
        {
            lmin[i] = pnt2 - pnt1;
        }
    }

    mini = lmin[0];
    while (z < 9)
    {
        if (lmin[z] < mini)
        {
            mini = lmin[z];
        }
        z++;
    }

    printf("\nEl menor espacio entre puntos consecutivos es de: %lf\n",mini);
}

void imprimirdistmintot(t_punto arr[20])
{
    int i = 0, f = 1,z = 1;
    double lmin[10], lmin2[10], mini = 0;

    mini = lmin2[0];
    while (i < 9)
    {
        mini = 10;
        double pnt3 = sqrt((pow(arr[i].x,2)) + (pow(arr[i].y,2)));
        f = 1;
        while(f < 10)
        {
            double pnt4 = sqrt((pow(arr[f].x,2)) + (pow(arr[f].y,2)));
            if (pnt3 > pnt4)
            {
                lmin2[f] = pnt3 - pnt4;
            }
            else if (pnt3 < pnt4)
            {
                lmin2[f] = pnt4 - pnt3;
            }

            if (lmin2[f] < mini)
            {
                mini = lmin2[f];
            }
            f++;
        }
        i++;
    }
    printf("El menor espacio entre 2 puntos cualquiera es de: %lf\n",mini);


}
