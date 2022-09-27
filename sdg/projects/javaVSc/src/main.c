
/**
 * @file main.c
 * @brief Main file on types of variables in C.
 * 
 * Code about the main differences between C and Java.
 * 
 * The code focuses on the theoretical aspects that distinguishes the C and the Java languages.
 * 
 * In this code we talk about precedence rules, control blocks: loops, conditionals..., and structures.
 * 
 * This code is oriented to the introduction of C to the students of Sistemas Digitales of the ETSI Telecomunicacion 
 * UPM. It is strongly recommended to comment and uncomment the \#includes of the different parts of the explanations to
 * be able to experiment with the code in order to make the terminal output more friendly.
 * 
 * For the sake of a better comprehension of the students of the current degree, the inline comments and the
 * explanations printed out by the printf function are written in Spanish.
 * 
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11
 */

/* INCLUDES DEL SISTEMA */
#include <stdio.h>
#include <stdint.h>

/* INCLUDES PROPIOS */
#include "precedencia.h"
#include "bloques_control.h"

/**
 * @brief Main function of the project "javaVSc". Entry point of the program.
 * 
 * @return Result of the execution.
 */
int32_t main()
{

#ifdef PRECEDENCIA_H_
	printf("\n==========================\n");
	printf("EXPLICACION DE PRECEDENCIA\n");
	printf("==========================\n");
	explica_precedencia();
#endif

#ifdef BLOQUES_CONTROL_H_
	printf("\n=================================\n");
	printf("EXPLICACION DE BLOQUES DE CONTROL\n");
	printf("=================================\n");
	printf("\nLas variables declaradas y definidas dentro de los bloques solo tienen alcance dentro de el, por lo que pueden reutilizarse los nombres luego.\n\n");

	explica_bucles();
	explica_bloques_condicionales(25.3, NUBLADO);
#endif

	return (0);
}