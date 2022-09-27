/**
 * @file tipos.h
 * @brief Header file for the explanation about the types of variables in C.
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11
 */

#ifndef TIPOS_H_
#define TIPOS_H_

/* INCLUDES DEL SISTEMA */
#include <stdio.h>
#include <complex.h> // Para parte imaginaria de __Complex
#include <string.h> // Para usar strcpy

/* INCLUDES PROPIOS */


/* DEFINES Y ENUMS */
/** enum type to define RGB colors. **/
enum COLOR {
	ROJO, /*!< Red */
	VERDE, /*!< Green */
	AZUL /*!< Blue */
};

/** enum type to define the days of the week. **/
enum DIA {
		DOMINGO, /*!< Sunday */
		LUNES = 0, /*!< Monday */
		MARTES, /*!< Tuesday */
		MIERCOLES=-1, /*!< Wednesday */
		JUEVES, /*!< Thursday */
		VIERNES, /*!< Friday */
		SABADO /*!< Saturday */
	};

/* DECLARACION DE NUEVOS TIPOS */
// Estructuras
/**
 * @struct Alumno
 * @brief Struct type of a student.
 */
/**
 * @typedef alumno_t
 * @brief Typedef of Alumno
 */
typedef struct Alumno {
	char nombre[20]; /*!< Array of chars to store student's name  */
	float notas[6]; /*!< Array of ints to store student's grades  */
} alumno_t;



// Uniones	
/**
 * @union Alumno_u 
 * @brief Union type of a student.
 */
/**
 * @typedef alumno_u
 * @brief Typedef of Alumno_u
 */

typedef union Alumno_u {
	char nombre[20]; /*!< Array of chars to store student's name  */
	float notas[6]; /*!< Array of ints to store student's grades  */
} alumno_u;	


/* PROTOTIPO DE FUNCIONES */
void explica_tipos(void);

#endif