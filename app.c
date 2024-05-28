#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "headers/tabla_hash.h"
#include "headers/arbol_binario.h"
#include "headers/busqueda_hash.h"

void hash();
void arbol();

int main(int argc, char *argv[]) {

	int = op
	
	while(1){
		printf("\n 1_----\n2_-----\n3_-------\n4_exit");
		printf("\n select options ->\t");
		scanf("%d", &op);
		fflush(stdin);
		
		switch(op){
			case 1:{ 
				hash();
				//arbol();
			}break;
			case 3:{	
				FHash ( list *cadena[] );
			}break;
			case 4:{
				printf("\n -- exit success --");
				exit(0);
			}break;
			default:{
				printf("\n -- error input, select 1-4 --");
			}break;
		}
	}
   
	return 0;
}

void arbol(){
	tree *raiz;
	int valor;
	printf("-- Arbol --\n");
	printf("Valor: ");
	scanf("%i",&valor);
	addTreeNode(&raiz,valor);
}

void hash(){
	printf("-- Hash --");
	list * lista = NULL;
	list * cadena[TAM];

	clock_t start, end;
    double cpu_time_used;

	start = clock();
	int N = 1000000;

	for(int i=0; i<N; i++){
		list * nuevo = (list *)malloc(sizeof(list));
		nuevo->dato = i;
		nuevo->sig = lista;
		lista = nuevo;
	}

    inicializarHash(lista, N, cadena);
	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("La carga de elementos tardo %f segundos.\n", cpu_time_used);


    //printHash(cadena);
	int valor;
	do{
		start = clock();
		
		printf("Valor a buscar: ");
		scanf("%d", &valor);
		
		
		if(searchHash(valor,cadena) == 1){
			printf("Valor encontrado\n");
		}
		else{
			printf("Valor no encontrado.\n");
		}
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("Tomo %f segundos.\n", cpu_time_used);
	}while(valor!=-1);
}
