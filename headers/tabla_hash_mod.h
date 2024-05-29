
#ifndef TABLA_HASH_MOD_H
#define TABLA_HASH_MOD_H
#include "tabla_hash.h"

void inicializarHashMod(list * lista, int N, list *cadena[]);
void insertHashNodeMod(int valor, list *cadena[]);
int searchHashMod(int valor, list *cadena[]);

#endif /* TABLA_HASH_MOD_H */