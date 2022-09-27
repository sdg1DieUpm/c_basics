#include "pantallas.h"

void ilumina_led(led_t *led){
    led->estado = true;
}

void apaga_led(led_t *led){
    led->estado = false;
}

// Inicializa apagado
int32_t inicializa_pixel(pixel_t * p_pixel){
    p_pixel->led_r.color = RED; 
    p_pixel->led_r.estado = false;

    p_pixel->led_g.color = GREEN; 
    p_pixel->led_g.estado = false;

    p_pixel->led_b.color = BLUE; 
    p_pixel->led_b.estado = false;

    return(INIT_OK);
}

pixel_t inicializa_pixel_2(pixel_t pixel){
    pixel.led_r.color = RED; 
    pixel.led_r.estado = false;

    pixel.led_g.color = GREEN; 
    pixel.led_g.estado = false;

    pixel.led_b.color = BLUE; 
    pixel.led_b.estado = false;

    return(pixel);
}

void ilumina_pantalla(pantalla_t *p_pantalla){
    int32_t num_filas = p_pantalla->num_rows;
    int32_t num_columnas = p_pantalla->num_cols;

    for (int32_t i=0; i<num_filas; i++){
        for (int32_t j=0; j<num_columnas; j++){
            ilumina_led(&(p_pantalla->matriz_RGB[i][j].led_r));
            ilumina_led(&(p_pantalla->matriz_RGB[i][j].led_g));
            ilumina_led(&(p_pantalla->matriz_RGB[i][j].led_b));
        }
    }
  
}


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