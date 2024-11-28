/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h> // stdin, stdout, stderr - standard I/O streams.
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

unsigned int array_from_stdin(int array[], unsigned int max_size) {

    FILE *file;
    file = stdin;
    assert(file != NULL);

    unsigned int len;
    printf("Enter array size: \n");
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
    
    printf("Enter the array elements (one at time):\n");

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


int main(void) {
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    unsigned int length = array_from_stdin(array, MAX_SIZE);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
