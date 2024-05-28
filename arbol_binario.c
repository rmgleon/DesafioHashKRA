#include "headers/arbol_binario.h"
#include <stdlib.h>
#include <stdio.h>

// Funcion subordinada a addTreeNode, crea un nodo y le asigna
// un valor especificado.
// Se ocupa dentro de addTreeNode y no deberia usarse fuera de el
tree *createTreeNode (int val){
	tree *nuevonodo;
	nuevonodo=(tree*)malloc(sizeof (tree));
	nuevonodo->dato=val;
	nuevonodo->left=NULL;
	nuevonodo->right=NULL;
	return nuevonodo;
}

// Inicializa o le añade un nodo al arbol binario.
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

void showTree (tree *arbol){
	if (arbol==NULL)
		return;
	printf ("\n%d",(arbol)->dato);
	showTree ((arbol)->left);
	showTree ((arbol)->right);
}

tree *findTreeNode (tree *arbol, int bus){
	if (arbol->dato==bus){
		return arbol;
	}else if (bus < arbol->dato && arbol->left!=NULL )
		return findTreeNode ( arbol->left, bus);
	else if (bus > arbol->dato && arbol->right!=NULL)
		return findTreeNode ( arbol->right, bus);
	return arbol;
}

/* Solo para que compile. Despues lo elimino
int main(){
    return 0;
}
*/