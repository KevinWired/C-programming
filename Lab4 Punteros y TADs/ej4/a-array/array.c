#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ARRAY_SIZE 7

static void
print_array(int a[], size_t length) {
    assert(length > 0);
    printf("[ %d", a[0]);
    for (size_t i=1; i<length; i++) {
        printf(", %d", a[i]);
    }
    printf("]\n");
}

static void
line_spacing(){
	printf("\n\n");
}


int main(void) {
    // El arreglo (arr) es estático está definido en el stack.
    int arr[ARRAY_SIZE] = {7, 4, 1, 3, 9, 3, 5};
    int* p = NULL;
    printf("Before: ");
    print_array(arr, ARRAY_SIZE);

	line_spacing();
	p = arr;
    p = calloc(ARRAY_SIZE, sizeof(int));
	if (p == NULL) {
	    printf("Error allocating memory.\n");
	    return EXIT_FAILURE;
	}

    for (unsigned int i=0u; i < ARRAY_SIZE; i++) {
        arr[i] = p[i];
    }

    printf("After : ");
    print_array(arr, ARRAY_SIZE);
    free(p); // Liberamos el bloque de memoria que se reservo.

    return EXIT_SUCCESS;
}

