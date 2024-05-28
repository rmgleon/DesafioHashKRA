#include <stdio.h>
#include <stdlib.h>
#include "headers/busqueda_hash.h"
#include "headers/tabla_hash.h"


// list * cadena [TAM];

void FHash ( list *cadena[] ){

    long long int GB = 1073741824,clave, valor;
    printf("valor -> \t");
    scanf("%lls",&valor);
    fflush(stdin);

    clave = (valor * (2*GB)) % TAM ;
    list * Find = cadena [clave];

    while (Find){

        if (Find ->dato == valor){

            printf("\n-- value found --");
        }

    Find = Find -> sig ;

    }

    printf("\n-- value not found --");
}
