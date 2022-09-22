/**
 * @file main.c
 * @brief Main file on precompile directives in C.
 * 
 * Code about the precompile directives in C `#include`, `#define`, `#if`, `#ifndef`, `#undef`, `#error`.
 * 
 * The code is a brief explanation of each one of the directives mentioned above. Oriented to the
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

/**
 * @def OK
 * @brief Macro used to return as a result of the excution if it runs normaly.
 */

/**
 * @def INPUT_DATA_ERROR
 * @brief Macro used to return as a result of the excution if the user enters as radius of a circle a number lower than 0.
 */

/**
 * @def UNKNOWN_ERROR
 * @brief Macro used to return as a result of the excution if it does not run normaly besides the user enters a positive  number.
 */

/* INCLUDES DEL SISTEMA */
#include <stdio.h>
#include <stdint.h>

/* INCLUDES PROPIOS */
#include "geometria.h"
#include "dprintf.h"
#include "otras_directivas.h"

/* DEFINES Y ENUMS */
#define OK 0
#define INPUT_DATA_ERROR 1
#define UNKNOWN_ERROR -1

/**
 * @brief Main function of the project "precompilador". Entry point of the program.
 * 
 * @return Result of the execution.
 */
int32_t main()
{
#ifdef GEOMETRIA_H_
	printf("\n==================\n");
	printf("EXPLICACION DEFINE\n");
	printf("==================\n");
	
	printf("\nIntroduce el radio de una circunferencia para calcular su longitud:\n");	
	float r;
	scanf("%f", &r); // Leo un string con formato float y lo guardo en la direccion de memoria de r
	
	if (r>0.0){
		DPRINTF("\nEl numero introducido por teclado ha sido el %f\n", r); // Impresion redundante, solo para depuracion		
	} else if (r<=0.0){
		DPRINTF("\nEl numero introducido por teclado ha de ser mayor que 0.0\n");
		return(INPUT_DATA_ERROR);
	} else {
		DPRINTF("\nSe ha producido un error inesperado al leer un numero del teclado\n");
		return(UNKNOWN_ERROR);
	}

	float longitud = longitud_circunferencia(r);
	printf("La longitud de una circunferencia de radio %f es: %0.5f\n", r, longitud);
#endif

#ifdef OTRAS_DIRECTIVAS_H_
	printf("\n============================\n");
	printf("EXPLICACION OTRAS DIRECTIVAS\n");
	printf("============================\n");	
	printf("\n/* #undef */");
	printf("\nSi es necesario \"des-definir\" una etiqueta o macro, usamos \"#undef\". Puede ser util al re-usar definiciones de librerias no actualizadas, que haya que \"parchear\", o en nuestro propio codigo. El compilador se encarga de sustituir los valores en el orden adecuado.\n");	
	usa_redefinicion();

	printf("\n/* #error */");
	printf("\nSi es indispensable que el usuario tome alguna accion de definir alguna etiqueta, por ejemplo, podemos forzar a que falle la compilacion y no llegue el codigo a fallar en ejecucion usando la directiva \"#error\".\n");	
	printf("Prueba a quitar el valor, o darle alguno incorrecto a la etiqueta \"#define IDIOMA\", y observa el fallo de compilacion.\n");
	detecta_error();
#endif

	return (0);
}