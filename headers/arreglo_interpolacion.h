#ifndef ARREGLO_INTERPOLACION_H
#define ARREGLO_INTERPOLACION_H

#include <stdlib.h>
#include <stdio.h>

// Calcula la posición estimada en base a la búsqueda por interpolación.
// Funcion subordinada usada por interpolationSearch.
int interpolate(int low, int high, int key, int *arr);

// Realiza la búsqueda por interpolación en un arreglo ordenado.
// Toma un arreglo, su tamaño y el valor a buscar. Devuelve el índice del valor encontrado, o -1 si no se encuentra.
int interpolationSearch(int *arr, int n, int key);

// Muestra los elementos del arreglo.
void showArray(int *arr, int n);

#endif /* ARREGLO_INTERPOLACION_H */
