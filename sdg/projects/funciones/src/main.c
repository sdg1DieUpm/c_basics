/**
 * @file main.c
 * @brief Main file on functions in C.
 * 
 * Code about the use of functions and passing of argument by reference in C.
 * 
 * The code is a brief explanation on the basic use of functions and how to pass arguments by reference using memory
 * addresses and pointers. This is a very common example on how a code of the subject `SDG2` (the lab of Sistemas
 * Digitales) looks like. This code is focused to the introduction of C to the students of Sistemas Digitales of the
 * ETSI Telecomunicacion UPM. For the sake of a better comprehension of the students of the current degree, the
 * inline comments and the explanations printed out by the printf function are written in Spanish.
 *
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-23
 * 
 */

/* INCLUDES DEL SISTEMA */
#include <stdio.h>
#include <stdint.h>

/* INCLUDES PROPIOS */
#include "pantallas.h"

/**
 * @brief Main function of the project "funciones". Entry point of the program.
 * 
 * This code defines a screen which is a struct that contains several elements: the matrix of pixels itself, its size (number of rows and number of columns), and a field which is a void pointer to store almost anything that the user wants to store.
 * 
 * @return Result of the execution.
 */
int32_t main()
{
	pantalla_t mi_pantalla; // Declaro una pantalla
	mi_pantalla.num_rows = NUM_ROWS; // Defino el tamano (numero de filas y columnas) de mi pantalla
	mi_pantalla.num_cols = NUM_COLS;

	int32_t estado_inicializacion = INIT_FAIL; // A priori, no sabemos si ira bien

	printf("\n/* Paso de parametros por referencia */\n");
	printf("Cuando pasamos la referencia (la direccion de memoria) de nuestra variable, es porque queremos que la funcion haga cosas con \"esa\" variable, que esta en \"esa\" direccion de memoria. No queremos que trabaje con una copia de sus valores, sino que trabaje sobre su zona de memoria particularmente.\n");	
	printf("Se manda la direccion de memoria (&); si es un array, vale con su nombre, porque el nombre de un array es la direccion de memoria del array.\n");
    printf("En las funciones se recibe, claro, como un puntero. Si es una estructura lo que pasamos, a sus campos accedemos con \"->\" en vez de con \".\".\n");

	estado_inicializacion = inicializa_pantalla(&mi_pantalla);
	printf("Las funciones de inicializacion son muy comunes. Acostumbran a devolver un codigo de estado de como ha ido el proceso. Conviene recoger dicho valor y actuar en consecuencia; por ejemplo, si ha ido mal, saliendo del programa o avisando al usuario.\n");
    
	if (estado_inicializacion == INIT_OK){
		printf("\nLa pantalla se ha inicializado correctamente. Ilumino la pantalla.\n");						
		ilumina_pantalla(&mi_pantalla);	// Paso por referencia

		char *marca = "TelecoTV";		
		mi_pantalla.cajon_de_sastre = marca;
		// Hago cast de void* a puntero de caracteres (char*), y lo imprimo como string (%s): 
		printf("La marca de mi pantalla es: %s\n", (char*)(mi_pantalla.cajon_de_sastre));

		int32_t id_pantalla = 12345678;
		mi_pantalla.cajon_de_sastre = &id_pantalla;
		// Hago cast de void* a puntero de entero (int32_t*), luego cojo el valor donde apunta (*): 
		printf("El ID de mi pantalla es: %d\n", *(int32_t*)(mi_pantalla.cajon_de_sastre)); 


	} else {
		printf("\nHa habido un error al inicializar la pantalla. Saliendo del programa...\n");
		return(estado_inicializacion);
	}

	printf("\n/* Paso de parametros por valor */\n");
	printf("Requiere de otras funciones que no esperen recibir un puntero a una direccion de memoria.\n");
	printf("Se pasa una copia igual a mi variable, los mismos valores, pero no es mi variable la que se va a usar.\n");
	printf("Requiere que devuelva los cambios realizados si quiero sobreescribirlos en mi variable.\n");
	printf("Descomentar estas lineas para ver su funcionamiento:\n");	
	/*
	pantalla_t una_pantalla = inicializa_pantalla_2(mi_pantalla);
	mi_pantalla = una_pantalla;

	printf("\nPantalla inicializada mediante paso por valor. Muestro la pantalla:\n");
    for (int32_t i=0; i<mi_pantalla.num_rows ; i++){
        for (int32_t j=0; j<mi_pantalla.num_cols; j++){
            printf("(%d,%d,%d) ", mi_pantalla.matriz_RGB[i][j].led_r.estado, mi_pantalla.matriz_RGB[i][j].led_g.estado, mi_pantalla.matriz_RGB[i][j].led_b.estado);
        }
        printf("\n");
    }
	*/

	return (0);
}