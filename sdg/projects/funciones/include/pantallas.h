#ifndef PANTALLAS_H_
#define PANTALLAS_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define NUM_ROWS 8
#define NUM_COLS 8

#define INIT_OK 0
#define INIT_FAIL 1

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

typedef struct Pantalla {
    pixel_t matriz_RGB[NUM_ROWS][NUM_COLS];
    int32_t num_rows;
    int32_t num_cols;
    void *cajon_de_sastre;
} pantalla_t;


int32_t inicializa_pantalla(pantalla_t *p_pantalla);
pantalla_t inicializa_pantalla_2(pantalla_t pantalla);
void ilumina_pantalla(pantalla_t *p_pantalla);
int32_t inicializa_pixel(pixel_t * p_pixel);
pixel_t inicializa_pixel_2(pixel_t pixel);
void ilumina_led(led_t *led);
void apaga_led(led_t *led);

#endif