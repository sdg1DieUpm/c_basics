/**
 * @file otras_directivas.h
 * @brief Header file of otras_directivas.c.
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11
 */

/**
 * @def PI
 * @brief The macro to define `PI` as a string instead of a number.  
 */

/**
 * @def IDIOMA
 * @brief The macro to define the language to work with.
 * 
 * Define `IDIOMA` as `ES` or `EN`, otherwise the pre-compiler will raise an `#error`. Values such as `FR` are not considered in the code.
 */

/**
 * @def EN
 * @brief Macro used to work with the English version of the `printf` texts in some functions.
 */

/**
 * @def ES
 * @brief Macro used to work with the Spanish version of the `printf` texts in some functions.
 */

/**
 * @def FR
 * @brief Unused macro to show how to work with the directive `#error` and invalid values. It might be intended to represent the French language.
 */

#ifndef OTRAS_DIRECTIVAS_H_
#define OTRAS_DIRECTIVAS_H_

/* INCLUDES PROPIOS */


/* DEFINES Y ENUMS */
#undef PI // Ya no sera la etiqueta definida en geometria.h
#define PI "Piiiiiii" // Ahora sera un texto

#define EN 0
#define ES 1
#define FR 2
 
#define IDIOMA ES

/* VARIABLES */


/* DECLARACION DE NUEVOS TIPOS */	


/* PROTOTIPO DE FUNCIONES */
void detecta_error(void);
void usa_redefinicion(void);

#endif

