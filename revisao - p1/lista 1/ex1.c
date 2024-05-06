//  Escreva um programa que, infinitamente, leia um número inteiro n, que representa o tamanho, seguida de uma sequência de n números inteiros, e determine o comprimento máximo de um segmento crescente destes n números. Exemplos: Na sequência 5, 10, 3, 2, 4, 7, 9, 8, 5 o comprimento do segmento crescente máximo é 4. Na sequência 10, 8, 7, 5, 2 o comprimento de um segmento crescente máximo é 1. Seu programa para quando n for menor ou igual a zero.

#include <stdio.h>
#include <stdlib.h>

// int *inicializaVetor(int n) {
//     int *vetor = malloc(n * sizeof(int));
//     return vetor;
// }

// void atribuicao(int *vetor, int n) {
//     for(int i = 0; i < n; i++) {
//         printf("Informe o valor %d do vetor: ", i+1);
//         scanf("%d", &vetor[i]);
//     }
// }

// void imprime(int *vetor, int n) {
//     for(int i = 0; i < n; i++) {
//         printf("%d ", vetor[i]);
//     }
//     printf("\n");
// }

// int segmentoMax(int *vetor, int n) {
//     int seg = 0;
//     for(int i = 0; i < n; i++) {
//         if(vetor[i] < vetor[i+1]) seg++;
//     }
//     return seg;
// }

int main (void) {

    int n;
    
    while (1) {
        printf("Digite n: ");
        scanf("%d", &n);
        
        if (n <= 0)
            break;
        
        int num, prevNum, maxLen = 1, currLen = 1;
        
        printf("Digite a sequencia de numeros:\n");
        scanf("%d", &prevNum);
        
        for (int i = 1; i < n; i++) {
            scanf("%d", &num);
            
            if (num > prevNum) {
                currLen++;
                if (currLen > maxLen)
                    maxLen = currLen;
            } else {
                currLen = 1;
            }
            
            prevNum = num;
        }
        printf("O comprimento do segmento crescente maximo é: %d\n\n", maxLen);
    }
    printf("Programa encerrado.\n");


    return 0;
}
