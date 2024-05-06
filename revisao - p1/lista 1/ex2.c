// Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número n e retorne a representação binária de n. Por exemplo, se n é igual a 12, a resposta deste programa deve ser “1100”. Seu programa para quando n for menor que zero.

#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int n;

    while(1) {
        printf("\nInforme n: ");
        scanf("%d", &n);

        if(n < 0) break;
        printf("%d(10) = ", n);
        int valorBin[32];

        int i = 0;
        while(n > 0) {
            valorBin[i] = (n % 2);
            n = n/2;
            i++;
        }

        for(int j = i-1; j >= 0; j--) {
            printf("%d", valorBin[j]);
        }

    }

    return 0;
}