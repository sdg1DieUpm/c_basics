/**
 * @file almacenamiento.h
 * @brief Header file of storage, life cycle and scope of variables.
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11
 */

#ifndef ALMACENAMIENTO_H_
#define ALMACENAMIENTO_H_

/* INCLUDES DEL SISTEMA */
#include <stdio.h>
#include <stdint.h>

/* INCLUDES PROPIOS */


/* DEFINES Y ENUMS */


/* VARIABLES */
extern int32_t var_externa; // Se declara externa, esta definida en otro fichero (en main.c)

/* DECLARACION DE NUEVOS TIPOS */	


/* PROTOTIPO DE FUNCIONES */
void funcion_actualiza_numero(void);
void explica_almacenamiento(void);
void explica_typedef(void);
int32_t funcion_get(void);
void funcion_set(int32_t valor);

#endif