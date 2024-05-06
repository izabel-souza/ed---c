#include "arvore.h"

void simetria(No *arvore) {
    if(arvore != NULL) {
        simetria(arvore->esq);
        printf("%d\n", arvore->valor);
        simetria(arvore->dir);
    }
}

int main (void) {

    No *raiz = criaNo(1);
    No *noA = criaNo(2);
    No *noB = criaNo(3);

    raiz->esq = noA;
    raiz->dir = noB;

    No *noC = criaNo(4);
    No *noD = criaNo(5);

    noB->esq = noC;
    noB->dir = noD;

    simetria(raiz);

    return 0;
}