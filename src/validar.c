#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const char* CARACTERES_LEGALES = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZabcdefghijklmnñopqrstuvwxyz1234567890*-$@";
const char* MAYUSCULAS = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
const char* MINUSCULAS = "abcdefghijklmnñopqrstuvwxyz";
const char* NUMEROS = "1234567890";
const char* CARACTERES_ESPECIALES = "*-$@";
const unsigned long LONGITUD_MAXIMA = 12;
const unsigned long LONGITUD_MINIMA = 8;

bool tiene_mayuscula(char* cadena) {
    return strpbrk(cadena, MAYUSCULAS);
}

bool tiene_minuscula(char* cadena) {
    return strpbrk(cadena, MINUSCULAS);
}

bool tiene_longitud_valida(char* cadena) {
    unsigned long longitud = strlen(cadena);
    return longitud <= LONGITUD_MAXIMA && longitud >= LONGITUD_MINIMA;
}

bool tiene_numero(char* cadena) {
    return strpbrk(cadena, NUMEROS);
}

bool tiene_caracter_especial(char* cadena) {
    return strpbrk(cadena, CARACTERES_ESPECIALES);
}

bool tiene_caracter_ilegal(char* cadena) {
    bool tiene_caracter_ilegal = 0;
    unsigned long i = 0;
    while (i < strlen(cadena) && !tiene_caracter_ilegal) {
        if (!strchr(CARACTERES_LEGALES, cadena[i])) {
            tiene_caracter_ilegal = 1;
        }
        i += 1;
    }
    return tiene_caracter_ilegal;
}

bool validar(char* cadena) {
    return tiene_longitud_valida(cadena) &&
           tiene_mayuscula(cadena) &&
           tiene_minuscula(cadena) &&
           tiene_numero(cadena) &&
           tiene_caracter_especial(cadena) &&
           !tiene_caracter_ilegal(cadena);
}


int main() {
    char* cadena = "Hol4@todos";
    printf("%d", validar(cadena));
    return 0;
}