#include <stdio.h>

const int NO_ENCONTRADO = -1;

unsigned int buscar_numero(int numero_a_buscar, const int* numeros, unsigned int tamanio) {
    unsigned int indice = NO_ENCONTRADO;
    unsigned int i = 0;
    while (indice == NO_ENCONTRADO && i < tamanio) {
        if (numeros[i] == numero_a_buscar) {
            indice = i;
        }
        i += 1;
    }
    return indice;
}

int main() {
    int numeros[10] = {1, 4, -6, 29, -3, 2, 8, -12, -15, 0};
    int numero_a_buscar = 8;
    unsigned int indice = buscar_numero(numero_a_buscar, numeros, 10);

    if (indice != NO_ENCONTRADO) {
        printf("El número %d está en la posición %d.", numero_a_buscar, indice);
    } else {
        printf("El número no se encontró.");
    }

    return 0;
}