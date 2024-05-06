#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *esq, *dir;
} TNo;

void imprime(TNo *no, int tab) {

    printf("\n");
    for(int i = 0; i < tab; i++) {
        printf("-");
    }
    if(no != NULL) {
        printf("%d\n", no->info);
        imprime(no->esq, tab + 2);
        printf("\n");
        imprime(no->dir, tab + 2);
    }
    else printf("No vazio");
}

TNo *criaNo(int info) {
    TNo *novo = malloc(sizeof(TNo));
    novo->info = info;
    novo->esq = NULL, novo->dir = NULL;

    return novo;
}

int maior(TNo *no) {

    int maiorNo = no->info;
    TNo *maiorNoEsq = maior(no->esq);
    int maiorNoDir = maior(no->dir);

    if(no->esq != NULL) {
        if(maiorNo < maiorNoEsq) {
            x = no->info;
        }
    }
    return x;
}

int main (void) {

    TNo *raiz = NULL;
    raiz = criaNo('1');
    raiz->esq = criaNo('2');
    raiz->dir = criaNo('3');
    raiz->dir->esq = criaNo('4');
    raiz->dir->dir = criaNo('5');

    imprime(raiz, 0);

    int x = maior(raiz);
    printf("\nMAIOR ELEMENTO = %d", x);

    return 0;
}