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

TNo *criaCopia(TNo *no) {

    if(no == NULL) return NULL;
    
    TNo *copia = criaNo(no->info);
    copia->esq = criaCopia(no->esq);
    copia->dir = criaCopia(no->dir);

    return copia;
}

int main (void) {

    TNo *raiz = NULL;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('D');
    raiz->dir->dir = criaNo('E');
    
    printf("ARVORE ORIGINAL:");
    imprime(raiz, 0);

    TNo *copia = NULL;
    copia = criaCopia(raiz);
    printf("ARVORE COPIA:\n");
    imprime(copia, 0);

    return 0;
}