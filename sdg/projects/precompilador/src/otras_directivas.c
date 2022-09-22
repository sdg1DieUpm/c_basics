/**
 * @file otras_directivas.c
 * @brief Code example to learn how to use less common pre-compile directive.
 *
 * This code focuses on the use of `#undef`, and `#error`. It also works with directives such as `#ifdef` or `#if`.
 *
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11 
 *  
 */
/* INCLUDES DEL SISTEMA */
#include <stdio.h>

/* INCLUDES PROPIOS */
#include "otras_directivas.h"

/**
 * @brief Function to explain the impact of the use of the directive `#undef`. 
 */
void usa_redefinicion(){
    printf("PI ya no es un numero, ahora PI es el sonido de una bocina... %s\n", PI);
}

/**
 * @brief Function to explain the use of the directive `#error`. 
 */
void detecta_error(){
#ifdef IDIOMA
#if IDIOMA == EN
    printf("Hello World!\n");
#elif IDIOMA == ES
    printf("Hola Mundo!\n");
#else
    #error El idioma especificado no es valido.
#endif
#else
    #error Se necesita especificar un idioma: EN o ES.
#endif
}
