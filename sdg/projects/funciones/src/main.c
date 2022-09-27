#include <stdio.h>
#include <stdint.h>
#include "pantallas.h"


int32_t main()
{
	pantalla_t mi_pantalla; // Declaro una pantalla
	mi_pantalla.num_rows = NUM_ROWS; // Defino el tamano (numero de filas y columnas) de mi pantalla
	mi_pantalla.num_cols = NUM_COLS;

	int32_t estado_inicializacion = INIT_FAIL; // A priori, no sabemos si ira bien


	estado_inicializacion = inicializa_pantalla(&mi_pantalla);
	//pantalla_t una_pantalla = inicializa_pantalla_2(mi_pantalla);
	//mi_pantalla = una_pantalla;

	if (estado_inicializacion == INIT_OK){
		printf("\nLa pantalla se ha inicializado correctamente. Ilumino la pantalla.\n");						
		ilumina_pantalla(&mi_pantalla);	

		char *marca = "TelecoTV";
		mi_pantalla.cajon_de_sastre = marca;
		printf("La marca de mi pantalla es: %s\n", (char*)mi_pantalla.cajon_de_sastre);

	} else {
		printf("\nHa habido un error al inicializar la pantalla. Saliendo del programa...\n");
		return(-1);
	}
	return (0);
}