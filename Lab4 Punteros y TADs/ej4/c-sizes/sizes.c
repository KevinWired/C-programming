#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

static void line_spacing() {
	printf("\n\n");
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);
	
	size_t name_size = sizeof(name_t);
	size_t age_size = sizeof(unsigned int);
	size_t height_size = sizeof(unsigned int); 
	size_t data_t_size = sizeof(data_t); 

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", name_size, age_size, height_size, data_t_size);
	line_spacing();
	printf("Size of [char] = %lubytes.\nSize of [unsigned int] = %lubytes.\n", sizeof(char), sizeof(unsigned int));
	
	line_spacing();
	printf("ADDRESS OF EACH FIELD/DATA\n");
	printf("Address of field [name] = %p\n", &(messi.name[0]));
	printf("Address of field [age] = %p\n", (void*)&(messi.age));
	printf("Address of field [height] = %p\n", (void*)&(messi.height));
	printf("Address of struct [data_t] = %p\n", (void*)&(messi));
	
	

    return EXIT_SUCCESS;
}

/******************************************************************************

	El tipo char ocupa 1 bytes como la macro NAME_MAXSIZE tiene una valor de
	30 entonces 30x1 = 30.

	El tipo unsigned int ocupa 4 bytes, y como en data_t age y height son de
	este tipo, entonces ya son 4x2 = 8 bytes ocupados.

	En total 30 + 8 son 38 bytes. Sin embargo se muestran 40 bytes como tamaño
	de la estructura data_t. Resulta que en muchas arquitecturas, los enteros
	(unsigned int) deben estar alineados en direcciones de memoria que sean
	múltiplos de 4 bytes. Para lograr esto, después del campo name de 30 bytes,
	se añaden 2 bytes de relleno para que el campo age comience en una dirección
	alineada a 4 bytes.

*******************************************************************************/
