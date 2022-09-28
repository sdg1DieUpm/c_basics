/**
 * @file pantallas.c
 * @brief Library-like code including functions to work with screens of RGB-pixels.
 *
 * It includes an example of two functions that perform the same action; the formers receive arguments by reference, the latests receive the arguments by value..
 *
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-23
 *    
 */

/* INCLUDES PROPIOS */
#include "pantallas.h"

/**
 * @brief Turn the status (`estado`) of a LED ON (true).
 * 
 * @param p_led Memory address of a LED.
 */
void ilumina_led(led_t *p_led){
    p_led->estado = true;
}

/**
 * @brief Turn the status (`estado`) of a LED OFF (false).
 * 
 * @param p_led Memory address of a LED.
 */
void apaga_led(led_t *p_led){
    p_led->estado = false;
}

/**
 * @brief Assign RGB colors to pixels and turn LEDs OFF.
 * 
 * @param p_pixel Memory address of a pixel.
 * @return int32_t Status of the initialization; tipically `INIT_OK`.
 */
int32_t inicializa_pixel(pixel_t * p_pixel){
    p_pixel->led_r.color = RED; 
    p_pixel->led_r.estado = false;

    p_pixel->led_g.color = GREEN; 
    p_pixel->led_g.estado = false;

    p_pixel->led_b.color = BLUE; 
    p_pixel->led_b.estado = false;

    return(INIT_OK);
}

/**
 * @brief Assign RGB colors to pixels and turn LEDs OFF.
 * 
 * This is another version of the function `inicializa_pixel` receiving the argument by value.
 * Another version could do the same with void input arguments. e.g.: `pixel_t inicializa_pixel_3(void);`
 * 
 * @param pixel The value of a pixel.
 * @return pixel_t The pixel received, modified.
 */
pixel_t inicializa_pixel_2(pixel_t pixel){
    pixel.led_r.color = RED; 
    pixel.led_r.estado = false;

    pixel.led_g.color = GREEN; 
    pixel.led_g.estado = false;

    pixel.led_b.color = BLUE; 
    pixel.led_b.estado = false;

    return(pixel);
}

/**
 * @brief Turn the pixels of a screen ON.
 * 
 * @param p_pantalla Memory address of a screen.
 */
void ilumina_pantalla(pantalla_t *p_pantalla){
    int32_t num_filas = p_pantalla->num_rows;
    int32_t num_columnas = p_pantalla->num_cols;

    for (int32_t i=0; i<num_filas; i++){
        for (int32_t j=0; j<num_columnas; j++){
            ilumina_led(&(p_pantalla->matriz_RGB[i][j].led_r));
            ilumina_led(&(p_pantalla->matriz_RGB[i][j].led_g));
            ilumina_led(&(p_pantalla->matriz_RGB[i][j].led_b));
            printf("(%d,%d,%d) ", p_pantalla->matriz_RGB[i][j].led_r.estado, p_pantalla->matriz_RGB[i][j].led_g.estado, p_pantalla->matriz_RGB[i][j].led_b.estado);
        }
        printf("\n");
    }
  
}

/**
 * @brief Init the pixels of a screen.
 * 
 * @param p_pantalla Memory address of a screen.
 * @return int32_t Status of the initialization; tipically `INIT_OK`.
 */
int32_t inicializa_pantalla(pantalla_t *p_pantalla){
    int32_t num_filas = p_pantalla->num_rows;
    int32_t num_columnas = p_pantalla->num_cols;

    for (int32_t i=0; i<num_filas; i++){
        for (int32_t j=0; j<num_columnas; j++){
            inicializa_pixel(&(p_pantalla->matriz_RGB[i][j])); // No recojo el valor devuelto...
        }
    }

    return(INIT_OK);
}

/**
 * @brief Init the pixels of a screen.
 * 
 * This is another version of the function `inicializa_pantalla` receiving the argument by value.
 * Another version could do the same with void input arguments. e.g.: `pixel_t inicializa_pantalla_3(void);` 
 * 
 * @param pantalla The values of a screen.
 * @return pantalla_t The screen received, modified.  
 */
pantalla_t inicializa_pantalla_2(pantalla_t pantalla){
    int32_t num_filas = pantalla.num_rows;
    int32_t num_columnas = pantalla.num_cols;

    for (int32_t i=0; i<num_filas; i++){
        for (int32_t j=0; j<num_columnas; j++){
            pixel_t un_pixel = inicializa_pixel_2(pantalla.matriz_RGB[i][j]); // No recojo el valor devuelto...
            pantalla.matriz_RGB[i][j] = un_pixel;
        }
    }

    return pantalla;
}