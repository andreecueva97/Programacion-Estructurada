#include <stdio.h>

void cargarArchivo(char *);
void imprimirArchivo(char *);

int main()
{
    char *string="Sueldos.csv";
    cargarArchivo(string);
    imprimirArchivo(string);
    return 0;
}

void cargarArchivo(char *string)
{
    FILE *ptrArchivo;

    ptrArchivo=fopen(string, "w");

    fprintf(ptrArchivo ,"%d,%s,%d\n", 1,"Jose", 123);
    fprintf(ptrArchivo ,"%d,%s,%d\n", 2,"Roberto", 456);
    fprintf(ptrArchivo ,"%d,%s,%d\n", 3,"Fernando", 789);

    fclose(ptrArchivo);
}

void imprimirArchivo(char *string)
{
    FILE *ptrArchivo;
    int num, i=0;
    char nombre[30], caracter;
    int sueldo;

    ptrArchivo=fopen(string, "r");

    if (ptrArchivo!=NULL)
    {
        while (!feof(ptrArchivo))
        {
            num=0;
            sueldo=0;
            fscanf(ptrArchivo, "%d,", &num);
            i=0;
            for (caracter=fgetc(ptrArchivo); caracter!=',' && !feof(ptrArchivo);caracter=fgetc(ptrArchivo))
            {
                nombre[i]=caracter;
                i++;
            }
            nombre[i]='\0';
            if (!feof(ptrArchivo))
                fscanf(ptrArchivo, "%d\n", &sueldo);
            printf("Valores Leidos: %d,%s,%d\n", num, nombre, sueldo);
        }
        fclose(ptrArchivo);

    }
}
