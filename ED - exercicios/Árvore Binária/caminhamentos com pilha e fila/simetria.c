// Escreva um algoritmo não recursivo para percurso de uma árvore binária em ordem simétrica. Dica: usar uma pilha.

#include "arvore.h"

Pilha *criacaoPilha(void) {
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;

    return p;
}

void push(Pilha *p, int i) {
    Lista *novo = malloc(sizeof(Lista));
    novo->valor = i;
    novo->proximo = p->topo;

    p->topo = novo;
}

int pilhaVazia(Pilha *p) {
    if(p->topo == NULL) return 1;
    else return 0;
}

int pop(Pilha *p) {
    if(pilhaVazia(p)) return -1;

    int x = p->topo->valor;
    p->topo = p->topo->proximo;
    return x;
}

void simetria(No *arvore) {
    Pilha *p = criacaoPilha();

    while(arvore->esq != NULL) {
        push(p, arvore->esq->valor);
        printf("%d\n", p->topo);
        pop(p);
    }
    while(arvore != NULL) {
        printf("%d\n", arvore->valor);
    }

    while(arvore->dir != NULL) {
        push(p, arvore->dir->valor);
        printf("%d\n", p->topo);
        pop(p);
    }
}

int main (void) {

    No *raiz = criaNo(1);
    No *noA = criaNo(22);
    No *noB = criaNo(33);

    raiz->esq = noA;
    raiz->dir = noB;

    No *noC = criaNo(44);
    No *noD = criaNo(55);

    noA->esq = noC;
    noA->dir = noD;

    simetria(raiz);

    return 0;
}