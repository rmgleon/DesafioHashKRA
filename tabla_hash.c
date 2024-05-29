#include "headers/tabla_hash.h"
#include <stdio.h>
#include <stdlib.h>

void insertHashNode(int valor, list *cadena[]){
    list * nuevoNodo = (list*)malloc(sizeof(list));
	nuevoNodo->dato = valor;
	nuevoNodo->sig = NULL;

	int clave = valor % TAM;
	if(cadena[clave] == NULL){
		cadena[clave] = nuevoNodo;
	}
	else{
		/* 	forma lentisima de cargar los datos. Tiene que recorrer
			hasta el final antes de que pueda cargar un elemento
		list * temp = cadena[clave];
		while(temp->sig != NULL){
			temp = temp->sig;
		}
		temp->sig = nuevoNodo;*/

		// Carga como se carga una lista normal
		nuevoNodo->sig=cadena[clave];
		cadena[clave]=nuevoNodo;
	}
}

void inicializarHash(list * lista, int N, list *cadena[]){
	//Inicializa la tabla Hash en NULL
	for(int i=0; i<TAM; i++){
		cadena[i] = NULL;
	}
	list * temp = lista;
	for(int i=0; i<N; i++){
		insertHashNode(temp->dato, cadena); 
		temp = temp->sig;
	}
}

void printHash(list *cadena[]){
	for (int i=0 ; i<TAM; i++){
	struct list * temp = cadena [i];
	printf ( "*cadena[%d]->", i);
		while (temp){
			printf ( "%d->", temp->dato);
			temp = temp->sig;
		}
	printf ( "NULL \n " );
	}
}

int searchHash(int valor, list *cadena[]){
	int clave = valor % TAM;
	list * temp = cadena [clave];
	while(temp){
		if(temp->dato == valor){	
			return 1 ;
		}
		temp = temp-> sig ;
	}
	return 0 ;
}

