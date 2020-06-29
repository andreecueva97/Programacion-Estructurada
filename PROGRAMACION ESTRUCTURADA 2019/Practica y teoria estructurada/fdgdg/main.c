#include <stdio.h>
#include <stdlib.h>

struct a_alu{
char *apellido;
struct s_nota lstnota;
struct s_alu * sig;
};typedef struct s_alu * t_alu;

struct s_nota
{
    int valor;
    struct s_nota * sig;
};typedef struct s_nota* t_nota;



int main()
{
    printf("Hello world!\n");
    return 0;
}
