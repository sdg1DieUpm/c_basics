/**
 * @file booleanos.c
 * @brief Explanation of the stdbool library.
 *
 * Explanation of the use of the \<stdbool> library introduced in C99.
 * 
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11 
 * */

#include "booleanos.h"

/**
 * @brief Function to explain the use of the \<stdbool\> library.
 * 
 */
void explica_booleanos(){
    printf("\nDesde C99 (1999), se incluye el tipo \"_Bool\" y la libreria <stdbool.h> con las macros \"bool\",  \"true\" y \"false\". Interesante entrar a la libreria y ver que es una etiqueta hecha con \"#define\" y no un tipo hecho con \"typedef\".\n");
    printf("Si en algun sitio dicen que en C no existen booleanos, es porque estan hablando de C89 (1989).\n");
    printf("Esto puede ser porque se esten usando codigos muy antiguos, o porque, a veces, el compilador compila por defecto (por compatibilidad hacia atras con dispositivos antiguos) con el estandar de C89, aunque se puede forzar al compilador a que compile en C99 o superior.\n");
    printf("Tradicionalmente la gente definia sus propias macros para TRUE y FALSE. Sirve para hacer codigos mas comodos de interpretar, tal vez, pero no ahorran memoria:\n");

    bool bt = true;
    bool bf = false; 

    printf("true ocupa: %llu Bytes\n", sizeof(bt));
    printf("false ocupa: %llu Bytes\n", sizeof(bf));

    printf("\nPodemos hacer operaciones Booleanas con ellos:\n");
    printf("true OR false es: bt | bf = %d\n", bt | bf);
    printf("true AND false es: bt & bf = %d\n", bt & bf);
    printf("true XOR true es: bt ^ bt = %d\n", bt ^ bt);    
}
