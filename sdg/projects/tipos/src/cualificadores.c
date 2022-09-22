/**
 * @file cualificadores.c
 * @brief Explanation of variable qualifiers.
 *
 * Explanation of the use of qualifiers and their importance in the optimization and use of critical variables.
 *
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11
 * 
 */

#include "cualificadores.h"

/**
 * @brief Explanation of variable qualifiers.
 * 
 */
void explica_cualificadores(){
    printf("\nLos cualificadores dan informacion sobre el valor de una variable y la forma correcta de usar el dato.\n");
    printf("Tenemos 4: \"const\", \"volatile\", \"restrict\", y _Atomic (introducido en C11, 2011).\n");

    printf("\n/* const */\n");
    printf("\"const\" indica que una variable no puede modificarse. Se diferencia de #define en que, si intentamos modificarla, el compilador dara un error. #define define etiquetas, alias que se sustituyen en todo el código. \"const\" sirve para no trabajar con número mágicos, y suele estar en funciones.\n");

    const float e = 2.71828;
    printf("La constante \"e\" vale e= %f\n", e);
    printf("La etiqueta (\"#define\") \"E\" definida en \"cualificadores.h\" sustituye el texto E por %f\n", E);

    printf("Pero al ser puro texto, el (\"#define\") puede dar lugar a errores que \"const\" sobre una variable (que no varia!), no da.\n");

    printf("\n/* volatile */\n");
    printf("\"volatile\" indica que el valor de una variable no ha de ser optimizado por el compilador.\n");
    printf("Indica que el valor de la variable puede ser cambiado por otra funcion externa en cualquier momento y por lo tanto debe ser releída de la memoria cada vez que se accede a ella.\n");
    printf("Se encuentra frecuentemente en codigos que manipulan HW (como en los sistemas integrados) y en las aplicaciones multi-hilo (multi-thread).\n");
    printf("Es útil cuando trabajamos con rutinas de atención a la interrupción (ISR) que modifican, por ejemplo, variables que cambian de valor cuando ocurre una interrupción.\n");

}
