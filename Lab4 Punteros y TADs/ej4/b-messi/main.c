#include <stdio.h>
#include <stdlib.h>

#include "data.h"

#define NULL_CHAR '\0' 

typedef unsigned int uint;

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

void set_name(name_t new_name, data_t *d) {
	uint index = 0;
	while (new_name[index] != NULL_CHAR) {
		d->name[index] = *(new_name + index);
		index++;
	}
	d->name[index] = NULL_CHAR;
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);
    name_t messi_full_name = "Lionel Messi";
	set_name(messi_full_name, &messi);
    print_data(messi);

    return EXIT_SUCCESS;
}

