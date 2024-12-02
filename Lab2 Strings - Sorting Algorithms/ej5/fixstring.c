#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


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

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!= NULL_CHARACTER) {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = NULL_CHARACTER;
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux, s1);
    fstring_set(s1, s2);
    fstring_set(s2, aux);
}


