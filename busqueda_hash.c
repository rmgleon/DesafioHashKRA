#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headers/tabla_hash.h"
#include "headers/busqueda_hash.h"


// list * cadena [TAM];

void FHash ( list *cadena[] ){

    long long int GB = 1073741824,clave, valor;
    printf("valor -> \t");
    scanf("%lls",&valor);
    fflush(stdin);
    
	clock_t start, end;
 	double cpu_time_used;
	start = clock();
						
    clave = (valor * (2*GB)) % TAM ;
    list * Find = cadena [clave];

    while (Find){

        if (Find ->dato == valor){

            printf("\n-- value found --");
        }

    Find = Find -> sig ;

    }

    printf("\n-- value not found --");

    end = clock();				
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if(cpu_time_used >=60){
        	printf("Tomo %f minutos.\n", cpu_time_used/60);
    }
    else  if(cpu_time_used <=0){
        	printf("Tomo %f ms.\n", cpu_time_used*60);
    }
    else{
        	printf("Tomo %f segundos.\n", cpu_time_used);
    }
}
