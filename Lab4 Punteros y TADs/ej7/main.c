/* First, the standard lib includes, alphabetically ordered */
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "list.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Compute average for the list of numbers in file.\n"
           "\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}


float average(list l) {
    unsigned int n = length(l);
    float avg = 0;

    if (empty_list(l)) {
        return 0;
    }

    list aux = copy_list(l); // Creating a new list involves freeing dynamic memory.
    list temp;

    while (!empty_list(aux)) {
        avg += (float) head(aux);
        temp = aux;
        aux = tail(aux);
        free(temp); // Delete temp list.
    }
    avg /= n;

    destroy_list(aux); // Ensure aux is properly freed.

    return avg;
}


list array_to_list(int array[], unsigned int length) {
	list l = create_list();	// Creating a new list involves freeing dynamic memory.
    for (unsigned int i = 0u; i < length; ++i) {
        l = append(l, *(array + i));
    }
	return (l);
}


int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];

    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

    /* show the array in the screen */
    array_dump(array, length);

    /* transform from array to our list type */
    list l = array_to_list(array, length);

    /* call the average function */
    printf("The average is: %.2f \n", average(l));
	
	destroy_list(l); // Free memory for C.

    return (EXIT_SUCCESS);
}
