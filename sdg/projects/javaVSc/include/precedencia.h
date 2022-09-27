/**
 * @file precedencia.h
 * @brief Header file for the explanation the rules of precedence.
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11
 */

/**
 * @def MASCARA_BINARIA
 * @brief Macro that defines a mask to work with binary operators.
 */

#ifndef PRECEDENCIA_H_
#define PRECEDENCIA_H_

/* INCLUDES DEL SISTEMA */
#include <stdio.h>
#include <stdint.h>

/* INCLUDES PROPIOS */


/* DEFINES Y ENUMS */
#define MASCARA_BINARIA 0x0040   // Las mascaras tiene 1 o varios bit activos (a 1). Puede ponerse en decimal (0x40=64)

/* DECLARACION DE NUEVOS TIPOS */	


/* PROTOTIPO DE FUNCIONES */
void explica_precedencia(void);


#endif