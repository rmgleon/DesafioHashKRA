#include "headers/arbol_binario.h"
#include <stdlib.h>
#include <stdio.h>

tree *createTreeNode (int val){
	tree *nuevonodo;
	nuevonodo=(tree*)malloc(sizeof (tree));
	nuevonodo->dato=val;
	nuevonodo->left=NULL;
	nuevonodo->right=NULL;
	return nuevonodo;
}

tree *addTreeNode (tree **arbol, int val){
	if (*arbol==NULL)
		return createTreeNode (val);
	if ((*arbol)->dato<val)
		(*arbol)->right=addTreeNode(&(*arbol)->right,val);
	if ((*arbol)->dato>val)
		(*arbol)->left=addTreeNode (&(*arbol)->left,val);
	return *arbol;
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