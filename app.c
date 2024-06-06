#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "headers/tabla_hash.h"
#include "headers/arbol_binario.h"
#include "headers/tabla_hash_mod.h"
#include "headers/arreglo_binario.h"
#include "headers/arreglo_interpolacion.h"

#define ELEMENTOS 1000

// Funcion para generar gráfico
void generateGnuplotScript(const char *filename, double *values, int numValues) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("No se pudo crear el archivo gnuplot script");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "set terminal pngcairo\n");
    fprintf(file, "set output 'grafico.png'\n");
    fprintf(file, "set title 'Tiempo promedio de busquedas'\n");
    fprintf(file, "set style data histograms\n");
    fprintf(file, "set style fill solid\n");
    fprintf(file, "set boxwidth 0.7\n");
    fprintf(file, "set ylabel 'Tiempo (μs)'\n");
	fprintf(file, "set yrange [0:2.0000]\n"); //Modificar en caso de que en el grafico una de las busquedas sobrepase el valor
	fprintf(file, "set ytics 0.2000\n"); // Intervalo de Y (cada cuantos numeros marca una linea)
    fprintf(file, "set xtics rotate by -45\n");
	fprintf(file, "set grid\n");
	fprintf(file, "set grid linecolor rgb '#808080' linewidth 1.5 linetype 1\n");
    fprintf(file, "set xtics ('Promedio Hash' 0, 'Promedio Arbol' 1, 'Promedio HashMod' 2, 'Promedio Bus binaria' 3, 'Promedio Bus interpolacion' 4)\n");

	fprintf(file, "plot '-' using 2:xtic(1) title 'Tiempo Promedio'\n");

    const char *labels[] = {"PromHash", "PromArbol", "PromHashMod", "PromBusBin", "PromBusInt"};
    for (int i = 0; i < numValues; i++) {
        fprintf(file, "%s %f\n", labels[i], values[i]);
    }
    fprintf(file, "e\n");
	
    fclose(file);
}

// Toma un arbol y permite buscar
// elementos dentro de el definidos por el usuario
// Devuelve el tiempo que tardo en la busqueda
double arbol(tree *raiz, int arr);

// Toma un arreglo, su tamaño, y el elemento a buscar
// Lo busca usando busqueda binaria
// Devuelve el tiempo que tardo en la busqueda
double arregloBusquedaBinaria(int arr[], int tam, int arr2);


// Toma un arreglo, su tamaño, y el elemento a buscar
// Lo busca usando busqueda por interpolacion
// Devuelve el tiempo que tardo en la busqueda
double arregloBusquedaInterpolacion(int arr[], int tam, int arr2);

// Toma un hashmap (cadena) y una lista auxiliar.
// Usa la lista para llenar a cadena de elementos
// Permite la busqueda de elementos dentro del hashmap
// deifindos por el usuario
// Devuelve el tiempo que tardo en la busqueda
double hash(list *cadena[], int arr);
double hashMod(list *cadenaMod[], int arr);

