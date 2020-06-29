#include <stdio.h>
#include <stdlib.h>

int redondeo(double a);
int piso(double a);
int techo(double a);

int main()
{
    double b;
    printf("Ingrese numero real: ");
    scanf("%lf", &b);
    printf("%s %d \n", "El numero redondeado es: ", redondeo(b));
    printf("%s %d \n", "El numero piso es: ", piso(b));
    printf("%s %d \n", "El numero techo es: ", techo(b));
    return 0;
}
int redondeo(double a)
{
    int b;
    double resta;
    b = a;
    resta = a-b;
    if (resta > 0.5)
    {
        b = b + 1;
    }
    else
    {
        b = b;
    }
    return b;
}
int piso(double a)
{
    int b;
    b = a;
    return b;
}
int techo(double a)
{
    int tech;
    tech = a;
    tech = tech + 1;
    return tech;
}
