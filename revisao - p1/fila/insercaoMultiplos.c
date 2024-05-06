// Sejam três filas Fila2, Fila5 e Fila7, armazenar respectivamenete, números inteiros divisíveis por 2, 5 e 7. Escreva um procedimento enfila, que percorre um vetor, e enfila o valor
// na Fila correta

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct lista {
    int valor;
    struct lista *proximo;
} TLista;

typedef struct fila {
    TLista *inicio;
    TLista *fim;
} TFila;

TFila *criacao(void) {
    TFila *novo = malloc(sizeof(TFila));
    novo->inicio = NULL;
    novo->fim = NULL;

    return novo;
}

void atribuicao_valores_vetor(int *vetor) {
    for(int i = 0; i < 15; i++) {
        int x = rand() % 100;
        vetor[i] = x;
    }
}

int fila_vazia(TFila *f) {
    if(f->inicio == NULL) return 1;
    else return 0;
}

void enfila(TFila *f2, TFila *f5, TFila *f7, int *vetor) {
    for(int i = 0; i < 15; i++) {

        TLista *novo = malloc(sizeof(TLista));
        novo->proximo = NULL;
        
        if(vetor[i] % 2 == 0) {
            novo->valor = vetor[i];

            if(!fila_vazia(f2)) {
                f2->fim->proximo = novo;
            }
            else f2->inicio = novo;

            f2->fim = novo;
        }

        else if(vetor[i] % 5 == 0) {
            novo->valor = vetor[i];

            if(!fila_vazia(f5)) {
                f5->fim->proximo = novo;
            }
            else f5->inicio = novo;

            f5->fim = novo;
        }

        else if(vetor[i] % 7 == 0) {
            novo->valor = vetor[i];

            if(!fila_vazia(f7)) {
                f7->fim->proximo = novo;
            }
            else f7->inicio = novo;

            f7->fim = novo;
        }

        else printf("\nValor indivisivel por 2, 5 ou 7\n");
    }
}

void imprime(TFila *f) {
    for(TLista *i = f->inicio; i != NULL; i = i->proximo) {
        printf("%d\n", i->valor);
    }
    printf("\n");
}

int main (void) {

    srand(time(NULL));

    TFila *fila2 = NULL, *fila5 = NULL, *fila7 = NULL;
    fila2 = criacao();
    fila5 = criacao();
    fila7 = criacao();

    int vetor[15];
    atribuicao_valores_vetor(vetor);

    enfila(fila2, fila5, fila7, vetor);

    printf("\nFILA COM VALORES DIVISIVEIS POR 2:\n");
    imprime(fila2);
    printf("\nFILA COM VALORES DIVISIVEIS POR 5:\n");
    imprime(fila5);
    printf("\nFILA COM VALORES DIVISIVEIS POR 7:\n");
    imprime(fila7);

    return 0;
}