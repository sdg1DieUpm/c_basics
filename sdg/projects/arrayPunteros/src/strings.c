/**
 * @file strings.c
 * @brief Explanation of the initialization and use of strings in C.
 *
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-23
 *    
 */

/* INCLUDES PROPIOS */
#include "strings.h"

/**
 * @brief Function to explain the initialization and use of stings in C. It includes an example code on how to copy strings using strcpy.  
 */
void explica_strings(){
    printf("\n/* Distintas formas de inicializar strings */");
    printf("\nLos strings son arrays de caracteres que acaban con el caracter ASCII \'\\0\'\n");
    printf("Las reglas para inicializacion son las mismas que para cualquier array. Un string se puede copiar en otro usando la funcion \"strcpy\" (de la libreria <string.h>)\n");
    printf("Un string puede ademas inicializarse poniendo el texto entre comillas dobles \" \".\n");

    // Descomentar esto para probar las distintas opciones de inicializacion:
    /*char cadena[5] = {'H', 'o', 'l', 'a', '\0'};
	char cadena[] = {'H', 'o', 'l', 'a', '\0'};
	char cadena[] = "Hola"; 
    */

    printf("\n/* Inicializacion con  comillas dobles \" \"*/\n");
	char *cadena = "Hola\n";
	printf("%s", cadena);

    printf("\n/* Caracteres ASCII de un string, recorriendolo con FOR */\n");
	int32_t longitud = (int32_t)strlen(cadena);
	for(int32_t i=0; i<longitud; i++){
		printf("0x%X, ", cadena[i]);
	}

    printf("\n/* Inicializacion con STRCPY */\n");
    printf("Se puede hacer uso de \"strlen\" para calcular el tamano de un string (sin contar el \'\\0\').\n");		
	char cadena_destino[(int32_t)strlen(cadena)+1];
	strcpy(cadena_destino, cadena);
	printf("%s", cadena_destino);
}
