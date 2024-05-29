#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "headers/tabla_hash.h"
#include "headers/arbol_binario.h"
#include "headers/tabla_hash_mod.h"
#include "headers/arreglo_binario.h"


// Genera un arbol, lo llena de elementos, y permite buscar
// elementos dentro de el definidos por el usuario
// Muestra el tiempo que tardo en la busqueda
void arbol();
void arregloBusquedaBinaria(int arr[], int n);

// Toma un hashmap (cadena) y una lista auxiliar.
// Usa la lista para llenar a cadena de elementos
// Permite la busqueda de elementos dentro del hashmap
// deifindos por el usuario
// Muestra el tiempo que tardo en la busqueda
void hash(list *cadena[], list *lista);
void hashMod(list *cadenaMod[], list *lista);

int main(int argc, char *argv[]) {
    srand(time(NULL));
	
	// Arreglo para arregloBusquedaBinaria
	int arreglo[1000000];
	// Lista auxiliar de hash
	list * lista = NULL;
	// Hashmap de hash
	list * cadena[TAM];
	// Hashmap de hashMod
	list * cadenaMod[TAM];
	// Elementos de la lista auxiliar de hash
	int N = 1000000;
	
	// Llena la lista auxiliar con elementos ordenados
	for(int i=0; i<N; i++){
		list * nuevo = (list *)malloc(sizeof(list));
		nuevo->dato = i;
		nuevo->sig = lista;
		lista = nuevo;
	}

	inicializarHash(lista, N, cadena);
	inicializarHashMod(lista, N, cadenaMod);
	createOrderedArray(arreglo,N);
	
	
	int op;
	
	while(1){
		printf("\n1- Hash\n2- Arbol\n3- FHash\n4- Exit");
		printf("\nOpcion: ");
		scanf("%d", &op);
		fflush(stdin);
		
		switch(op){
			case 1:{ 
				hash(cadena, lista);
			}break;
			case 2:{
				arbol();
			}break;
			case 3:{
				hashMod(cadenaMod, lista);
			}break;
			case 4:{
				printf("\n -- exit success --");
				exit(0);
			}break;
			case 5:{
				arregloBusquedaBinaria(arreglo,N);
			}
			default:{
				printf("\n -- bad input, select 1-4 --");
			}break;
		}
	}
   
	return 0;
}

void arbol(){

	// Genera el arbol y un arreglo auxiliario para
	// rellenar al arbol
	tree *raiz;
	int array[1000000];

	printf("-- Arbol --\n");

    int range = 1000000;
    int *numbers = malloc((range + 1) * sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "Error al inicializar el arreglo\n");
		return;
    }

    // Inicializa el arreglo con valores consecutivos
    for (int i = 0; i <= range; i++) {
        numbers[i] = i;
    }

    // Randomiza el arreglo
    shuffle(numbers, range + 1);

    // Añade los numeros del arreglo al arbol
    for (int i = 0; i <= range; i++) {
        addTreeNode(&raiz, numbers[i]);
    }

    // Le tira una bomba atomica al arreglo auxiliar
    free(numbers);

	clock_t start, end;
    double cpu_time_used;
	int valor;
	tree *aux;
	do{
		printf("Valor a buscar: ");
		scanf("%d", &valor);
		start = clock();
	

		aux=findTreeNode(raiz,valor);
		if(aux->dato == valor){
			printf("Valor encontrado\n");
		}
		else{
			printf("Valor no encontrado.\n");
		}

		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("Tomo %f milisegundos.\n", cpu_time_used*1000);
		

	}while(valor!=-1);

	
}

void hash(list *cadena[], list *lista){
	printf("-- Hash --");
	
	clock_t start, end;
    double cpu_time_used;

	/*
	start = clock();
    // Aca se cargaban las cosas
    end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Tomo %f milisegundos.\n", cpu_time_used*1000);
	*/
    //printHash(cadena);
	int valor=0;
	do{
		printf("Valor a buscar: ");
		scanf("%d", &valor);
		start = clock();
			
		if(searchHash(valor,cadena) == 1){
			printf("Valor encontrado\n");
		}

		else{
			printf("Valor no encontrado.\n");
		}

		end = clock();				
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

		printf("Tomo %f milisegundos.\n", cpu_time_used*1000);

	}while(valor!=-1);
}

void hashMod(list *cadenaMod[], list *lista){

	printf("-- Hash Mod--");
	
	clock_t start, end;
    double cpu_time_used;

	/*
	start = clock();
    
    end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Tomo %f segundos.\n", cpu_time_used);
	*/

    //printHash(cadena);
	int valor;
	do{
		start = clock();
		
		printf("Valor a buscar: ");
		scanf("%d", &valor);
		
		if(searchHashMod(valor,cadenaMod) == 1){
			printf("Valor encontrado\n");
		}

		else{
			printf("Valor no encontrado.\n");
		}

		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("Tomo %f milisegundos.\n", cpu_time_used*1000);

	}while(valor!=-1);
}

void arregloBusquedaBinaria(int arr[], int n){
	clock_t start, end;
    double cpu_time_used;
	int valor;
	do{
		start = clock();
		
		printf("Valor a buscar: ");
		scanf("%d", &valor);
		
		if(binarySearch(arr,n,valor) != -1){
			printf("Valor encontrado\n");
		}

		else{
			printf("Valor no encontrado.\n");
		}

		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("Tomo %f milisegundos.\n", cpu_time_used*1000);

	}while(valor!=-1);
}
