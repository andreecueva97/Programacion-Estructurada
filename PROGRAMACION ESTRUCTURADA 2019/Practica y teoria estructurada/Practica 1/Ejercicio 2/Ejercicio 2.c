#include <stdio.h>
#include <stdlib.h>
int operacion(int a,char b, int c),suma(int a,int c),resta(int a,int c),divi(int a,int c),mult(int a,int c);
void error();
int main()
{
    int a = 0,c = 0;
    char b;
    printf("Ingrese numero: ");
    scanf("%d",&a);
    printf("Ingrese operador(+ - * /): ");
    scanf("%s",&b);
    printf("Ingrese numero: ");
    scanf("%d",&c);
    operacion(a,b,c);
    return 0;
}

int operacion(int a,char b, int c){
    int x;
    if (b == '+'){
       x = suma(a,c);
    }
    else if (b == '-'){

       x = resta(a,c);
    }
    else if (b == '*'){
       x = mult(a,c);
    }
    else if (b == '/'){
       x = divi(a,c);
    }
    else{
       printf("Error");
}
    return x;
}

int suma(int a,int c){
    int x;
    x = a + c;
    printf("Resultado: %d", x);
    return 0;
}
int resta(int a,int c){
    int x;
    x = a - c;
    printf("Resultado: %d", x);
    return 0;
}
int mult(int a,int c){
    int x;
    x = a * c;
    printf("Resultado: %d", x);
    return 0;
}
int divi(int a, int c){
    int x;
    x = a / c;
    printf("Resultado: %d", x);
    return 0;
}

