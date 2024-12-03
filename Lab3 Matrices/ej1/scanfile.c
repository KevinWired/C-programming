#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "scanfile.h"


char *parse_filepath(int argc, char *argv[]) {
    if (argc!=2) {
        printf("Error: cantidad de argumentos invalida.\n");
        exit(EXIT_FAILURE);
    }
    return (argv[1]);
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size) {
    unsigned int size = 0;
    FILE *file;
    file = fopen(path, "r");
    if (file == NULL) {
        printf("Error: File cannot be read.\n");
        exit(EXIT_FAILURE);
    }
    while (!feof(file)) {
        fscanf(file, FORMAT, &indexes[size], &letters[size]); //format := "%u -> *%c*\n"
        if (size >= max_size) {
            printf("Error: Overflow size:%u\n", size);
            exit(EXIT_FAILURE);
        }
        if (indexes[size] >= max_size) {
            printf("Error: Letter cannot be stored: %u.\n", indexes[size]);
            exit(EXIT_FAILURE);
        }
        size++;
    }
    fclose(file);
    return size;
}


void phrase_builder(char l[], char s[], unsigned int indexes[], unsigned int length) {
    if(MAX_SIZE <= length) {
        printf("Error: length %d", length);
        exit(EXIT_FAILURE);
    }
    for (unsigned int i = 0; i<length; i++) {
        s[indexes[i]] = l[i];
    }
}
