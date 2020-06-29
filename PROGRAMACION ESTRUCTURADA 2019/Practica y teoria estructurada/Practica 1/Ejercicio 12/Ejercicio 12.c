#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F 10
#define C 10

int cargarMatNumDeArch(int mat[F][C], char nom[]);
int imprimirMatNum(int mat[F][C], int fil, int col);

int main(){
	int matriz[F][C] = {{0}};
	cargarMatNumDeArch(matriz, "equiposDatos.txt");
	imprimirMatNum(matriz, 5, 8);

}

int cargarMatNumDeArch(int mat[F][C], char nom[]){
	FILE* arch;
	int f = 0;
	int r = 0;
	arch = fopen(nom, "r");
	if(arch == NULL){
		return -1;
	}
	r = 0;

	while(r != EOF){
		r = fscanf(arch, "%d,%d,%d,%d,%d,%d,%d,%d\n", &mat[f][0], &mat[f][1], &mat[f][2], &mat[f][3], &mat[f][4], &mat[f][5],&mat[f][6], &mat[f][7]);
		f++;

	}

	return 0;
}


int imprimirMatNum(int mat[F][C], int fil, int col){

	int f = 0, c = 0;
	if(fil > F || col > C){
		return -1;
	}

	for(f = 0; f < fil; f++){
		for(c = 0; c < col-1; c++){
				printf("%d ", mat[f][c]);
		}
		if(mat[f][col-1] > 0){
			printf("+%d ", mat[f][col-1]);
		}
		else {
			printf("%d ", mat[f][col-1]);
		}
		printf("\n");
	}

	return 0;
}
