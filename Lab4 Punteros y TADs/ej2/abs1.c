/******************************************************************************

    El código no funciona dado que absolute() recibe y como argumento,
    y este es pasado por valor. Entonces cualquier cambio dentro de la función
    no afecta la variable original (res) en el programa pricipal.

    La solución es usar punteros. En abs2.c se ataca a este problema.

*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (0 <= x) {
        y = x;
    }
    else {
        y = x * -1;
    }
}

int main(void) {
    int a=-22, res=0;
    absolute(a, res);
    printf("Result = %d\n", res);
    return EXIT_SUCCESS;
}
