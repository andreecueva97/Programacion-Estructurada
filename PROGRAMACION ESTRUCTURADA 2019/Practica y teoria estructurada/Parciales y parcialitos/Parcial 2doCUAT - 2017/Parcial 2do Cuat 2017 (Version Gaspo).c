#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_texto {
    char * txt;
    int lan;
};
typedef struct s_texto t_texto;
char * cargar();
int cantImpar(int * arr);
char * subcadena(char* cad, int ini, int cant){
    if (cad == NULL){
        return NULL;
    }
    int Largo_cad = strlen(cad);
    int cont = 0;
    char * cad_nueva = (char*)malloc(sizeof(char)*(Largo_cad-ini+1));
    if (cad_nueva == NULL){
        return NULL;
    }
    while(cont<cant && cad[ini+cont]!='\0'){
        cad_nueva[cont] = cad[ini+cont];
        cont++;
    }
    cad_nueva[cont] = '\0';
    return cad_nueva;
}

t_texto * cargarTexto(){
    t_texto* Arreglo = (t_texto*)malloc(sizeof(t_texto));
    Arreglo[0].txt = cargar();
    Arreglo[0].lan = strlen(Arreglo[0].txt);
    return Arreglo;

}

char * cargar(){
    char * Texto = (char*)malloc(sizeof(char)*2);
    char c;
    int cont = 0;
    printf("\nIngresar texto: ");
    c = getche();
    while(c!='\r'){
        Texto[cont] = c;
        cont++;
        c = getche();
        Texto = realloc(Texto, sizeof(char)*(cont+2));
    }
    Texto[cont] = '\0';
    return Texto;
}

int cantImpar(int* arr){
    if(arr[0]==0){
        return 0;
    }
    else if (arr[0]%2 != 0){
        return 1+cantImpar(&arr[1]);
    }
    return cantImpar(&arr[1]);
}

int main(){
    int ini= 19;
    int cant = 20;
    char * string = malloc(100);

    printf("\n\nEj 1\n");
    string = "Todo debe simplificarse\0";
    printf("\nCadena original: %s", string);
    char * string_nuevo = subcadena(string, ini, cant);
    printf("\nCadena final: %s", string_nuevo);

    printf("\n\nEj 2");
    t_texto* Arreglo = cargarTexto();
    printf("\nTexto: %s | Longitud: %d", Arreglo[0].txt, Arreglo[0].lan);

    printf("\n\nEj 3");
    int arr[] = {10,12,30,4,50,0};

    printf("\nCantidad de impares: %d", cantImpar(arr));

    printf("\n\nLiberando Arreglos dinamicos...");
    free(Arreglo[0].txt);
    free(Arreglo);
    free(string_nuevo);
    free(string);




    return 0;
}
