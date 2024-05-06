#include "lista.h"

typedef struct pilha {
    Lista *topo;
} Pilha;

void push(Pilha *p, int i) {
    Lista *novo = malloc(sizeof(Lista));
    novo->valor->valor = i;
    novo->proximo = p->topo;
    p->topo = novo;
}

int pilha_vazia(Pilha *p) {
    if(p->topo == NULL) return 1;
    else return 0;
}

int pop(Pilha *p) {
    if(!pilha_vazia(p)) {
        int x = p->topo->valor;
        p->topo = p->topo->proximo;

        return x;
    }
    else return -1;
}