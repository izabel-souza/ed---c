// Qual afirmativa é falsa? 
 
// a. *pti é igual a 10 

// b. *(pti+2) é igual a 2 

// c. pti[4] é igual a 3

// d. pti[1] é igual a 10 

// e. *(veti+3) é igual a 6
#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int *pti;
    int veti[] = {10,7,2,6,3};
    pti = veti;

    printf("*pti = %d\n*(pti+2) = %d\npti[4] = %d\npti[1] = %d\n*(veti+3) = %d", *pti, *(pti+2), pti[4], pti[1], *(veti+3));

    printf("\nLetra D e falsa");

    return 0;
}