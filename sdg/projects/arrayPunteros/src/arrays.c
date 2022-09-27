/**
 * @file arrays.c
 * @brief Explanation of the initialization and use of arrays in C.
 *
 * It includes an example code on how to generate a multidimentional (2D) array of structs.
 *
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-23
 *    
 */

/* INCLUDES PROPIOS */
#include "arrays.h"

/**
 * @brief Function to explain the initialization and use of arrays in C. It includes an example code on how to generate a multidimentional (2D) array of structs.
 * 
 */
void explica_arrays(){    
    printf("\n/* Declaracion de arrays sin inicializacion */");
    int32_t arr[TAM_ARRAY_A];
	int32_t arr_destino[TAM_ARRAY_A];

    printf("\nSi el array se inicializa (da valores) junto con la declaracion, se hace entre llaves \"{ }\".\n");
    printf("Si el array se inicializa (da valores) despues de la declaracion, se puede hacer (i) elemento a elemento, (ii) con un bucle, o (iii) copiando contenido en memoria con la funcion \"memcpy\" (de la libreria <string.h>).\n");

    printf("\n/* Inicializacion con FOR */\n");
	for (int32_t i=0; i<TAM_ARRAY_A; i++){
		arr[i] = i+1;
		printf("arr[%d]=%d\n", i, arr[i]);
	}

	printf("\n/* Inicializacion con MEMCPY */\n");	
    memcpy(arr_destino, arr, sizeof(arr));
    for (int32_t i=0; i<TAM_ARRAY_A; i++){ // Imprimo el resultado		
		printf("arr_destino[%d]=%d\n", i, arr_destino[i]);
	}

    printf("\n/* Declaracion de arrays sin especificar tamano */\n");
	int32_t otro_arr[] = {33, 34};
	printf("otro_arr[0]=%d\n", otro_arr[0]);
	printf("otro_arr[1]=%d\n", otro_arr[1]);

    printf("\nEn la declaracion de un array puede no especificarse el tamano solamente si tambien se hace la inicializacion de sus valores a la vez. De otra forma, dara error.\n");
    
    // Descomentar esto para comprobar el error:
	/* 
	int32_t otro_arr2[];
	otro_arr2[0] = 1;
	*/

    printf("\n/* Ejemplo: array multidimensional de estructuras. Pantalla de pixeles, de LEDs RGB */\n");
	pixel_t pantalla[NUM_ROWS][NUM_COLS];

	for (int32_t i=0; i<NUM_ROWS; i++){
		for (int32_t j=0; j<NUM_COLS; j++){
			pantalla[i][j].led_r.color = RED; 
			pantalla[i][j].led_r.estado = true;

			pantalla[i][j].led_g.color = GREEN; 
			pantalla[i][j].led_g.estado = false;

			pantalla[i][j].led_b.color = BLUE; 
			pantalla[i][j].led_b.estado = true;
		}
	}

	for (int32_t i=0; i<NUM_ROWS; i++){
		for (int32_t j=0; j<NUM_COLS; j++){
			printf("(%d,%d,%d),", pantalla[i][j].led_r.estado, pantalla[i][j].led_g.estado, pantalla[i][j].led_b.estado);
		}
		printf("\n");
	}
}
