#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i) {
    unsigned int index = i;
    while (0 < index && goes_before(a[index], a[index-1])) {
        swap(a, index, index-1);
        index--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
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

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    if (izq < der) {
    unsigned int ppiv = partition(a, izq, der);
    quick_sort_rec(a, izq, (ppiv == 0u ? 0u : ppiv - 1));
    quick_sort_rec(a, ppiv + 1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}