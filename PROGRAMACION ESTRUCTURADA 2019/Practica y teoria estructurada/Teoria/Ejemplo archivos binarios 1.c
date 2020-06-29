#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int entero;
    int decimal;
}real;

void EscribirArchivo(char *);
void LeerArchivo(char *);

int main()
{
    char archivo[]="valores.dat";
    int pos;

    printf("----------------------------\n");
    EscribirArchivo(archivo);
    printf("----------------------------\n");
    LeerArchivo(archivo);

    return 0;
}

void EscribirArchivo(char *archivo)
{
    FILE *ptrArchivo;
    real numero;
    int entero, decimal;

    ptrArchivo = fopen(archivo, "wb");
    if (ptrArchivo!=NULL)
    {
        do
        {
            printf("Ingrese valor entero, Finaliza con Valor 0(Cero)\n");
            scanf("%d", &entero);
            if (entero!=0)
            {
                printf("Ingrese valor decimal\n");
                scanf("%d", &decimal);
                numero.entero=entero;
                numero.decimal=decimal;
                fwrite(&numero, sizeof(real), 1, ptrArchivo);
            }

        }
        while (entero!=0);

        fclose(ptrArchivo);
    }
}

void LeerArchivo(char *archivo)
{
    FILE *ptrArchivo;
    real numero;

    ptrArchivo = fopen(archivo, "rb");
    if (ptrArchivo!=NULL)
    {
        while (!feof(ptrArchivo) && fread(&numero, sizeof(real), 1, ptrArchivo))
        {
            printf("\n");
            printf("Valor Entero: %d\n", numero.entero);
            printf("Valor Entero: %d\n", numero.decimal);
        }

        fclose(ptrArchivo);
    }
}
