/**
 * @file geometria.c
 * @brief Code example to learn how to use the `#define` directive.
 *
 * Create macros, defines, and also use other pre-compile directives such as `#ifdef` or `#if`.
 *
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11 
 *  
 */

/* INCLUDES DEL SISTEMA */

/* INCLUDES PROPIOS */
#include "geometria.h"

/**
 * @brief Function that returns the the circumference of a circle with radius `r`.
 * 
 * @param r Radius of the circle.
 * @return Value of the circumference.
 */
float longitud_circunferencia(float r){
    return LONGITUD_CIRC(r);
}