#include <stdio.h>
#include <string.h>

/*
 * Escribir un programa que 'multiplique' una palabra
 * de la forma hola * 2 == holahola
 * Esto lo podemos hacer ahora (sin memoria dinámica) pero la solución es una porquería.
 */

void multiplicar_palabra(char* palabra, unsigned int veces) {
    // Concretamente, esto es una porquería.
    char resultado[999] = "";
    for (unsigned int i = 0; i < veces; i++) {
        strcat(resultado, palabra);
    }
    printf("%s", resultado);
}

int main() {
    multiplicar_palabra("HOLA", 10);
    return 0;
}