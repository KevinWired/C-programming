#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    if(x >= 0) {
        *y = x;
    } 
    else {
        *y = (x * -1);
    }
}

int main(void) {
    int a=-5, res=0;
    absolute(a, &res);
    assert(res >= 0 && (res == a || res == -a));
    printf("Result = %d\n", res);
    return EXIT_SUCCESS;
}

