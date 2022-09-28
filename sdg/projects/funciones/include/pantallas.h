/**
 * @file pantallas.h
 * @brief Header file for the explanation of the use of functions in C. 
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-23
 */

/**
 * @def NUM_ROWS
 * @brief Macro to defines the number of rows of a matrix of pixels.
 */

/**
 * @def NUM_COLS
 * @brief Macro to defines the number of columns of a matrix of pixels.
 */

/**
 * @def INIT_OK
 * @brief Macro to indicate that the initialization functions have performed correctly.
 */

/**
 * @def INIT_FAIL
 * @brief Macro to indicate that the initialization functions have failed.
 */

#ifndef PANTALLAS_H_
#define PANTALLAS_H_

/* INCLUDES DEL SISTEMA */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/* INCLUDES PROPIOS */


/* DEFINES Y ENUMS */
#define NUM_ROWS 8
#define NUM_COLS 8

#define INIT_OK 0
#define INIT_FAIL 1

/** enum type to define RGB colors. **/
enum RGB_COLOR {
	RED, /*!< Red */
	GREEN, /*!< Green */
	BLUE /*!< Blue */
};

/* DECLARACION DE NUEVOS TIPOS */
/**
 * @struct Led
 * @brief Struct type of a LED.
 */
/**
 * @typedef led_t
 * @brief Typedef of Led
 */
typedef struct Led {
	int8_t color; /*!< The color of the LED according to the enum `RGB_COLOR` */
	bool estado; /*!< Status of the LED: true (ON), false (OFF) */
} led_t;

/**
 * @struct Pixel
 * @brief Struct type of a pixel RGB.
 */
/**
 * @typedef pixel_t
 * @brief Typedef of Pixel
 */
typedef struct Pixel {
	led_t led_r; /*!< Red LED of the pixel */
	led_t led_g; /*!< Green LED of the pixel */
	led_t led_b; /*!< Blue LED of the pixel */
} pixel_t;

/**
 * @struct Pantalla
 * @brief Struct type of a screen.
 */
/**
 * @typedef pantalla_t
 * @brief Typedef of Pantalla
 */
typedef struct Pantalla {
    pixel_t matriz_RGB[NUM_ROWS][NUM_COLS]; /*!< Bidimentional array of RGB-pixels that represents the screen itself. */
    int32_t num_rows; /*!< Number of rows of the screen */
    int32_t num_cols; /*!< Number of columns of the screen */
    void *cajon_de_sastre; /*!< Void pointer so that the users can point to whatever they want. */
} pantalla_t;


/* PROTOTIPO DE FUNCIONES */
int32_t inicializa_pantalla(pantalla_t *p_pantalla);
pantalla_t inicializa_pantalla_2(pantalla_t pantalla);
void ilumina_pantalla(pantalla_t *p_pantalla);
int32_t inicializa_pixel(pixel_t * p_pixel);
pixel_t inicializa_pixel_2(pixel_t pixel);
void ilumina_led(led_t *led);
void apaga_led(led_t *led);

#endif