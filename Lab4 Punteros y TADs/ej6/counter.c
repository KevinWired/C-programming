#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
	counter c = NULL;
	c = (void*)calloc(1, sizeof(struct _counter));
	if (c == NULL) {
		fprintf(stderr, "Not enough memory\n");
		exit(EXIT_FAILURE);
	}
	c->count = 0;
	assert(counter_is_init(c) && c != NULL);
	return c;
}

void counter_inc(counter c) {
	assert(c != NULL);
	c->count++;
}

bool counter_is_init(counter c) {
	return c->count == 0;
}

void counter_dec(counter c) {
	assert(c != NULL);
	c->count--;
}

counter counter_copy(counter c) {
	assert(c != NULL);
	counter cpy = counter_init();
	cpy->count = c->count;
	return cpy;
}

void counter_destroy(counter c) {
	if (c!=NULL) {
	free(c);  // Liberamos el bloque de memoria apuntado por c.
	c = NULL; // Seteamos c a NULL.
	}
}
