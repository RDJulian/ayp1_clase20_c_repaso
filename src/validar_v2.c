#include <stdbool.h>
#include <string.h>
#include <stdio.h>

const char* CARACTERES_LEGALES = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZabcdefghijklmnñopqrstuvwxyz1234567890*-$@";
const char* MAYUSCULAS = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
const char* MINUSCULAS = "abcdefghijklmnñopqrstuvwxyz";
const char* NUMEROS = "1234567890";
const char* CARACTERES_ESPECIALES = "*-$@";
const unsigned long LONGITUD_MAXIMA = 12;
const unsigned long LONGITUD_MINIMA = 8;

// Se pueden hacer más funciones como esta para modularizar.
bool es_mayuscula(char caracter) {
    return strchr(MAYUSCULAS, caracter);
}

bool validar(char* clave) {
    bool es_valido = true;
    bool tiene_mayuscula = false;
    bool tiene_minuscula = false;
    bool tiene_numero = false;
    bool tiene_caracter_especial = false;
    unsigned int i = 0;
    if (strlen(clave) < LONGITUD_MINIMA || strlen(clave) > LONGITUD_MAXIMA) {
        es_valido = false;
    }
    while (es_valido && i < strlen(clave)) {
        if (!strchr(CARACTERES_LEGALES, clave[i])) {
            es_valido = false;
        } else {
            if (es_mayuscula(clave[i])) {
                tiene_mayuscula = true;
            }
            if (strchr(MINUSCULAS, clave[i])) {
                tiene_minuscula = true;
            }
            if (strchr(NUMEROS, clave[i])) {
                tiene_numero = true;
            }
            if (strchr(CARACTERES_ESPECIALES, clave[i])) {
                tiene_caracter_especial = true;
            }
        }
        i += 1;
    }
    return es_valido && tiene_mayuscula && tiene_minuscula && tiene_numero && tiene_caracter_especial;
}

int main() {
    printf("%d", validar("Al.r1tm@s"));
    return 0;
}