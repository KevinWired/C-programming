#include <stdlib.h>
#include <stdio.h>
#include "pair.h"

// Encapsulamiento: Se define la estructura (s_pair_t) en el archivo de implementación (.c)
// Solo se expone un puntero a la estructura en el archivo de cabecera (.h).

struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(int x, int y) {
    pair_t p = (void*)malloc(sizeof(struct s_pair_t));
    if (p == NULL) {
        fprintf(stderr, "Not enough memory\n");
        exit(EXIT_FAILURE);
    }
    p->fst = x;
    p->snd = y;
    return p;
}

int pair_first(pair_t p) {
    return p->fst;
}

int pair_second(pair_t p) {
    return p->snd;
}

pair_t pair_swapped(pair_t p) {
    if (p == NULL) {
        fprintf(stderr, "Error: NULL pointer passed to pair_swapped\n");
        exit(EXIT_FAILURE);
    }
    return pair_new(p->snd, p->fst);
}

pair_t pair_destroy(pair_t p) {
    if (p != NULL) {
        free(p);
    }
    return NULL; // Retornar NULL para indicar que el par fue destruido.
}

