
#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#define TAM 100

typedef struct list{
	int dato;
	struct list * sig;
}list;

void inicializarHash(list * lista, int N, list *cadena[]);
void insertHashNode(int valor, list *cadena[]);
int searchHash(int valor, list *cadena[]);

#endif /* TABLA_HASH_H */