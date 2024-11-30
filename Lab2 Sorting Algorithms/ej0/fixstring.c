#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

// Retorna la longitud de la cadena.
unsigned int fstring_length(fixstring s) {
	unsigned int length=0;
	if(s[length] == NULL_CHARACTER) {
		return 0;
	} else {
		while(s[length] != NULL_CHARACTER && length < FIXSTRING_MAX-1) {
			length = length+1;
		}
	}
	return length;
}

// Indica si las cadenas s1 y s2 son iguales.
bool fstring_eq(fixstring s1, fixstring s2) {
    unsigned int s1_len = fstring_length(s1);
    unsigned int s2_len = fstring_length(s2);
    bool eq = true;
    if(s1_len == s2_len) {
        unsigned int index = 0;
        while (eq && s1[index] != NULL_CHARACTER && s2[index] != NULL_CHARACTER && index < FIXSTRING_MAX-1) {
            eq = s1[index] == s2[index];
            index++;
        }
        
    } else {
        return false;
    }
    return eq;
}

static bool fstring_subchain(fixstring s1, fixstring s2) {
    if (fstring_length(s2) < fstring_length(s1)) { // Si s1 es de mayor longitud que s2. Entonces s1 no puede ser subcadena de s2.
        return false;
    } else {
        unsigned int index = 0;
        bool subchain = true;
        while (s1[index] != NULL_CHARACTER && subchain && index) {  // Se verifica que s1 sea efectivamente subcadena de s2.
            subchain = s1[index] == s2[index];
            index++;
        }
        assert(index < FIXSTRING_MAX-1);
        return subchain;
    }
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    // Caso trivial: Las cadenas s1 y s2 son iguales.
    if (fstring_eq(s1, s2)) {
        return true;
    }
    // Caso subcadena: Si s1 es subcadena de s2, entonces s1 en orden alfabetico va primero que s2.
    if(fstring_subchain(s1, s2)) {
        return true;
    }
    // Caso general: Se compara char por char, si son distintos se comparan para determinar el valor alfabetico de s1.
    unsigned int index = 0;
    while (s1[index] == s2[index] && s1[index] != NULL_CHARACTER && s2[index] != NULL_CHARACTER) {
        index++;
    }
    assert(index < FIXSTRING_MAX-1);
    return s1[index] < s2[index];
}
