#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char valor;
    struct no *esq, *dir;
} TNo;

void imprime(TNo *no, int tab) {

    printf("\n");

    for(int i = 0; i < tab; i++) {
        printf("-");
    }

    if(no != NULL) {
        printf("%c\n", no->valor);
        imprime(no->esq, tab + 2);
        printf("\n");
        imprime(no->dir, tab + 2);
    }
    else printf("No vazio");
}

TNo *insercao(char info) {

    TNo *novo = malloc(sizeof(TNo));
    novo->valor = info;
    novo->esq = NULL, novo->dir = NULL;
    return novo;
}

int main (void) {

    TNo *raiz = NULL, *noB = NULL, *noC = NULL, *noD = NULL, *noE = NULL, *noF = NULL, *noG = NULL;
    raiz = insercao('A');
    noB = insercao('B');
    noC = insercao('C');

    raiz->esq = noB;
    raiz->dir = noC;

    noD = insercao('D');
    noE = insercao('E');
    noF = insercao('F');
    noG = insercao('G');

    noB->esq = noD, noB->dir = noE;
    noC->esq = noF, noC->dir = noG;

    imprime(raiz, 0);

    return 0;
}
