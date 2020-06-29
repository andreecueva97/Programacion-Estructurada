/*
 * main.c
 *
 *  Created on: May 3, 2017
 *      Author: martinpordomingo
 */

#include <stdio.h>
#include <stdlib.h>

#define F 20
#define C 20
#define D 8
#define E 5

int cargarMat(char mat[][C], char nom[]);
int cargarMatEnt(int mat[][D], char nom[]);
int ordenarMat(char items[F][C], int datos[][D], int col, int desc);
void imprimirMat(int datos[][D], char items[F][C], char cabecera[F][C]);
void imprimirMatText(char mat[F][C]);

int main(){
	char matItems[F][C] = {{0}};
	char matCabecera[F][C] = {{0}};
	int matEnt[E][D] = {{0}};
	int col = 0, ord = 0;

	cargarMat(matCabecera, "cabeceras.txt");
	cargarMat(matItems, "items.txt");
	cargarMatEnt(matEnt, "datos.txt");

	printf("Ingrese la columna por la que desea ordenar (0-7): ");
	scanf("%d", &col);
	printf("Asc (0) o desc (1): ");
	scanf("%d", &ord);
    printf("\n");
	ordenarMat(matItems, matEnt, col, ord);
	imprimirMat(matEnt, matItems, matCabecera);
}

void imprimirMatText(char mat[F][C]){
    int i = 0;

    printf("\n");
    for(i = 0; i < F; i++){
    	if(mat[i][0] != '\0'){
    		printf("%s\n", mat[i]);
    	}
    }
}

int cargarMat(char mat[F][C], char nom[]){
	FILE* arch;
	char ch = 0;
	int f = 0, c = 0;
	arch = fopen(nom, "r");
	if(arch == NULL){
		return -1;
	}

	ch = fgetc(arch);
	while(ch != EOF){
		if(ch != '\n'){
			mat[f][c] = ch;
			c++;
		}
		else if(ch == '\n') {
			mat[f][c] = '\0';
			f++;
			c = 0;
		}
		ch = fgetc(arch);
	}
	mat[f][c] = '\0';
	return 0;
}

int cargarMatEnt(int mat[][D], char nom[]){

	FILE* arch;
	int r = 0, f = 0;
	arch = fopen(nom, "r");

	if(arch == NULL){
		return -1;
	}
	r = fscanf(arch, "%d,%d,%d,%d,%d,%d,%d,%d\n", &mat[f][0], &mat[f][1], &mat[f][2], &mat[f][3], &mat[f][4], &mat[f][5],&mat[f][6], &mat[f][7]);
	while(r != EOF){
		f++;
		r = fscanf(arch, "%d,%d,%d,%d,%d,%d,%d,%d\n", &mat[f][0], &mat[f][1], &mat[f][2], &mat[f][3], &mat[f][4], &mat[f][5],&mat[f][6], &mat[f][7]);
		//para hacerlo con getc hubiera tenido que transformar char a int con int n = c = '0'
	}

	return 0;
}

void imprimirMat(int datos[][D], char items[F][C], char cabecera[F][C]){

	int f = 0, c = 0;
	for(c = 0; c < C; c++){
		if(c == 0){
			printf("%-15s ", cabecera[c]);
		}
		else {
			printf("%4s ", cabecera[c]);
		}

	}
	c = 0;
	f = 0;
	printf("\n-------------------------------------------------------\n");
    for(f = 0; f < E; f++){
		printf("%-15s ", items[f]);
		for(c = 0; c < D; c++){
            printf("%4d ", datos[f][c]);
		}
		printf("\n");
	}

}

void imprimirMatEnt(int mat[F][C]){

	int f = 0, c = 0;
	for(f = 0; f < F; f++){
		for(c = 0; c < C; c++){
			printf("%d ", mat[f][c]);
		}
		printf("\n");
	}


}

int ordenarMat(char items[F][C], int datos[][D], int col, int desc){
    int f = 0, f2 = 0, c = 0;
    int num[C] = {0};
    if(desc == 1){
    for(f = 0; f < F; f++){
        for(f2 = f; f2 < E; f2++){
            if(datos[f][col] < datos[f2][col]){

                for(c = 0; c < D; c++){
                    num[c] = datos[f2][c];
                }
                for(c = 0; c < D; c++){
                    datos[f2][c] = datos[f][c];
                }
                for(c = 0; c < D; c++){
                     datos[f][c] = num[c];
                }

            }
        }
    	}
    }
    else {
    	for(f = 0; f < F; f++){
    	        for(f2 = f; f2 < E; f2++){
    	            if(datos[f][col] > datos[f2][col]){

    	                for(c = 0; c < D; c++){
    	                    num[c] = datos[f2][c];
    	                }
    	                for(c = 0; c < D; c++){
    	                    datos[f2][c] = datos[f][c];
    	                }
    	                for(c = 0; c < D; c++){
    	                     datos[f][c] = num[c];
    	                }

    	            }
    	        }
    }
    }
	return 0;
}
