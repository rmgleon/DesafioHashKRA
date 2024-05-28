#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "headers/tabla_hash.h"
#include "headers/arbol_binario.h"
#include "headers/busqueda_hash.h"

void hash();
void arbol();

int main(int argc, char *argv[]) {
	list * lista = NULL;
	list * cadena[TAM];
	
	int op;
	
	while(1){
		printf("\n1- Hash \n2- Nan\n3- FHash\n4- Exit");
		printf("\nOpcion: ");
		scanf("%d", &op);
		fflush(stdin);
		
		switch(op){
			case 1:{ 
				hash(cadena, lista);
				//arbol();
			}break;
			case 3:{
				FHash(cadena);
			}break;
			case 4:{
				printf("\n -- exit success --");
				exit(0);
			}break;
			default:{
				printf("\n -- bad input, select 1-4 --");
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

void hash(list *cadena[], list *lista){
	printf("-- Hash --");
	

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
    if(cpu_time_used >=60){
        	printf("Tomo %f minutos.\n", cpu_time_used/60);
    }
    else  if(cpu_time_used <=0){
        	printf("Tomo %f ms.\n", cpu_time_used*60);
    }
    else{
        	printf("Tomo %f segundoss.\n", cpu_time_used);
    }


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
    if(cpu_time_used >=60){
        	printf("Tomo %f minutos.\n", cpu_time_used/60);
    }
    else  if(cpu_time_used <=0){
        	printf("Tomo %f ms.\n", cpu_time_used*60);
    }
    else{
        	printf("Tomo %f segundoss.\n", cpu_time_used);
    }
	}while(valor!=-1);
}
