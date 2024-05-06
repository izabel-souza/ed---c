#include "arvore.h"

void profundidade(No *arvore) {
    if(arvore != NULL) {
        printf("%d\n", arvore->valor);
        profundidade(arvore->esq);
        profundidade(arvore->dir);
    }
}

int main (void) {

    No *raiz = criaNo(0);
    No *noA = criaNo(2);
    No *noB = criaNo(4);

    raiz->esq = noA;
    raiz->dir = noB;

    No *noC = criaNo(6);
    No *noD = criaNo(8);

    noA->dir = noC;
    noB->esq = noD;

    printf("CAMINHAMENTO: PRE-ORDEM\n");
    profundidade(raiz);

    return 0;
}