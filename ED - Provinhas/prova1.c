#include <stdio.h>
#include <stdlib.h>

float *alocacao_vetor(float *vetor, int n);
void atribuicao_valores(float *vetor, int n);
void calculo_media(float *vetor, int n, float *media);

int main (void) {

    float *vetor = NULL;
    int n;
    float media = 0;
    printf("Informe n: ");
    scanf("%d", &n);

    vetor = alocacao_vetor(vetor, n);
    atribuicao_valores(vetor, n);
    calculo_media(vetor, n, &media);

    printf("Media do vetor = :%.2f", media);

    return 0;
}

float *alocacao_vetor(float *vetor, int n) {
    vetor = (float *) malloc(n * sizeof(float));
    return vetor;
}

void atribuicao_valores(float *vetor, int n) {

    for(int i = 0; i < n; i++) {
        printf("Informe o %d valor: ", i+1);
        scanf("%f", &vetor[i]);
    }
}

void calculo_media(float *vetor, int n, float *media) {
    for(int i = 0; i < n; i++) {
        (*media) = (*media) + vetor[i];
    }
    (*media) /= n;
}