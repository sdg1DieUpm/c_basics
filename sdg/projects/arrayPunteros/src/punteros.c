/**
 * @file punteros.c
 * @brief Explanation of the basic use of pointers in C.
 *
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-23
 *    
 */

/* INCLUDES PROPIOS */
#include "punteros.h"

/**
 * @brief Function to explain the use of pointers in C. It includes an example about how get things well done, and how to avoid errors. It shows the use of `fflush`, and explanation of pointer arithmetic, void and NULL pointers.
 */
void explica_punteros(){
    // Las variables
    int32_t arr[TAM_ARRAY_A];
	int32_t	a = 100;
	int32_t	b;
    pixel_t pantalla[NUM_ROWS][NUM_COLS];

    printf("\n/* Declaracion de punteros sin inicializacion */\n");
	int32_t *p_arr, *p_a;  // Declaracion de dos variables (punteros) en la misma linea
    pixel_t *p_pixel;
	
	// La direccion de memoria se indica con el simbolo ampersand (&)
	//int32_t *p_a = &a;
	p_a = &a;
	p_arr = arr;  
	p_pixel = &pantalla[0][0];
	
	
	printf("La dirección de memoria de a, en hexadecimal es: %p\n", p_a);
	fflush(stdout);  // Fuerza a que vacie el buffer de la salida estandar (terminal) y lo imprima ya
    
    printf("\n/* Tamano de un puntero */\n");		
	printf("Tamano del puntero p_arr: %d\n", (int32_t)sizeof(p_arr));
	printf("Tamano del puntero p_a: %d\n", (int32_t)sizeof(p_a));
	printf("Tamano del puntero p_pixel: %d\n", (int32_t)sizeof(p_pixel));
	
	
    printf("\n/* Cosas QUE PODEMOS HACER BIEN con los punteros */\n");
    printf("/* (1) Guardar en el una direccion de memoria */\n");	
	p_a = &a;   // p_a guarda la (apunta a la) direccion de memoria de "a"
	b = *p_a;   // guarda en "b" el contenido que hay donde apunta "p_a"

	printf("a --> Se lee: el valor de a. a es %d\n", a);
	printf("&a --> Se lee: direccion de memoria de a. &a es %p\n", &a); // %p para imprimir direcciones de memoria
	printf("p_a --> Se lee: el valor de p_a; que es la direccion de a. p_a es %p\n", p_a); 
	printf("*p_a --> Se lee: el valor que hay donde apunta p_a. b=*p_a es %d\n", b);
	printf("&p_a --> Se lee: direccion de memoria de p_a. &p_a es %p\n", &p_a);	
	
	p_arr = arr; // p_a guarda (apunta) a la direccion de memoria del primer elemento de "arr", o de “arr”. El nombre de un array es la direccion de memoria del array, y del primer elemento del array
	
    printf("\n/* (2) Guardar de manera indirecta un valor alli donde apunta */\n");
	*p_a = 33; // Ahora el valor de "a" ha cambiado, pero p_a sigue apuntando a la direccion de "a"
	
    printf("Nuevo valor de a. a es %d\n", a);
	printf("p_a sigue apuntando a la direccion de a. p_a es %p\n", p_a);
	
	printf("\n/* Cosas QUE PODEMOS HACER MAL con los punteros */\n");
    printf(" NOTA: descomentar lineas para probar los errores.\n");
    printf("/* (3) ERROR: Asignar al valor de \"p_a\", el valor de \"a\", porque \"p_a\" es una direccion, pero \"a\", no. */\n");
	//p_a = a; // ERROR. Estaria apuntando a la direccion de memoria 33
	
	printf("\n/* (4) ERROR: Que el valor que hay en la direccion de memoria donde apunta \"p_a\" sea la direccion de memoria de \"a\", porque \"&a\" es una direccion, pero \"*p_a\", no*/\n");
	//*p_a = &a; // ERROR porque &a es una direccion, pero *p_a, no
	
	printf("\n/* (5) ERROR: Asignar al valor de \"p_a\", un valor directamente, porque puede estar fuera del rango de memoria, ya que \"p_a\" es una direccion, pero \"un valor\", no*/\n");	
	// p_a = 33; // ERROR 

	printf("\n/* OTRAS cosas QUE PODEMOS HACER con los punteros */\n");
    printf("/* (6) Punteros a \"void\" (puntero a \"cualquier cosa\") */\n");
    // Descomentar para poder usarlo:    	
	//void *p_void; // "void" es un tipo especial en C. Sirve para hacer un "typecasting" a calquier cosa
	
	printf("\n/* (7) Puntero a \"NULL\" (puntero a la \"nada\") */\n");
    p_a = NULL; // Cuando se asigna el valor NULL (<stdlib.h>), se le dice puntero a NULL. Genera "segmentation fault". Apunta a direcciones de memoria fuera del rango accesible. Es igual que definir un puntero sin asignarle valor; dara error.
    
    printf("\n/* (7bis) ERROR: Generamos un puntero a \"NULL\" cuando no se inicializa un puntero. Si se intenta usar da error.*/\n");
    printf(" NOTA: descomentar lineas para probar los errores.\n");
    //int32_t *p_b;
	//printf("Valor donde apunta p_b: %d", *p_b);


	printf("\n/* (8) Aritmetica de punteros */\n");
    printf("\t- Podemos sumar y restar enteros a un puntero (en Bytes), para que apunten a direcciones de memoria distintas. \n");
	printf("\t- Podemos restar punteros para ver la distancia entre elementos de un array.\n");
	printf("\t- NO SE PUEDEN SUMAR PUNTEROS, NI OTRAS OPERACIONES.\n");
	
    p_arr = arr;
	for (int32_t i = 0; i< TAM_ARRAY_A; i++){		
		*p_arr *= 100;				
		printf("Ahora el valor donde apunta p_arr es: %d, en la direccion de memoria: %p\n", *p_arr, p_arr); 
		p_arr += 1; // Actualizo puntero para que apunte a la siguiente direccion de memoria del array
	}

	printf("\nLa distancia entre el 1er y el ultimo elemento del array \"arr\" es de %d elementos de tipo int32_t.\n", (int32_t)(p_arr-arr));
	p_arr = arr; // Volvemos a apuntar a la 1a direccion de memoria
}