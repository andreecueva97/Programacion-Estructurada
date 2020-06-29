#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 25




int cargarMatTexDeArch(char mat[][N], char nomArch[]);
void ordenarTexto(char mat[][N]);
void imprimirMatText(char mat[][N]);
int strcmp2(char str1[], char str2[]);
int strcpy2(char str1[], char str2[]);


int main(){
	char matriz[][N] = {{0}};
	cargarMatTexDeArch(matriz, "equipos.txt");
	imprimirMatText(matriz);
	ordenarTexto(matriz);
	imprimirMatText(matriz);

}

int cargarMatTexDeArch(char mat[][N], char nomArch[]){

	int f = 0, c = 0;
	char ch = 0;

	FILE* arch;
	arch = fopen(nomArch, "r");

	if(arch == NULL){
		return -1;
	}

	ch = fgetc(arch);
	while(ch != EOF && c < N){

		if(ch != '\n'){
			mat[f][c] = ch;
			c++;
		}
		else if(ch == '\n'){
			mat[f][c] = '\0';
			c = 0;
			f++;
		}

		ch = fgetc(arch);

	}
	mat[f][0] = '\0';
	return 0;

}

void imprimirMatText(char mat[][N]){
    int i = 0;

    printf("\n");
    while(mat[i][0] != '\0'){
    	printf("%s\n", mat[i]);
    	i++;
    }

}


void ordenarTexto(char mat[][N]){
	int f = 0, f2 = 0;
	char nom[N] = {0};
	while(mat[f][0] != '\0'){
		f2 = f;
		while(mat[f2][0] != '\0'){

			if( strcmp2(mat[f],mat[f2]) > 0){
				strcpy2(nom, mat[f]);
				strcpy2(mat[f], mat[f2]);
				strcpy2(mat[f2], nom);
			}
			f2++;
		}
		f++;
	}

}

int strcmp2(char str1[], char str2[]){
	int i = 0;
	while ( str1[i] != '\0' && str2['\0']){
		if(str1[i] > str2[i]){
			return 1;
		}
		else if(str1[i] < str2[i]){
					return -1;
			}

		i++;
	}
	return -1;
}

int strcpy2(char str1[], char str2[]){
	int i = 0;
	while (str2[i] != '\0'){
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
	return 0;
}
