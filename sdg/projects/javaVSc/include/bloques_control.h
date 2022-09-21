/**
 * @file bloques_control.h
 * @brief Header file for the explanation loops and conditional blocks in C. * 
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11
 */

#ifndef BLOQUES_CONTROL_H_
#define BLOQUES_CONTROL_H_

/* INCLUDES DEL SISTEMA */
#include <stdio.h>
#include <stdint.h>

/* INCLUDES PROPIOS */


/* DEFINES Y ENUMS */
#define TEMPERATURA_CONFORT_HIGH 27.0
#define TEMPERATURA_CONFORT_LOW 10.5

enum CLIMA {
    SOLEADO,
    NUBLADO,
    LLUVIOSO
};
char *nombres_climas[3] = {"SOLEADO", "NUBLADO", "LLUVIOSO"};

/* DECLARACION DE NUEVOS TIPOS */	


/* PROTOTIPO DE FUNCIONES */
void explica_bucles(void);
void explica_bloques_condicionales(float temp, int8_t cli);

#endif