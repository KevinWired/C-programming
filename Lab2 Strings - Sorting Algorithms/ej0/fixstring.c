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

bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int index = 0;
    while (s1[index] == s2[index] && s1[index] != NULL_CHARACTER && s2[index] != NULL_CHARACTER) {
        index++;
    }
    assert(index < FIXSTRING_MAX-1);
    return s1[index] < s2[index];
}