int main(int argc, char *argv[]) {
    srand(time(NULL));
	// Genera el arbol y un arreglo auxiliario para
	// rellenar al arbol
	tree *raiz = NULL;
    int range = 1000000;
    int *numbers = (int *)malloc((range + 1) * sizeof(int));


    // Inicializa el arreglo auxiliar del arbol
	// con valores consecutivos
    for (int i = 0; i <= range; i++) {
        numbers[i] = i;
    }

    // Randomiza las posiciones del arreglo de manera
	// que sus miembros no sean consecutivos
    shuffle(numbers, range + 1);


    // Añade los numeros del arreglo al arbol
    for (int i = 0; i <= range; i++) {
        addTreeNode(&raiz, numbers[i]);
    }

    // Le tira una bomba atomica al arreglo auxiliar
   free(numbers);

	// Arreglo para arregloBusquedaBinaria y arregloBusquedaInterpolacion
	int arreglo[1000000];
	//int elementosABuscar[ELEMENTOS];
	int elementosABuscar;

	// Lista auxiliar de hash
	list * lista = NULL;

	// Hashmap de hash
	list * cadena[TAM];

	// Hashmap de hashMod
	list * cadenaMod[TAM];

	// Elementos de la lista auxiliar de hash
	int N = 1000000;

	
	// Llena la lista auxiliar con elementos ordenados
	for(int i=0; i<N; i++){
		list * nuevo = (list *)malloc(sizeof(list));
		nuevo->dato = i;
		nuevo->sig = lista;
		lista = nuevo;
	}

	inicializarHash(lista, N, cadena);
	inicializarHashMod(lista, N, cadenaMod);
	createOrderedArray(arreglo,N);


    double resultado;

	// Valores de sumatoria de cada busqueda
	double resultadoHash = 0;
	double resultadoArbol = 0;
	double resultadoHashMod = 0;
	double resultadoBusBin = 0;
	double resultadoBusInt = 0;

	FILE *archivo;
	archivo = fopen("resultado.csv", "w");
	fprintf(archivo, "Valor;Hash;Arbol;HashMod;BusBin\n");

	if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }


	// Valores de tiempo de cada busqueda individual, auxiliares para la sumatoria 
	double resHash;
	double resArbol;
	double resHashMod;
	double resBusBin;
	double resBusInt;

   for (int i = 0; i < ELEMENTOS; i++) {
        elementosABuscar = rand() % N;
        fprintf(archivo, "%d;", elementosABuscar);

        // Obtener y almacenar resultados individuales
        resHash = hash(cadena, elementosABuscar);
        resArbol = arbol(raiz, elementosABuscar);
        resHashMod = hashMod(cadenaMod, elementosABuscar);
        resBusBin = arregloBusquedaBinaria(arreglo, N, elementosABuscar);
		resBusInt = arregloBusquedaInterpolacion(arreglo, N, elementosABuscar);

        // Sumar resultados a los acumuladores
        resultadoHash += resHash;
        resultadoArbol += resArbol;
        resultadoHashMod += resHashMod;
        resultadoBusBin += resBusBin;
		resultadoBusInt += resBusInt;

        // Escribir resultados individuales en el archivo
        fprintf(archivo, "%f;%f;%f;%f;%f\n", resHash, resArbol, resHashMod, resBusBin, resBusInt);
    }

    fclose(archivo);

    printf("Archivo resultado.csv generado correctamente.\n");

	// Arreglo con promedios para generar grafico de barras
    const int numValues = 5;
    double values[numValues];

	values[0] = resultadoHash/1000;
	values[1] = resultadoArbol/1000;
	values[2] = resultadoHashMod/1000;
	values[3] = resultadoBusBin/1000;
	values[4] = resultadoBusInt/1000;

    // Imprime los promedios de las busquedas en consola
    printf("Tiempo Promedio Busqueda Hash: \t\t%lf microsegundos\n", values[0]);
    printf("Tiempo Promedio Busqueda Arbol: \t%lf microsegundos\n", values[1]);
    printf("Tiempo Promedio Busqueda HashMod: \t%lf microsegundos\n", values[2]);
    printf("Tiempo Promedio Busqueda binaria: \t%lf microsegundos\n", values[3]);
	printf("Tiempo Promedio Busqueda Interpolacion: \t%lf microsegundos\n", values[4]);

    //Comprueba si esta instalado Gnuplot
    if(!system("gnuplot --version") != 0){
    // Generar el script de Gnuplot
    generateGnuplotScript("script.gnuplot", values, numValues);

    // Ejecutar el script de Gnuplot
    system("gnuplot script.gnuplot");

    printf("Grafico generado correctamente\n");

    }
    else{
        printf("No se pudo generar un grafico. No se encuentra instalado Gnuplot\n");
    }

	return 0;
}

double arbol(tree *raiz, int arr){

	clock_t start, end;
    double cpu_time_used=0;
	int valor;
	tree *aux = NULL;

		valor=arr;
		start = clock();
		aux=findTreeNode(raiz,valor);
		end = clock();
		cpu_time_used = ((double) (end - start));

		return cpu_time_used;
}

double hash(list *cadena[], int arr){
	clock_t start, end;
    double cpu_time_used = 0;

	int valor;

		valor=arr;
		start = clock();
		searchHash(valor,cadena);
		end = clock();
		cpu_time_used = ((double) (end - start));

	return cpu_time_used;
}

double hashMod(list *cadenaMod[], int arr){
	clock_t start, end;
    double cpu_time_used = 0;

	int valor;

		valor=arr;
		start = clock();
		searchHashMod(valor,cadenaMod);
		end = clock();
		cpu_time_used = ((double) (end - start));

		return cpu_time_used;
}

double arregloBusquedaBinaria(int arr[], int tam, int arr2){
	clock_t start, end;
    double cpu_time_used = 0;
	int valor;

		valor=arr2;
		start = clock();
		binarySearch(arr,tam,valor);
		end = clock();
		cpu_time_used = ((double) (end - start));

		return cpu_time_used;
}

double arregloBusquedaInterpolacion(int arr[], int tam, int arr2){
	clock_t start, end;
    double cpu_time_used = 0;
	int valor;
		valor=arr2;
		start = clock();
		interpolationSearch(arr,tam,valor);
		end = clock();
		cpu_time_used = ((double) (end - start));

		return cpu_time_used;
}