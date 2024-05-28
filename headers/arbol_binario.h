#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

typedef struct tree{
    int dato;
    struct tree* left;
    struct tree* right;
}tree;

tree *createTreeNode (int val);
void addTreeNode (tree **arbol, int val);
void showTree (tree *arbol);
tree *findTreeNode (tree *arbol, int bus);

#endif /* ARBOL_BINARIO_H */