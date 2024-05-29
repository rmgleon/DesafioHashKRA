#include "headers/tabla_hash.h"
#include <stdio.h>
#include <stdlib.h>



void insertHashNodeMod(int valor, list *cadenaMod[]){
    list * nuevoNodo = (list*)malloc(sizeof(list));
	nuevoNodo->dato = valor;
	nuevoNodo->sig = NULL;

	int clave = valor * 31 % TAM;
	if(cadenaMod[clave] == NULL){
		cadenaMod[clave] = nuevoNodo;
	}
	else{
		nuevoNodo -> sig = cadenaMod[clave];
		cadenaMod[clave] = nuevoNodo;
	}
}

void inicializarHashMod(list * lista, int N, list *cadenaMod[]){
	//Inicializa la tabla Hash en NULL
	for(int i=0; i<TAM; i++){
		cadenaMod[i] = NULL;
	}
	list * temp = lista;
	for(int i=0; i<N; i++){
		insertHashNodeMod(temp->dato, cadenaMod); 
		temp = temp->sig;
	}
}

int searchHashMod(int valor, list *cadenaMod[]){
	int clave = valor * 31 % TAM;
	list * temp = cadenaMod[clave];
	while(temp){
		if(temp->dato == valor){	
			return 1 ;
		}
		temp = temp-> sig ;
	}
	return 0 ;
}

