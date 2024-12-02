#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    if (izq < der) {
        unsigned int ppiv = partition(a, izq, der); // Divide el arreglo.
        quick_sort_rec(a, izq, (ppiv == 0u ? 0u : ppiv - 1)); // Llamada recursiva para ordenar el subarreglo a la izquierda del pivote, (excluyendo el pivote).
        quick_sort_rec(a, ppiv + 1, der); // Llamada recursiva para ordenar el subarreglo a la derecha del pivote, (excluyendo el pivote).
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

