#include "arreglo_interpolacion.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Funcion subordinada a interpolationSearch
// Realiza el cálculo de la posición estimada en base a la búsqueda por interpolación.
// Esta función es usada internamente por interpolationSearch y no debería usarse fuera de ella.
int interpolate(int low, int high, int key, int *arr) {
    // Prevent division by zero
    if (arr[high] == arr[low]) {
        return low;
    }
    return low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
}

// Realiza la búsqueda por interpolación en un arreglo ordenado.
// Toma un arreglo, su tamaño y el valor a buscar. 
// Devuelve el indice del valor encontrado, o -1 si no se encuentra.
int interpolationSearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        // Caso 1: El valor buscado está en el límite inferior
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }

        // Calcula la posición estimada usando la búsqueda por interpolación
        int pos = interpolate(low, high, key, arr);

        // Confirma que estamos dentro del rango
        if (pos < low || pos > high) {
            return -1; // Fuera de rango, no existe key
        }

        // Caso 2: Se encuentra el valor buscado
        if (arr[pos] == key) return pos;

        // Caso 3: El valor buscado es mayor, ajusta low
        if (arr[pos] < key) low = pos + 1;
        // Caso 4: El valor buscado es menor, ajusta high
        else high = pos - 1;
    }

    // Valor no encontrado
    return -1;
}