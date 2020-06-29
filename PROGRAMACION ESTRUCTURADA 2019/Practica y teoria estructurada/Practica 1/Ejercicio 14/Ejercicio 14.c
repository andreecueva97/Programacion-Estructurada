#include <stdio.h>
#include <stdlib.h>
#define F 31
#define C 12

int cargarMat(int m[][C], char direc[]);
void impMat(int m[F][C]);
int minAnual(int m[F][C]);
int maxAnual(int m[F][C]);
double promAnual(int m[F][C], int diasMed[C]);
double mesCaluroso(int m[F][C], int diasMed[C]);
double mesFrio(int m[F][C], int diasMed[C]);
int cargarDiasMedidos(int m[]);
int totDiasMed(int m[]);

int main(){
	int matriz[F][C] = {{-273}};
	int diasMed[C] = {0};
	cargarMat(matriz, "temperaturas.csv");
	cargarDiasMedidos(diasMed);
	impMat(matriz);
	printf("El minimo anual es: %d \n", minAnual(matriz));
	printf("El maximo anual es: %d \n", maxAnual(matriz));
	printf("El promedio anual es: %f", promAnual(matriz, diasMed));
	mesCaluroso(matriz, diasMed);
	mesFrio(matriz, diasMed);
	printf("\nEl total de dias es: %d", totDiasMed(diasMed));

}

int cargarMat(int m[][C], char direc[]){
	int c = 0, f = 0, r = 0;
	char coma = 0;
	FILE* arch;
	arch = fopen(direc, "r");

	if(arch == NULL){
		return -1;
	}

	r = fscanf(arch, "%d", &m[f][c]);
	fgetc(arch);
	f++;

	while(r != EOF && c < C){
		r = fscanf(arch, "%d", &m[f][c]);
		coma = fgetc(arch);
		f++;
		if(coma == '\n'){
			c++;
			f = 0;
		}


	}
	return 0;
}

int cargarDiasMedidos(int m[]){
	int c = 0, r = 0;
	FILE* arch;
	arch = fopen("diasMedidos.txt", "r");

	if(arch == NULL){
		return -1;
	}

	r = fscanf(arch, "%d", &m[0]);
	fgetc(arch);
	while(r != EOF){
		c++;
		r = fscanf(arch, "%d", &m[c]);
		fgetc(arch);
	}


	printf("\n");
	return 0;
}

int minAnual(int m[F][C]){

	int f = 0, c = 0, i = m[0][0];

	for(f = 0; f < F; f++){
		for(c = 0; c < C; c++){
			if(m[f][c] > i || (f > 27 && c == 1) || (f > 29 && (c ==3 || c == 5 || c == 8 || c == 10))){ //arreglar

			}
			else {
				i = m[f][c];
			}
		}
	}

	return i;
}

void impMat(int m[F][C]){
	int c = 0, f = 0;
	for(f = 0; f < F; f++){
		for(c = 0; c < C; c++){
			printf("%3d", m[f][c]);
		}
		printf("\n");
	}
}

int maxAnual(int m[F][C]){

	int f = 0, c = 0, i = m[0][0];

	for(f = 0; f < F; f++){
		for(c = 0; c < C; c++){
			if(m[f][c] > i){
				i = m[f][c];
			}
		}
	}

	return i;
}

double promAnual(int m[F][C],  int diasMed[C]){
	double i = 0, n = 0;
	int c = 0, f = 0;
	n = totDiasMed(diasMed);

	for(f = 0; f < F; f++){
			for(c = 0; c < C; c++){
				i += m[f][c];
			}
		}
	return i/n;
}

double mesCaluroso(int m[F][C], int diasMed[C]){

	double i = 0, r = 0, dias = 0;
	int c = 0, f = 0, c2 = 0;
	for(c = 0; c < C; c++){
		dias = diasMed[c];
		for(f = 0; f < F; f++){
			i += m[f][c];
		}
		if(i/dias > r){
			r = i/dias;
			c2 = c;
		}
		i = 0;
	}

	printf("\nEl mes mas caluroso es el %d con un promedio de %.2f", c2+1, r);
	return 0;

}

double mesFrio(int m[F][C], int diasMed[C]){

	double i = 0, r = 0, dias = diasMed[0];
	int c = 0, f = 0, c2 = 0;

	for(f = 0; f < F; f++){
		i += m[f][0];
	}
	r = i/dias;

	for(c = 0; c < C; c++){
		dias = diasMed[c];
		for(f = 0; f < F; f++){
			i += m[f][c];
		}
		if(i/dias < r){
			r = i/dias;
			c2 = c;
		}
		i = 0;
	}

	printf("\nEl mes mas frio es el %d con un promedio de %.2f", c2+1, r);
	return 0;

}

int totDiasMed(int m[]){
	int c = 0, n = 0;
	for(c = 0; c < C; c++){
			n += m[c];
	}
	return n;
}


