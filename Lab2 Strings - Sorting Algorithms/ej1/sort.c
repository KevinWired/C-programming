#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


// Importante: goes_before() ordena con criterio de valor absoluto
// Por ejemplo según el criterio de orden de goes_before el array [-2,0] se ordena como [0, -2].
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
        assert(array_is_sorted(a, i));
    }
}
