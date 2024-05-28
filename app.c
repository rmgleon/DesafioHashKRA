#include <stdlib.h>
#include <stdio.h>
#include "headers/tabla_hash.h"
#include "headers/arbol_binario.h"

void hash();

int main(int argc, char *argv[]) {
    
    hash();
	
	return 0;
}

void hash(){
	list * lista = NULL;
	list * cadena[TAM];

	int N = 1000000;

	for(int i=0; i<N; i++){
		list * nuevo = (list *)malloc(sizeof(list));
		nuevo->dato = i;
		nuevo->sig = lista;
		lista = nuevo;
	}

    inicializarHash(lista, N, cadena);
    //printHash(cadena);

	int valor;
	printf("Valor a buscar: ");
	scanf("%d", &valor);
	
	if(searchHash(valor,cadena) == 1){
		printf("Valor encontrado\n");
	}
	else{
		printf("Valor no encontrado.\n");
	}
}