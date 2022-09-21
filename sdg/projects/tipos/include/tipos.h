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
enum COLOR {
	ROJO, VERDE, AZUL
};

enum DIA {
		DOMINGO,
		LUNES = 0,
		MARTES, 
		MIERCOLES=-1,
		JUEVES,
		VIERNES,
		SABADO
	};

/* DECLARACION DE NUEVOS TIPOS */
// Estructuras
/**
 * @struct Alumno
 * @brief Struct type of a student.
 * 
 * @var Alumno::nombre
 * Array of chars to store student's name 
 * @var Alumno::notas
 * Array of ints to store student's grades 
 */
/**
 * @struct alumno_t
 * @brief Typedef of Alumno
 */
typedef struct Alumno {
	char nombre[20]; 
	float notas[6]; // Array de 6 elementos
} alumno_t;



// Uniones	
/**
 * @union Alumno_u 
 * @brief Union type of a student.
 * 
 * @var Alumno_u::nombre
 * Array of chars to store student's name 
 * @var Alumno_u::notas
 * Array of ints to store student's grades 
 */
/**
 * @union alumno_u
 * @brief Typedef of Alumno_u
 */

typedef union Alumno_u {
    char nombre[20]; 
  	float notas[6];  	// Array de 6 elementos	
} alumno_u;	


/* PROTOTIPO DE FUNCIONES */
void explica_tipos(void);

#endif