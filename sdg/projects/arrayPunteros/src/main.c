/**
 * @file main.c
 * @brief Main file on arrays, strings and pointers in C.
 * 
 * Code about the definition and use of arrays, strings and pointers in C.
 * 
 * The code is a brief explanation on the basic use of arrays, strings and pointers with examples and tips of what 
 * it can be done correctly and typical errors made by students. This code is focused to the introduction of C to
 * the students of Sistemas Digitales of the ETSI Telecomunicacion UPM. It is strongly recommended
 * to comment and uncomment the \#includes of the different parts of the explanations to be able to experiment with the
 * code in order to make the terminal output more friendly.
 * 
 * For the sake of a better comprehension of the students of the current degree, the inline comments and the
 * explanations printed out by the printf function are written in Spanish.
 *
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-23
 * 
 */

/* INCLUDES DEL SISTEMA */
#include <stdio.h>
#include <stdint.h>

/* INCLUDES PROPIOS */
//#include "arrays.h"
//#include "strings.h"
#include "punteros.h"

/**
 * @brief Main function of the project "arrayPunteros". Entry point of the program.
 * 
 * @return Result of the execution.
 */
int32_t main()
{
#ifdef ARRAYS_H_
	printf("\n==================\n");
	printf("EXPLICACION ARRAYS\n");
	printf("==================\n");

	explica_arrays();
#endif

#ifdef STRINGS_H_
	printf("\n==================\n");
	printf("EXPLICACION STRINGS\n");
	printf("===================\n");

	explica_strings();
#endif

#ifdef PUNTEROS_H_
	printf("\n====================\n");
	printf("EXPLICACION PUNTEROS\n");
	printf("====================\n");

	explica_punteros();
#endif
	


	return (0);
}