#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/** 03B Memoria dinámica */

/**
FUNCIONA TANTO PARA WINDOWS COMO PARA MAC
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 03 Punteros */

char* cargarStrDin(){
	int i=0;
	char letra;
	char* arr=NULL;
	
	arr = (char *) malloc(sizeof(char));
	if (arr==NULL){return NULL;}
	
	putchar(letra); // guarda todos caracteres para el getchar
	letra=getchar();       // letra = getche();
	while (letra!='\n')    //(letra!='\r')
	{
		*(arr+i)=letra;
		i++;
		arr=(char *) realloc(arr,(i+1)*sizeof(char));
		letra=getchar();
	}
	arr[i]='\0'; // *(arr+i)='\0'
	printf("\n");
	return arr;
}
	
	int main()
	{
		printf("%s\n",cargarStrDin());
		
		return 0;
	}
