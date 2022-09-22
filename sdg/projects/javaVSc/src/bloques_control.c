/**
 * @file bloques_control.c
 * @brief Explanation of the loop and conditional blocks in C.
 *
 * Explanation of the loop (for, while, do while) and conditional (if, switch) blocks in C, with examples.
 *
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11 
 *  
 */

#include "bloques_control.h"

/**
 * @brief Function to explain the use of the conditional blocks (if, switch) in C.
 * 
 */
void explica_bloques_condicionales(float temperatura, int8_t clima){
    printf("\n/*Bloque if-else if-else*/\n");
    printf("Por completitud, y para que el codigo sea verificable en todas sus condiciones, conviene poner siempre el caso \"else\".\n");
    printf("Importa el orden en el que se hagan las comprobaciones.\n");

    if (temperatura > TEMPERATURA_CONFORT_HIGH){
        printf("\tNO SALGAS. Por culpa del cambio climatico tenemos %0.1fºC en abril. No olvides beber agua.\n", temperatura);
    }
    else {
        if ((clima == SOLEADO) && (temperatura <= TEMPERATURA_CONFORT_HIGH)){
            printf("\tSAL A PASEAR. El clima es %s y la temperatura de %0.1fºC es buena.\n", nombres_climas[clima], temperatura);
        } 
        else if ((clima == SOLEADO) && (temperatura > TEMPERATURA_CONFORT_HIGH)){
            printf("\tQUEDATE EN CASA. Aunque el clima es %s, la temperatura es de %0.1fºC.\n", nombres_climas[clima], temperatura);
        } 
        else if ((clima == NUBLADO) || ((TEMPERATURA_CONFORT_LOW >= temperatura) && (temperatura < TEMPERATURA_CONFORT_HIGH))){
            printf("\tSAL A PASEAR, O NO. El clima es %s y la temperatura de %0.1fºC, agradable.\n", nombres_climas[clima], temperatura);
        } else {
        printf("\tMAL TIEMPO. El clima es %s y la temperatura de %0.1fºC. Mejor quedarse en casa.\n", nombres_climas[clima], temperatura);
        }
    }

    printf("\n/*Bloque switch-case*/\n");
    printf("Elige un curso de acción de un conjunto de acciones posibles, basado en el resultado de una expresion ENTERA\n");
    printf("Por completitud, y para que el codigo sea verificable en todas sus condiciones, conviene poner siempre el caso \"default\".\n");
    printf("No hay que olvidar poner \"break\" al final de cada \"case\", o se ejecutara tambien el siguiente \"case\".\n");

    switch (clima)
    {
    case SOLEADO:
        printf("\tEsta SOLEADO, hay poca probabilidad de lluvia.\n");
        break;
    case NUBLADO:
        printf("\tEsta NUBLADO, quizas llueva.\n");
        break;
    case LLUVIOSO:
        printf("\tEsta LLUVIOSO, precaucion en la carretera.\n");
        break;          
    default:
        printf("\tEste es un estado nuevo de la materia, no conozco el clima %d.\n", clima);
        break;
    }
}


/**
 * @brief Function to explain the use of the loops (for, while, do while) in C.
 * 
 */
void explica_bucles(){    
    printf("\n/*Bucles for*/\n");
    printf("Se lee:\n\t\"Desde que la variable de control vale \"X\", mientras que valga \"Y\", variando de \"Z\" en \"Z\", haz...\"\n");
    printf("Desde C99 se puede declarar la variable de control dentro del argumento de for() y queda declarada solo en el bloque, por lo que puede reutilizarse el nombre luego.\n");
    
    for (int32_t i=10; i>=0; i-=2){
        static int32_t j = 0;
        j+=1;
        printf("\ti vale %d, j vale %d\n", i, j);
    }
    
    printf("\n/*Bucles while*/\n");
    printf("Se lee:\n\t\"Mientras se cumpla la condicion \"X\" haz...\n");
    printf("\tPrimero se comprueba la condicion y luego se ejecuta el bloque.\n");

    int32_t i=0, j=10; // Puedo reusar los nombres porque antes quedaron en el ambito del bloque for
    while (i<j){
        printf("\ti vale %d, ", i);
        printf("i todavia es menor que j=%d; le sumo 1 y vale i=%d\n", j, i+=1);
    }

    printf("\n/*Bucles do-while*/\n");
    printf("Se lee:\n\t\"Ejecuta el bloque, y vuelvelo a ejecutar mientras se cumpla la condicion \"X\"\n");
    printf("\tPrimero se ejecuta el bloque y luego se comprueba la condicion.\n");
    printf("\tCuidado: Se ejecuta siempre, al menos, 1 vez.\n");
    
    do {
        printf("\ti todavia es menor que j=%d, le sumo 1 y vale i=%d\n", j, i+=1); // Cuidado!!!
    } while (i < j);
}
