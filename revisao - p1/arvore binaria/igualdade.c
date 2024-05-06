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

TNo *criaNo(char info) {
    TNo *novo = malloc(sizeof(TNo));
    novo->info = info;
    novo->esq = NULL, novo->dir = NULL;

    return novo;
}

int igual(TNo *no1, TNo *no2) {

    if(no1 == NULL || no2 == NULL) return -1;
    else {
        
    }
    
}

int main (void) {

    TNo *raiz = NULL;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('D');
    raiz->dir->dir = criaNo('E');

    printf("\nARVORE 1:");
    imprime(raiz, 0);

    TNo *raiz2 = NULL;
    raiz2 = criaNo('A');
    raiz2->esq = criaNo('B');
    raiz2->dir = criaNo('C');
    raiz2->esq->esq = criaNo('D');
    raiz2->dir->dir = criaNo('E');

    printf("\nARVORE 2:");
    imprime(raiz2, 0);

    int x = igual(raiz, raiz2);
    (x == 1) ? printf("\nSAO IGUAIS\n") : printf("\nSAO DIFERENTES\n");

    return 0;
}