#include "headers/tabla_hash.h"
#include <stdio.h>
#include <stdlib.h>


list * cadena[TAM];

void insertHashNode(int valor){
    list * nuevoNodo = (list*)malloc(sizeof(list));
	nuevoNodo->dato = valor;
	nuevoNodo->sig = NULL;

	int clave = valor % TAM;
	if(cadena[clave] == NULL){
		cadena[clave] = nuevoNodo;
	}
	else{
		list * temp = cadena[clave];
		while(temp->sig != NULL){
			temp = temp->sig;
		}
		temp->sig = nuevoNodo;
	}
}

void inicializarHash(list * lista, int N){
	//Inicializa la tabla Hash en NULL
	for(int i=0; i<TAM; i++){
		cadena[i] = NULL;
	}
	list * temp = lista;
	for(int i=0; i<N; i++){
		insertHashNode(temp->dato); 
		temp = temp->sig;
	}
}

void printHash(){
	for (int i=0 ; i<TAM; i++){
	struct list * temp = cadena [i];
	printf ( "cadena[%d]->", i);
		while (temp){
			printf ( "%d->", temp->dato);
			temp = temp->sig;
		}
	printf ( "NULL \n " );
	}
}

int searchHash(int valor){
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