/**
 * @file arrays.h
 * @brief Header file for the explanation of arrays in C. 
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-23
 */

/**
 * @def TAM_ARRAY_A
 * @brief Macro to defines the size of an array.
 */

/**
 * @def NUM_ROWS
 * @brief Macro to defines the number of rows of a matrix of pixels.
 */

/**
 * @def NUM_COLS
 * @brief Macro to defines the number of columns of a matrix of pixels.
 */


#ifndef ARRAYS_H_
#define ARRAYS_H_

/* INCLUDES DEL SISTEMA */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/* INCLUDES PROPIOS */


/* DEFINES Y ENUMS */
#define TAM_ARRAY_A 5
#define NUM_ROWS 8
#define NUM_COLS 8

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


/* PROTOTIPO DE FUNCIONES */
void explica_arrays(void);

#endif