/**
 * @file main.c
 * @brief Main file on types of variables in C.
 * 
 * Code about the types of variables in C, their qualifiers, their memory usage, their scope and lifetime.
 * 
 * The code is mainly an explanation of each one of the points mentioned above. Oriented to the
 * introduction of C to the students of Sistemas Digitales of the ETSI Telecomunicacion UPM. It is strongly recommended
 * to comment and uncomment the \#includes of the different parts of the explanations to be able to experiment with the
 * code in order to make the terminal output more friendly.
 * 
 * For the sake of a better comprehension of the students of the current degree, the inline comments and the
 * explanations printed out by the printf function are written in Spanish.
 *
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11
 * 
 */

/* INCLUDES DEL SISTEMA */
#include <stdio.h>
#include <stdint.h>

/* INCLUDES PROPIOS */
#include "tipos.h"
#include "ancho_fijo.h"
#include "booleanos.h" 
#include "almacenamiento.h"
#include "cualificadores.h"
#include "representacion.h"

/**
 * @brief Global variable accesible from other files if declared as extern.
 * 
 */
int32_t var_externa = 0; // Definimos la variable global y le damos valor

/**
 * @brief Main function of the project "tipos". Entry point of the program.
 * 
 * @return Result of the execution.
 */
int32_t main()
{		
	
#ifdef TIPOS_H_
	printf("\n========================\n");
	printf("EXPLICACION DE LOS TIPOS\n");
	printf("========================\n");
	explica_tipos();
#endif

#ifdef ANCHO_FIJO_H_
	printf("\n====================================\n");
	printf("EXPLICACION DE ENTEROS DE ANCHO FIJO\n");
	printf("====================================\n");
	explica_ancho_fijo();
#endif

#ifdef BOOLEANOS_H_
	printf("\n========================\n");
	printf("EXPLICACION DE BOOLEANOS\n");
	printf("========================\n");
	explica_booleanos();
#endif

#ifdef ALMACENAMIENTO_H_	
	printf("\n====================================================\n");
	printf("EXPLICACION CLASES DE ALMACENAMIENTO Y CICLO DE VIDA\n");
	printf("====================================================\n");
    printf("\nLos llamados \"modificadores\" deberian ser llamados \"especificadores de tipo de almacenamiento y ciclo de vida\". Se colocan delante del tipo de una variable e indican: como se almacena, su valor inicial, alcance y ciclo de vida.\n");
    printf("Los mas usados son extern y static (y typedef).\n");

	printf("/* extern */\n");
	printf("En \"main.c\" damos valor a la variable externa definida como global\n");	
	var_externa = 1000; // Modificamos el valor de la variable externa 
		
	explica_almacenamiento();
	printf("\n\nDesde fuera de donde esta declarada una variable \"static global\", no puedo acceder a ella, y necesito funciones auxiliares para recoger y guardar el valor:\n");
	
	int32_t valor = funcion_get();	
	printf("\tEl valor leido es: valor=%d\n", valor);

	valor += 67; // Modifico el valor
	printf("\tEl valor modificado LOCAL es: valor=%d, pero no se ha cambiado en origen, pues sigue valiendo: %d\n", valor, funcion_get());
	
	funcion_set(valor); // Guardo el valor actualizado en origen
	printf("\tAl llamar a la funcion \"funcion_set()\", el valor modificado en origen se ha cambiado y ahora vale: %d\n", funcion_get());

#endif

#ifdef CUALIFICADORES_H_	
	printf("\n=============================\n");
	printf("EXPLICACION DE CUALIFICADORES\n");
	printf("=============================\n");
	explica_cualificadores();
#endif

#ifdef REPRESENTACION_H_
	printf("\n==========================================\n");
	printf("REPRESENTACION DE VARIABLES, PRINTF, ASCII\n");
	printf("==========================================\n");
	explica_representacion();
#endif
	
	return(0);
}