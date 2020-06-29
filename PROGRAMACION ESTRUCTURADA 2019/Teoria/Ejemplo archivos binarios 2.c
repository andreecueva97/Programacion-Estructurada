#include <stdio.h>

typedef struct
{
    int Edad;
    char Nombre[25];
}Alumno;

void guardarDatos(char *, Alumno);
void agregarDatos(char *, Alumno);
Alumno *leerDatos(char *);

int main()
{
    Alumno Edgardo;
    Alumno *Leido;
    int opcion;

    do{
    printf("Ingrese Opcion:\n");
    printf("1 - Imprimir Archivo\n");
    printf("2 - Guardar dato\n");
    printf("3 - Agregar dato\n");
    printf("0 - Salir\n");
    scanf("%d", &opcion);
    switch(opcion)
    {
        case 1:
            Leido=leerDatos("Prueba.dat");

            //--------------------------------------
            //Como no lo vuelvo a utilizar no me
            //Preocupa perder el inicio del puntero
            //--------------------------------------
            //Leo hasta encontrar
            //la posicion con EDAD =  0
            //--------------------------------------
            while (Leido!=NULL && Leido->Edad!=0)
            {
                printf("-------------------------\n");
                printf("Nombre: %s\n", Leido->Nombre);
                printf("Edad: %d\n", Leido->Edad);
                Leido++;
            }
            break;
        case 2:
            fflush(stdin);
            printf("Ingrese su Nombre\n");
            gets(Edgardo.Nombre);

            printf("Ingrese su Edad\n");
            scanf("%d", &(Edgardo.Edad));

            guardarDatos("Prueba.dat", Edgardo);
            break;
        case 3:
            fflush(stdin);
            printf("Ingrese su Nombre\n");
            gets(Edgardo.Nombre);

            printf("Ingrese su Edad\n");
            scanf("%d", &(Edgardo.Edad));

            agregarDatos("Prueba.dat", Edgardo);
            break;
    }
    printf("\nPresione una tecla por favor.\n");
    getche();
    system("cls");
    }while(opcion!=0);

    printf("ADIOS!\n");

    return 0;
}

void agregarDatos(char *archivo, Alumno alm)
{
    FILE *ptrArchivo;

    ptrArchivo=fopen(archivo, "ab");

    if (ptrArchivo!=NULL)
    {
        fwrite(&alm, sizeof(Alumno), 1, ptrArchivo);
        fclose(ptrArchivo);
    }
}

void guardarDatos(char *archivo, Alumno alm)
{
    FILE *ptrArchivo;

    ptrArchivo=fopen(archivo, "wb");

    if (ptrArchivo!=NULL)
    {
        fwrite(&alm, sizeof(Alumno), 1, ptrArchivo);
        fclose(ptrArchivo);
    }
}

Alumno *leerDatos(char *archivo)
{
    FILE *ptrArchivo;
    Alumno Leido;
    Alumno *Resultado=NULL;
    int i=0;

    ptrArchivo=fopen(archivo, "rb");

    if (ptrArchivo!=NULL)
    {
        while (!feof(ptrArchivo) && fread(&Leido, sizeof(Alumno), 1, ptrArchivo))
        {
            Resultado=(Alumno *)realloc(Resultado, sizeof(Alumno)*(i+1));
            *(Resultado+i)=Leido;
            i++;
        }
        Resultado=(Alumno *)realloc(Resultado, sizeof(Alumno)*(i+1));
        (Resultado+i)->Edad=0;

        fclose(ptrArchivo);

        return Resultado;
    }
}
