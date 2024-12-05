#include <stdio.h>
#include <stdlib.h>


typedef struct _person {
    int age;
    char name_initial;
} person_t;


int main(void) {

    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};

    // Puntero 1
    int* ptr_to_x = NULL;
    ptr_to_x = &x;
    *ptr_to_x = 9;

    // Puntero 2
    person_t* ptr_to_m = NULL;
    ptr_to_m = &m;
    (*ptr_to_m).age = 100;
    (*ptr_to_m).name_initial = 'F';
      
    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);

    return EXIT_SUCCESS;
}

