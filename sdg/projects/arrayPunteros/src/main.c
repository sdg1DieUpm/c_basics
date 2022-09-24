#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define TAM_ARRA_A 5
#define NUM_ROWS 8
#define NUM_COLS 8

enum COLOR {
	RED, GREEN, BLUE
};

typedef struct Led {
	int8_t color;
	bool estado;
} led_t;

typedef struct Pixel {
	led_t led_r;
	led_t led_g;
	led_t led_b;
} pixel_t;

int32_t main()
{
	int32_t arr[TAM_ARRA_A];
	int32_t arr_destino[TAM_ARRA_A];

	for (int32_t i=0; i<TAM_ARRA_A; i++){
		arr[i] = i+1;
		printf("arr[%d]=%d\n", i, arr[i]);
	}

	memcpy(arr_destino, arr, sizeof(arr));

	int32_t otro_arr[] = {33, 34};
	printf("otro_arr[0]=%d\n", otro_arr[0]);
	printf("otro_arr[1]=%d\n", otro_arr[1]);

	/* 
	int32_t otro_arr2[];
	otro_arr2[0] = 1;
	*/

	pixel_t pantalla[NUM_ROWS][NUM_COLS];

	for (int32_t i=0; i<NUM_ROWS; i++){
		for (int32_t j=0; j<NUM_COLS; j++){
			pantalla[i][j].led_r.color = RED; 
			pantalla[i][j].led_r.estado = true;

			pantalla[i][j].led_g.color = GREEN; 
			pantalla[i][j].led_g.estado = false;

			pantalla[i][j].led_b.color = BLUE; 
			pantalla[i][j].led_b.estado = true;
		}
	}

	for (int32_t i=0; i<NUM_ROWS; i++){
		for (int32_t j=0; j<NUM_COLS; j++){
			printf("(%d,%d,%d),", pantalla[i][j].led_r.estado, pantalla[i][j].led_g.estado, pantalla[i][j].led_b.estado);
		}
		printf("\n");
	}

	/*char cadena[5] = {'H', 'o', 'l', 'a', '\0'};
	char cadena[] = {'H', 'o', 'l', 'a', '\0'};
	char cadena[] = "Hola"; */

	char *cadena = "Hola\n";

	printf("%s", cadena);

	int32_t longitud = (int32_t)strlen(cadena);

	for(int32_t i=0; i<longitud; i++){
		printf("0x%X, ", cadena[i]);
	}
	char cadena_destino[(int32_t)strlen(cadena)+1];
	strcpy(cadena_destino, cadena);
	printf("%s", cadena_destino);
	

	/* PUNTEROS */	
	// Las variables
	int32_t	a = 100;
	int32_t	b;
	int32_t *p_arr, *p_a;
	pixel_t *p_pixel;

	// Punteros
	//int32_t *p_a = &a;
	p_a = &a;
	p_arr = arr;  
	p_pixel = &pantalla[0][0];
	
	// La direccion de memoria se indica con el simbolo ampersand (&):	
	printf("La dirección de memoria de a, en hexadecimal es: %p", p_a);
	fflush(stdout);  // Fuerza a que vacie el buffer de la salida estandar (terminal) y lo imprima ya

	// Tamano del puntero
	printf("\nTamano del puntero p_arr: %d\n", (int32_t)sizeof(p_arr));
	printf("Tamano del puntero p_a: %d\n", (int32_t)sizeof(p_a));
	printf("Tamano del puntero p_pixel: %d\n", (int32_t)sizeof(p_pixel));
	
	// Cosas QUE PODEMOS HACER BIEN con los punteros
	// (1) Guardar en el una direccion de memoria
	p_a = &a;   // p_a guarda la (apunta a la) direccion de memoria de "a"
	b = *p_a;   // guarda en "b" el contenido que hay donde apunta "p_a"

	printf("a --> Se lee: el valor de a. a es %d\n", a);
	printf("&a --> Se lee: direccion de memoria de a. &a es %p\n", &a); // %p para imprimir direcciones de memoria
	printf("p_a --> Se lee: el valor de p_a; que es la direccion de a. p_a es %p\n", p_a); 
	printf("*p_a --> Se lee: el valor que hay donde apunta p_a. b=*p_a es %d\n", b);
	printf("&p_a --> Se lee: direccion de memoria de p_a. &p_a es %p\n", &p_a);	
	
	p_arr = arr; // p_a guarda (apunta) a la direccion de memoria del primer elemento de "arr", o de “arr”. El nombre de un array es la direccion de memoria del array, y del primer elemento del array
	
	// (2) Guardar de manera indirecta un valor alli donde apunta
	*p_a = 33; // Ahora el valor de "a" ha cambiado, pero p_a sigue apuntando a la direccion de "a"
	printf("Nuevo valor de a. a es %d\n", a);
	printf("p_a sigue apuntando a la direccion de a. p_a es %p\n", p_a);
	
	// Cosas QUE PODEMOS HACER MAL con los punteros
	// (3) Asignar al valor de p_a, el valor de a, porque estaria apuntando a la direccion de memoria 33. Dara segmentation fault (violacion de segmento):
	//p_a = a; // ERROR. p_a es una direccion, pero a, no
	
	// (4) Que el valor que hay en la direccion de memoria donde apunta p_a (es decir, direccion de memoria 33) sea la direccion de memoria de a:
	//*p_a = &a; // ERROR porque &a es una direccion, pero *p_a, no
	
	// (5) Asignar al valor de p_a, un valor directamente, porque puede estar fuera del rango de memoria:
	// p_a = 33; // ERROR p_a es una direccion, pero 33, no

	// OTRAS cosas QUE PODEMOS HACER con los punteros
	// (6) Punteros a "void" (puntero a la "cualquier cosa")
	//void *p_void; // "void" es un tipo especial en C. Sirve para hacer un "typecasting" a calquier cosa
	
	// (7) Puntero a "NULL" (puntero a la "nada")
	p_a = NULL; // Cuando se asigna el valor NULL (<stdlib.h>), se le dice puntero a NULL. Genera "segmentation fault". Apunta a direcciones de memoria fuera del rango accesible. Es igual que definir un puntero sin asignarle valor; dara error.

	//int32_t *p_b;
	//printf("Valor donde apunta p_b: %d", *p_b);

	/* (8) Aritmetica de punteros: 
	 - Podemos sumar y restar enteros a un puntero (en Bytes), para que apunten a direcciones de memoria distintas. 
	 - Podemos restar punteros para ver la distancia entre elementos de un array.
	 - NO SE PUEDEN SUMAR PUNTEROS, NI OTRAS OPERACIONES.
	*/
	p_arr = arr;
	for (int32_t i = 0; i< TAM_ARRA_A; i++){		
		*p_arr *= 100;				
		printf("Ahora el valor donde apunta p_arr es: %d, en la direccion de memoria: %p\n", *p_arr, p_arr); 
		p_arr += 1; // Actualizo puntero para que apunte a la siguiente direccion de memoria del array
	}

	printf("\nLa distancia entre el 1er y el ultimo elemento del array \"arr\" es de %d elementos de int32_t\n", (int32_t)(p_arr-arr));
	p_arr = arr; // Volvemos a apuntar a la 1a direccion de memoria

	return (0);
}