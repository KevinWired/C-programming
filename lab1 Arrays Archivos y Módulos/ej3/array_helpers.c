#include <assert.h>
#include <stdio.h> 
#include <stdlib.h>

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
    if (filepath == NULL) {
        printf("Error: filepath is NULL\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Error: File must exist\n");
        exit(EXIT_FAILURE);
    }

    unsigned int len;
    int fscanf_res = fscanf(file, "%u", &len);

    if (fscanf_res != 1) {
        printf("Error: Invalid array size\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    if (len > max_size) {
        printf("Error: maximum size allowed %u\n", max_size);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Empty array case.
    if (len == 0) { 
        fclose(file);
        return 0;
    }

    for (unsigned int i = 0; i < len; i++) {
        fscanf_res = fscanf(file, "%d", &array[i]);
        if (fscanf_res != 1) {
            printf("Error: Invalid array element at index %u\n", i);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return len;
}


void array_dump(int a[], unsigned int length) {

    if (length == 0) {
        printf("[ Empty array]\n");
    }else {
        printf("[ ");
        for (unsigned int i=0; i<length; i++) {
            if(i % length == length-1) {
                printf("%d]", a[i]);
            }else {
                printf("%d,", a[i]);
            }
        }
    }
    printf("\n");
}
