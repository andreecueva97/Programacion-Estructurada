#include <stdio.h>
#include <stdlib.h>
#define F 5
#define C 15

int cargarMatTexDeArch(char mat[F][C], char nomArch[50]);
void imprimirMatText(char mat[F][C]);

int main(){
	char matriz[F][C] = {{0}};
	cargarMatTexDeArch(matriz, "equipos.txt");
	imprimirMatText(matriz);

}

int cargarMatTexDeArch(char mat[F][C], char nomArch[50]){

	int f = 0, c = 0;
	char ch = 0;

	FILE* arch;
	arch = fopen(nomArch, "r");

	if(arch == NULL){
		return -1;
	}

	ch = fgetc(arch);
	while(ch != EOF){

		if(ch != '\n'){
			mat[f][c] = ch;
			c++;
		}
		else {
			mat[f][c] = '\0';
			c = 0;
			f++;
		}

		ch = fgetc(arch);

	}

	return 0;

}

void imprimirMatText(char mat[F][C]){
    int i = 0;

    printf("\n");
    for(i = 0; i < F; i++){
        printf("%s\n", mat[i]);
    }
}
