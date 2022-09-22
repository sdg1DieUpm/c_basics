/**
 * @file tipos.c
 * @brief Explanation about the types of variables in C.
 *
 * Explanation of primitive variable types, derivatives, structures, unions, pointers and functions in C.
 *
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11
 */

#include "tipos.h"

/**
 * @brief Function to explain the different types of variables in the C programing language.
 * 
 */
void explica_tipos(){
	printf("\nLOS OBJETOS DE C\n");

	/* Segun C99 todo esto son LOS OBJETOS DE C: variables, funciones, punteros, enumerados, estructuras... */
	printf("En C no tenemos objetos entendidos como en Java...!!!\n");

    /* (1) TIPOS PRIMITIVOS */
    printf("\n/* TIPOS PRIMITIVOS */\n");
    
	// (1a) Tipos primitivos enteros
	printf("/* Tipos primitivos enteros */\n");
    _Bool b = 1; // Solo puede ser 1, o 0
	char c = 'a'; // Siempre 1 Byte. Comillas simples si queremos representarlo como caracter
	short int si = 32000; 
	int i = -2147483648;
	long int li = -2147483648;
	long long int lli = -9223372036854775807;

	printf("\nBytes que ocupa tipo _Bool: %llu\n", sizeof(b));
	printf("Bytes que ocupa tipo char: %llu\n", sizeof(c));
    printf("Bytes que ocupa tipo short int: %llu\n", sizeof(si));
    printf("Bytes que ocupa tipo int: %llu\n" ,sizeof(i));
    printf("Bytes que ocupa tipo lont int: %llu\n", sizeof(li));
    printf("Bytes que ocupa tipo long long int: %llu\n", sizeof(lli));

	// Podemos ver los limites de cada tipo definidos en la libreria <limits.h>
	
	// (1b) Tipos primitivos decimales o flotantes reales
	printf("/* Tipos primitivos decimales o flotantes reales */\n");
    float f = 3.14e-30;
	double d = 1.79769e+108;
	long double ld= 3.4e+220;

	printf("\nBytes que ocupa tipo float: %llu\n",sizeof(f));
    printf("Bytes que ocupa tipo double: %llu\n",sizeof(d));
    printf("Bytes que ocupa tipo long double: %llu\n",sizeof(ld));
    
	// (1c) Tipos primitivos flotantes complejos (necesita libreria <complex.h> para parte imaginaria)
	printf("/* Tipos primitivos flotantes complejos */\n");
    _Complex ri = 1.5 + 2.0f*_Complex_I;
	printf("\nBytes que ocupa tipo _Complex: %lli\n",sizeof(ri));
    
	/* (1) TIPOS ESPECIALES */
    printf("\n/* TIPOS ESPECIALES */\n");

	// (2a) Especiales: Enumerados
    printf("/* Enumerados */\n");
    
	int color_cielo = AZUL;
	printf("\nLa clave ROJO vale: %d\n", ROJO);
	printf("La variable color vale: %d\n", color_cielo);
	printf("La clave VERDE vale: %d\n", VERDE);
	
	int dia = DOMINGO;
	printf("\nEl valor de dia es: %d\n", dia);
	printf("La clave LUNES vale: %d\n", LUNES);
	printf("La clave MARTES vale: %d\n", MARTES);
	printf("La clave SABADO vale: %d\n", SABADO);

	// (2a) Especiales: Void
	printf("/* Void */\n");
    printf("\nNo se puede declarar una variable como void\n");
	printf("Si una funcion no devuelve nada, su prototipo se pone como \"void nombre_funcion(...)\"\n");
	printf("Un puntero a void luego puede ser convertido a cualquier cosa. Lo encontraremos en funciones que pueden aceptar argumentos de tipos, a priori, desconocidos.\n");
	
	/* (3) TIPOS DERIVADOS */
    printf("\n/* TIPOS DERIVADOS */\n");
    // (3a) Arrays
    printf("/* Arrays */\n");
    int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	printf("\nLos elementos del array \"arr\" son:\n");
	for (int row = 0; row<3; row++)	{
		for (int col = 0; col<3; col++) {
			printf("%d,", arr[row][col]);
		}	
		printf("\n");	
	}

	// (3b) Estructuras
    printf("/* Estructuras */\n");
	alumno_t el_mejor_alumno;
	strcpy(el_mejor_alumno.nombre, "Ariel Perez"); // string copy, copia en destino string dado. Se vera mas adelante
	el_mejor_alumno.notas[0] = 10.0;
	
    printf("\nEl campo \"nombre\" de la estructura \"alumno\" de nuestro mejor alumno es: %s\n", el_mejor_alumno.nombre);
	printf("El campo \"nota\" con dos decimales de nuestro mejor alumno es: %0.2f\n", el_mejor_alumno.notas[0]);

	// (3c) Uniones
    printf("/* Uniones */\n");
	printf("\nEl tamano de la estructura \"alumno_t\" es: %llu\n", sizeof(alumno_t));
	printf("El tamano de la union \"alumno_u\" es: %llu\n", sizeof(alumno_u));
	printf("El tamano de la estructura es la suma del tamano de cada elemento: 20+6*sizeof(float)\n");
	printf("El tamano de la union es el tamano del elemento mas grande: 6*sizeof(float)\n");
	
	printf("\nPero las uniones comparten memoria, y en cuanto se asigna un elmento, se modifica otro:\n");
	alumno_u el_peor_alumno; // Creamos la variable
	strcpy(el_peor_alumno.nombre, "Andrea Rodriguez"); // string copy, copia en destino string dado. Se vera mas adelante
	printf("El campo \"nombre\" de la union \"alumno\" de nuestro peor alumno es: %s\n", el_peor_alumno.nombre);
	el_peor_alumno.notas[0] = 1.0;
	printf("El campo \"nombre\" de la union \"alumno\" tras asignar la nota es: %s\n", el_peor_alumno.nombre);
	
    printf("\nA los campos de las estructuras y de las uniones se accede con un punto \".\", o con flecha \"->\", si la variable nos la pasan como puntero de forma indirecta.\n");
	
	/* FUNCIONES */
    printf("\n/* FUNCIONES */\n");
	printf("\nUna funcion realiza una tarea que devuelve un valor de un tipo especificado (puede ser void si no devuelve nada). Una funcion queda definida por el tipo devuelto, el nombre y el numero y tipos de sus argumentos de entrada.\nLas estudiaremos mas adelante.\n");

	/* PUNTEROS */
    printf("\n/* PUNTEROS */\n");
	printf("\nUn tipo de puntero puede derivarse de una función, de un tipo primitivo, o de un derivado. Una variable de tipo puntero es una variable cuyo valor es una referencia a la zona de memoria de otro elemento de ese tipo. Se le llama \"puntero a X\".\nLos estudiaremos mas adelante.\n");
}