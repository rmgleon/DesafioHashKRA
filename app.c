#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "headers/tabla_hash.h"
#include "headers/arbol_binario.h"
#include "headers/tabla_hash_mod.h"
#include "headers/arreglo_binario.h"

#define ELEMENTOS 1000


// Genera un arbol, lo llena de elementos, y permite buscar
// elementos dentro de el definidos por el usuario
// Muestra el tiempo que tardo en la busqueda
void arbol();
void arregloBusquedaBinaria(int arr[], int n, int arr2[]);

// Toma un hashmap (cadena) y una lista auxiliar.
// Usa la lista para llenar a cadena de elementos
// Permite la busqueda de elementos dentro del hashmap
// deifindos por el usuario
// Muestra el tiempo que tardo en la busqueda
void hash(list *cadena[], list *lista);
void hashMod(list *cadenaMod[], list *lista);

int main(int argc, char *argv[]) {
    srand(time(NULL));
	// Genera el arbol y un arreglo auxiliario para
	// rellenar al arbol
	tree *raiz;
	int array[1000000];
    int range = 1000000;
    int *numbers = malloc((range + 1) * sizeof(int));

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


	// Arreglo para arregloBusquedaBinaria
	int arreglo[1000000];
	int elementosABuscar[ELEMENTOS];

	// Lista auxiliar de hash
	list * lista = NULL;
	// Hashmap de hash
	list * cadena[TAM];
	// Hashmap de hashMod
	list * cadenaMod[TAM];
	// Elementos de la lista auxiliar de hash
	int N = 1000000;

	// Elementos aleatorios a buscar
	for(int i=0;i<ELEMENTOS;i++){
		elementosABuscar[i]=rand()%N;
	}
	
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
		printf("\n1- Busqueda Hash\n2- Busqueda Arbol\n3- Busqueda Hash del alumno\n4- Busqueda Arreglo Binaria\n5- Exit");
		printf("\nOpcion: ");
		scanf("%d", &op);
		fflush(stdin);
		
		switch(op){
			case 1:{ 
				hash(cadena, lista);
			}break;
			case 2:{
				arbol(raiz, elementosABuscar);
			}break;
			case 3:{
				hashMod(cadenaMod, lista);
			}break;
			case 4:{
				arregloBusquedaBinaria(arreglo,N,elementosABuscar);
			}break;
			case 5:{
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

void arbol(tree *raiz, int arr[]){

	clock_t start, end;
    double cpu_time_used=0;
	int valor;
	tree *aux;

	int encontrados=0;
	double average_time=0;

	
	for(int i=0;i<ELEMENTOS;i++){
		valor=arr[i];
		start = clock();
		aux=findTreeNode(raiz,valor);
		end = clock();
		cpu_time_used = cpu_time_used + ((double) (end - start)) / CLOCKS_PER_SEC;
		
	}
	
	
	
	average_time=cpu_time_used;
	printf("Tomo %f segundos.\nEl promedio fue %f milisegundos.\n", cpu_time_used, average_time);
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

void arregloBusquedaBinaria(int arr[], int n, int arr2[]){
	clock_t start, end;
    double cpu_time_used;
	int valor;
	double average_time;

	for(int i=0;i<ELEMENTOS;i++){
		valor=arr2[i];
		start = clock();
		binarySearch(arr,n,valor);
		end = clock();
		cpu_time_used = cpu_time_used + ((double) (end - start)) / CLOCKS_PER_SEC;
	
	}


	
	average_time=cpu_time_used;
	printf("Tomo %f segundos.\nEl promedio fue %f milisegundos.\n", cpu_time_used, average_time);

	
}
