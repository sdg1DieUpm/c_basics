/**
 * @file precedencia.c
 * @brief Explanation of the rules of precedence.
 *
 * Explanation of the rules of precedence and operators in C, with examples.
 *
 * @author Josué Pagán <j.pagan@upm.es>
 * @date 2022-09-11
 * 
 */

#include "precedencia.h"

/**
 * @brief Function to explain the use of the rules of precedence and operators in C.
 * 
 */
void explica_precedencia(){
    uint32_t x = 1;
    const uint32_t limite_x = 256;    

    printf("\nExiste un orden de precedencia en los operadores de C. Algunos operadores pueden tener el mismo nivel de precedencia. Por ejemplo, * ,/, y %% tienen todos la misma precedencia, la cual es más alta que la de + y - binarios\n");
    printf("Ademas, existen reglas de asociatividad (de izquierda a derecha, o viceversa) para cada operador.\n");
    
    printf("\n/*Operadores de interes*/\n");
    printf("/*Desplazamiento de bits*/\n");
    
    printf("La variable x vale, x=%d\n", x);

    printf("Los desplazamientos a la izquierda (<<) y la derecha (>>) consisten en mover los bits de la variable tantas posiciones como se indiquen en el sentido del operador. Desplazar 1 posicion a la izquierda es multiplicar x2, a la derecha, es dividir /2.\n\n");    
    for (int32_t i=0; i<8; i++){
        x <<= 1;
        printf("\tEl valor de x desplazado a la izquierda %d posiciones es x=%d (0x%x)\n", i, x ,x);
    }

    for (int32_t i=0; i<8; i++){
        x >>= 1;
        printf("\tSi desplazamos el valor anterior a la derecha %d posiciones queda x=%d (0x%x)\n", i, x, x);
    }
    
    printf("\n/*Comparacion: desigualdad*/\n");
    printf("Los comparadores de desigualdad sirven para comparar si una variable es \"mayor que\" o \"menor que\" (incluyendo, o no la igualdad), otro valor (constante, o variable).\n\n"); 
    
    printf("\tLa variable x vale, x=%d\n", x);
    for (int32_t i=0; i<16; i++){
        x <<= 1; // Desplazamos a la izquierda            
        
        if (x < limite_x){
            printf("\tLa variable x vale, x=%d\n", x);
        } 
        else if (x >= limite_x){
            printf("\tLa variable x ha alcanzado el limite %d en la iteracion %d. Salimos del \"for\" con un \"break\"\n", limite_x, i);
            break;
        } else {
            printf("\tYou shouldn't be here ;()!!!\nx debe ser \"menor que\" o \"mayor o igual que\" %d\n", limite_x);
        }
    }

    printf("\n/*Comparacion: igualdad*/\n");
    printf("Los comparadores de igualdad sirven para comparar si una variable es \"igual a\" (\"==\") o \"distinta a\" (\"!=\") otro valor (constante, o variable).\n\n");
    if (x != limite_x){
        printf("\tAlgo ha fallado, x deberia valer %d, y vale %d\n", limite_x, x);
    } 
    else if (x == limite_x){
        printf("\tLa variable x is igual que el limite %d puesto\n", limite_x);          
    } else {
        printf("\tYou shouldn't be here ;()!!!\nx debe ser \"distinta a\" o \"igual a\" %d\n", limite_x);
    }
    

    printf("\n/*Operadores binarios*/\n");
    printf("Los operadores binarios se aplican \"bit a bit\", a los bits de una variable, no tiene por que ser booleana.\n");
    printf("Concepto muy util para usar con MASCARAS, por ejemplo, al leer registros.\n");

    printf("\nProducto binario (AND, & --> SHIFT+6), para comprobar si estan activos 1 (o varios) bits de una variable, segun una mascara:\n");    
    for (int32_t i=0; i<8; i++){
        x >>= 1;

        if (x & MASCARA_BINARIA){ // Si el producto es distinto de 0...
            printf("\tEl producto bit a bit de x con la MASCARA_BINARIA es distinto de 0, y vale %d (0x%x)\n", x &MASCARA_BINARIA, x & MASCARA_BINARIA);
        }        
    }

    printf("\nSuma binaria (OR, |), para activar (poner a 1) 1 o varios bits de una variable, segun una mascara:\n");
    x |= (MASCARA_BINARIA<<1); // OR y asignacion sobre X
    printf("\tDesplazo la mascara y se la sumo a x, que ahora vale: x |= (MASCARA_BINARIA<<1) => x=%d (0x%x)\n", x, x);
    
    printf("\nProducto con la inversa de una mascara (AND ~, & ~ --> ALTGR+4), para limpiar (poner a 0) los bits de una variable que me indique una mascara (u otra variable):\n");
    printf("El operador negacion \"~\" invierte los bits de una variable.\n");

    x = 0x0F; // 0x0F = 0b 0000 1111
    uint32_t y = 0x06; // 0x06 = 0b 0000 0110
    
    // Producto con la inversa de una mascara: suele escribirse x &= ~y 
    // 00001111 & ~(00000110) = 00001111 & 11111001 = 00001001
    printf("\tPongo a 0 los bits de x que esten activos en y--> x=%d (0x%x), y=%d (0x%x)--> x= x&(~y)= 0x%x\n", x, x, y, y, x&~y); 
    x = x & (~y); // Actualizo el valor de x

    printf("\nProducto binario exclusivo (XOR, ^).\nOJO! NO VALE USAR XOR PARA LIMPIAR BITS, PORQUE XOR SUMA 1 DONDE NO HAY COINCIDENCIA. XOR NO ES SUSTITUTO DE \"&~\".\n");    
    x = 0x0F; // 0x0F = 0b 0000 1111
    y = 0x16; // 0x16 = 0b 0001 0110

    printf("\tx=0x%x, y=0x%x--> x^=y = 0x%x\n", x, y, x^y);
    x ^= y; // Actualizo el valor de x

    printf("\n/*Operadores condicionales*/\n");
    printf("\tNo hay que confundir los operadores binarios con los operadores condicionales. Conviene agrupar condicionantes entre paréntesis para evitar errores y mejorar la legibilidad.\n");
    printf("\tEl \"AND\" condicional se escribe \"&&\" (Si condicion A Y tambien condicion B).\n");
    printf("\tEl \"OR\" condicional se escribe \"||\" (Si condicion A O condicion B).\n");    
    printf("\tEl operador negacion logica \"!\" invierte el valor de una condicion (true a false, y viceversa).\n");
    printf("\tNo hay que confundir \"negacion logica\" (\"!\") con \"inverso de\" (\"~\").\n");    

    if ((x > MASCARA_BINARIA) && (y > MASCARA_BINARIA)){
        printf("\t\"x\" es mayor que MASCARA_BINARIA, y también \"y\" es mayor que MASCARA_BINARIA.\n");
    }
    else if ((x > MASCARA_BINARIA) | (y > MASCARA_BINARIA)){
        printf("\t\"x\", \"y\", o ambos valores es mayor que MASCARA_BINARIA.\n");
    } 
    else if ((x > MASCARA_BINARIA) && !(y > MASCARA_BINARIA)){
        printf("\t\"x\" es mayor que MASCARA_BINARIA, e \"y\" NO es mayor que MASCARA_BINARIA.\n");
    }
    else {
        printf("\t You shouldn't be here!!!\n");
    }
}
