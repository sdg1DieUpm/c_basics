/**
 * @file almacenamiento.c
 * @brief Storage, life cycle and scope of variables.
 *
 * Explanation of the storage form, the life cycle of the variables and their scope according to their location in the code.
 *
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11   
 */

#include "almacenamiento.h"

/* VARIABLES GLOBALES */
static int32_t g_var_almacenamiento = 33; // No accesible desde el exterior (e.g. main)

/**
 * @brief Function to return the value of a global static variable.
 * 
 * @return int32_t the value of the global static variable.
 */
int32_t funcion_get(){
    return g_var_almacenamiento;
}

/**
 * @brief Function to set the value of a global static variable.
 * 
 * @param[in] valor The value of the global static variable.
 */
void funcion_set(int32_t valor){
    g_var_almacenamiento = valor;
}

/**
 * @brief Function to explain the use of static in local variables.
 * 
 */
void funcion_actualiza_numero(){
    static int32_t var_static_local = 0; // Por aqui solo pasa una vez
    int32_t var_no_static_local = 0; // Por aqui pasa siempre

    var_static_local += 1;
    var_no_static_local += 1;

    printf("\tAhora la variable estatica local vale: var_static_local= %d\n", var_static_local);
    printf("\tDe nuevo la variable NO estatica local vale: var_no_estatica_local= %d\n", var_no_static_local);
}

/**
 * @brief Function to explain the use of aliases using typedef.
 * 
 */
void explica_typedef(){
    printf("/* typedef */\n");
    printf("\n\"typedef\" no es para crear tipos, sino alias, i.e., llamar a una misma cosa por otro nombre. Generalmente se escriben acabados en \"_t\" para identificarlos rapidamente.\n");
    
    typedef uint32_t millas_t, km_t;
    millas_t distancia_imperial = 10; 
    km_t distancia_SI = 16;

    printf("\t\"millas\" es un uint32_t, que a su vez es \"unsigned int\", y ocupa: %llu Bytes.\n", sizeof(distancia_imperial));
    printf("\t\"km\" es un uint32_t, que a su vez es \"unsigned int\", y ocupa: %llu Bytes.\n", sizeof(distancia_SI));
}

/**
 * @brief Function to explain the use of extern and static variables.
 * 
 */
void explica_almacenamiento(){
    printf("El valor modificado en \"main\" de la variable externa puede ser leido aqui, en \"alamcenamiento.c\" y comprobamos que vale: var_externa= %d\n", var_externa);
    var_externa = 33;
    printf("Podemos modificar el valor la variable externa, que ahora vale: var_externa= %d\n", var_externa);

    printf("/* static */\n");
    printf("\n\"static\" dentro de una funcion, indica que esa variable mantiene su valor en las sucesivas llamadas a esa funcion.\n");
    for (int i=0; i<10; i++){
        printf("Vuelta i: %d\n", i);
        funcion_actualiza_numero();
    }
}
