#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int x, y, *p;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;
    printf("x: %d, y: %d, p: %d", x, y, *p);

    return 0;
}
