#include "arvore.h"
#include "pilha.h"

Pilha *inicializa(void) {
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void profundidade(No *arvore, Pilha *p) {
    if(arvore != NULL) {
        push(p, arvore->valor);
        printf("%d\n", p->topo->valor->valor);
        int x = pop(p->topo->valor);
    }
    else exit(1);
}

// void imprime(No *arvore, int tab) {
//     for(int i = 0; i < tab; i++) {
//         printf("-");
//     }
//     if(arvore != NULL) {
//         printf("%d\n", arvore->valor);
//         imprime(arvore->esq, tab + 2);
//         printf("\n");
//         imprime(arvore->dir, tab+2);
//     }
//     else printf("NULL");
// }

int main (void) {

    No *raiz = criaNo(1);
    No *noA = criaNo(2);
    No *noB = criaNo(3);

    raiz->esq = noA;
    raiz->dir = noB;

    No *noC = criaNo(4);
    No *noD = criaNo(5);

    noA->esq = noC;
    noA->dir = noD;

    No *noE = criaNo(6);
    No *noF = criaNo(7);

    noB->esq = noE;
    noB->dir = noF;

    Pilha *p = inicializa();
    profundidade(raiz, p);

    return 0;
}