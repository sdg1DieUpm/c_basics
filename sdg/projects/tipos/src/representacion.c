/**
 * @file representacion.c
 * @brief Representation of variables, ASCII and printf.
 *
 * Explanation of variable representation and ways to interpret them. ASCII representation and conversion 
 * table of the printf function. It is highly recommended to have a look the ASCII table and the conversion 
 * table of the printf function.
 *
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11
 * 
 */

#include "representacion.h"

/**
 * @brief Function to explain how to work with the value of a variable according to its representation.  
 * 
 */
void explica_representacion(){
    printf("\nLo que importa de una variable es su valor almacenado en memoria, como 1s y 0s.\n");
    printf("Es cuestion del programador como se interprete o represente dicho valor.\n");

    int8_t x = 66;
    printf("x interpretado como un entero vale x= %d\n", x);
    printf("x interpretado como un valor hexadecimal vale x=0x %x\n", x);
    printf("x interpretado como un valor octal vale x=Ox %o\n", x);
    printf("x interpretado como un caracter vale x= %c\n", x);

    int8_t y = 50;
    printf("x +y interpretado como una suma de enteros vale x+y= %d\n", x+y);
    printf("x +y interpretado como una suma de caracteres vale x+y= %c\n", x+y);

    printf("Suma de caracteres \'(\' y \'<\' interpretado como enteros vale \'(\'+\'<\'= %d\n", '('+'<');
    printf("Suma de caracteres \'(\' y \'<\' interpretado como caracteres vale \'(\'+\'<\'= %c\n", '('+'<');
}
