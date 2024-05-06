#include "arvore.h"

void posOrdem(No *arvore) {
    if(arvore != NULL) {
        posOrdem(arvore->esq);
        posOrdem(arvore->dir);
        printf("%d\n", arvore->valor);
    }
}

int main (void) {

    No *raiz = criaNo(1);
    No *noA = criaNo(3);
    No *noB = criaNo(5);

    raiz->esq = noA;
    raiz->dir = noB;

    No *noC = criaNo(7);
    No *noD = criaNo(9);

    noA->dir = noC;
    noB->esq = noD;

    printf("CAMINHAMENTO: POS-ORDEM\n");
    posOrdem(raiz);

    return 0;
}