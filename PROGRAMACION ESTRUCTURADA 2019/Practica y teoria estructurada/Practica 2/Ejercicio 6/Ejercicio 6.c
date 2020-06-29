#include <stdio.h>
#include <stdlib.h>

#define F 30
#define C 30

void cargarMat();

int main(){
	char mat[F][C] = {{0}};
    cargarMat();
}


void cargarMat()
{
    FILE *arch;
    int dni, r = 0, f = 0, mat[F][C];

    arch=fopen("personas.txt", "r");

    r = fscanf(arch,"%d,%s,%s",&mat[f][0],&mat[f][1],&mat[f][2]);
	while(r != EOF){
        printf("%d,%s,%s,", mat[f][0],mat[f][1],mat[f][2]);
		r = fscanf(arch,"%d,%s,%s", &mat[f][0],&mat[f][1],&mat[f][2]);
        f++;
	}

}


