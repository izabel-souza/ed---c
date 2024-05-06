#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char info;
    struct no *esq, *dir;
} TNo;

void imprime(TNo *no, int tab) {

    printf("\n");
    for(int i = 0; i < tab; i++) {
        printf("-");
    }
    if(no != NULL) {
        printf("%c\n", no->info);
        imprime(no->esq, tab + 2);
        printf("\n");
        imprime(no->dir, tab + 2);
    }
    else printf("No vazio");
}

TNo *criaNo(char valor) {
    TNo *novo = malloc(sizeof(TNo));
    novo->info = valor;
    novo->esq = NULL, novo->dir = NULL;

    return novo;
}

void espelho(TNo *no) {

    TNo *aux = NULL;

    if(no != NULL) {
        aux = no->dir;
        no->dir = no->esq;
        no->esq = aux;
        espelho(no->esq);
        espelho(no->dir);
    }

}

int main (void) {

    TNo *raiz = NULL;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('D');
    raiz->dir->dir = criaNo('E');
    imprime(raiz, 0);

    imprime(raiz, 0);
    espelho(raiz);
    imprime(raiz, 0);

    return 0;
}