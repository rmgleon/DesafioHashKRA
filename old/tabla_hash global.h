
#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#define TAM 100

typedef struct list{
	int dato;
	struct list * sig;
}list;

void inicializarHash(list * lista, int N);
void insertHashNode(int valor);
void printHash();
int searchHash(int valor);

#endif /* TABLA_HASH_H */