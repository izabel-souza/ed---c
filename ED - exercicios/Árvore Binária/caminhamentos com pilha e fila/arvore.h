#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq, *dir;
} TNo;

TNo *criaNo(int i) {
    TNo *novo = (*TNo) malloc(sizeof(TNo));
    novo->valor = i;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

void imprime(TNo *arvore, int tab) {
    for(int i = 0; i < tab; i++) {
        printf("-");
    }
    if(arvore != NULL) {
        printf("%d\n", arvore->valor);
        imprime(arvore->esq, tab+2);
        printf("\n");
        imprime(arvore->dir, tab + 2);
    }
}