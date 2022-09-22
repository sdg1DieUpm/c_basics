/**
 * @file ancho_fijo.c
 * @brief Explanation of the use of fixed-width integers.
 *
 * Explanation of why fixed-width integer types are used and their importance in the interoperability of 
 * code between machines.
 *
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11  
 */

#include "ancho_fijo.h"

/**
 * @brief Function to explain the need of interoperable codes using fixed-width integer variables.
 * 
 */
void explica_ancho_fijo(){
    printf("\nPara hacer que un codigo sea interoperable entre dispositivos de distinta arquitectura, se recomienda trabajar con tipos de entero de ancho fijo.\n");
    printf("Pensando en arquitecturas de microcontrolador, sin sistema operativo, al especificar su longitud hara que los codigos sean interoperables.\n");
    printf("En C no existen los tipos decimales (flotantes) de coma fija -porque float y double son de coma flotante-, por lo que esto solo se aplica a los enteros.\n");
    printf("\nLa lista de tipos enteros que usaremos queda definida por typedef en la libreria <stdint.h>, y son:\n");

    int8_t c = 's'; // Caracter imprimible en tabla ASCII, en decimal la 's' minuscula es 115, 0x73 en hexadecimal
    int16_t i16 = 32768-1; // Entero con signo de 16 bits ((2^16 /2) -1)
    uint16_t ui16 = 65536-1; // Entero sin signo de 16 bits (2^16 -1)
    int32_t i32 = 100000; // Entero con signo de 32 bits
    uint32_t ui32 = -200000; // Entero con signo de 32 bits
    

    printf("typedef char int8_t, que ocupa: %llu Bytes\n", sizeof(c));
    printf("typedef short int int16_t, que ocupa: %llu Bytes\n", sizeof(i16));
    printf("typedef unsigned short int uint16_t, que ocupa: %llu Bytes\n", sizeof(ui16));
    printf("typedef int int32_t, que ocupa: %llu Bytes\n", sizeof(i32));
    printf("typedef unsigned int uint32_t, que ocupa: %llu Bytes\n", sizeof(ui32));
}
