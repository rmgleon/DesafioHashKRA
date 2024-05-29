#include "headers/arbol_binario.h"
#include <stdlib.h>
#include <stdio.h>

// Funcion subordinada a addTreeNode
// Toma valor y se lo asigna a un nodo
// el cual lo devuelve.
// Se ocupa dentro de addTreeNode y no deberia usarse fuera de el
tree *createTreeNode (int val){
	tree *nuevonodo;
	nuevonodo=(tree*)malloc(sizeof (tree));
	nuevonodo->dato=val;
	nuevonodo->left=NULL;
	nuevonodo->right=NULL;
	return nuevonodo;
}

// Toma un arbol y un valor y lo añade como un nodo.
// Si el arbol esta vacio, se le asigna un nodo. 
void addTreeNode (tree **arbol, int val){
	// Caso 1: El  nodo esta vacio  || El arbol esta vacio
	if (*arbol==NULL)
		*arbol = createTreeNode(val);
	// Caso 2: El valor a ingresar es mayor
	if ((*arbol)->dato<val)
		addTreeNode(&(*arbol)->right,val);
	// Caso 3: El valor a ingresar es menor 
	if ((*arbol)->dato>val)
		addTreeNode(&(*arbol)->left,val);
}

// Toma un arbol y lo muestra un arbol de forma recursiva
void showTree (tree *arbol){
	if (arbol==NULL)
		return;
	printf ("\n%d",(arbol)->dato);
	showTree ((arbol)->left);
	showTree ((arbol)->right);
}


// Toma un arbol y valor y lo encuentra de forma recursiva.
// Devuelve el arbol encontrado
tree *findTreeNode (tree *arbol, int bus){
	// Caso 1: El nodo actual es el de bus
	if (arbol->dato==bus){
		return arbol;
	// Caso 2: El valor del nodo actual es menor a bus 
	}else if (bus < arbol->dato && arbol->left!=NULL )
		return findTreeNode ( arbol->left, bus);
	// Caso 3: El valor del nodo actual es mayor a bus
	else if (bus > arbol->dato && arbol->right!=NULL)
		return findTreeNode ( arbol->right, bus);
	return arbol;
}

// Toma un arreglo ordenado y su tamaño.
// Lo mueve de forma aleatoria para garantizar
// Que sus elementos no sean consecutivos
void shuffle(int *arreglo, int n) {
    for (int i = n - 1; i > 0; i--) {
        // Eligue un indice aleatorio de 0 a i
        int j = rand() % (i + 1);
        // Intercambia los valores de forma aleatoria
        int temp = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = temp;
    }
}

