#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
	unsigned int ppiv = izq;
	unsigned int index_i = izq + 1;
	unsigned int index_j = der;
	while (index_i <= index_j) {
		if (goes_before(a[index_i], a[ppiv])) {
			index_i++;
		} else if (goes_before(a[ppiv], a[index_j])) {
			index_j--;
		} else {
			swap(a, index_i, index_j);
			index_i++;
			index_j--;
		}
	}
	swap(a, ppiv, index_j);
	ppiv = index_j;
	return (ppiv);
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    if (izq < der) {
        unsigned int ppiv = partition(a, izq, der);
        quick_sort_rec(a, izq, (ppiv == 0u ? 0u : ppiv - 1));
        quick_sort_rec(a, ppiv + 1, der);
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


