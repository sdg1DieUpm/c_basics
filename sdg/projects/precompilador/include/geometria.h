/**
 * @file geometria.h
 * @brief Header file of geometria.c.
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11
 */

/**
 * @def PRECISION
 * @brief The macro to define the version of number `PI` to work with according to the number of decimal digits especified.
 * 
 * Define `PRECISION` as `ALTA` or `BAJA`, otherwise the pre-compiler will raise an `#error`. 
 */

/**
 * @def ALTA
 * @brief Macro used to work with a version of number `PI` equals 3.141592654 
 */

/**
 * @def BAJA
 * @brief Macro used to work with a version of number `PI` equals 3.14
 */

/**
 * @def PI
 * @brief Macro to represent the PI number.
 */

/**
 * @def LONGITUD_CIRC(r)
 * @brief Macro that computes the circumference of a circle with radius `r`. 
 */

#ifndef GEOMETRIA_H_
#define GEOMETRIA_H_

/* INCLUDES PROPIOS */


/* DEFINES Y ENUMS */
#define ALTA 0
#define BAJA 1

#define PRECISION BAJA

#ifdef PRECISION
#if PRECISION == ALTA
#define PI 3.141592654
#elif PRECISION == BAJA
#define PI 3.14
#else
#error La PRECISION especificada no es valida
#endif
#define LONGITUD_CIRC(r) 2*PI*r
#else
#error Se necesita especificar una PRECISION: ALTA o BAJA
#endif

/* VARIABLES */


/* DECLARACION DE NUEVOS TIPOS */	


/* PROTOTIPO DE FUNCIONES */
float longitud_circunferencia(float r);


#endif