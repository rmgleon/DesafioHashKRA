#include "headers/arreglo_binario.h"
#include <stdio.h>
#include <stdlib.h>

// Toma un arreglo y su tamaño
// Devuelve el arreglo con elementos ordenados
void createOrderedArray(int arr[], int size){
    int i;
    for(i=0;i<size;i++){
        arr[i] = i;
    }
}

// Toma un arreglo, su tamaño, y el objetivo
// Si encuentra el objetivo, lo devuelve
// Si no, devuelve -1
// Asume que el arreglo esta ordenado de menor a mayor
int binarySearch(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // Indice del medio
        // Si encuentra el numero en medio
        if (arr[mid] == target) {
            return mid;  // Lo encuentra
        }
        
        // Si el numero que buscamos es mayor, cambia el rango
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // Si el numero es menor, cambia el rango
        else {
            right = mid - 1;
        }
    }
    
    // No se encontro
    return -1;
}
