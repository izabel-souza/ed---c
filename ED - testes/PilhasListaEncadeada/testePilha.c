#include "testePilha.h"

int main(void) {

    TPilha *pilha = inicializa();
    push(pilha, 5);
    push(pilha, 6);
    push(pilha, 7);
    push(pilha, 3);
    push(pilha, 1);
    impressao(pilha);

    int x = pop(pilha);
    impressao(pilha);

    int z = peek(pilha);
    printf("%d ", z);

    return 0;
}

TPilha *inicializa() {
    TPilha *pilha = malloc(sizeof(TPilha));
    pilha->topo = NULL;

    return pilha;
}

void push(TPilha *pilha,int i) {
    TLista *novo = malloc(sizeof(TLista));
    novo->valor = i;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

int pop(TPilha *pilha) {
    if(!pilha_vazia(pilha->topo)) {
        TPilha *aux = pilha->topo->valor;
        pilha->topo = pilha->topo->proximo;
        return aux;
    }
    else printf("Pilha vazia"); exit(1);
}

int peek(TPilha *pilha) {
    if(!pilha_vazia(pilha->topo)) {
        return pilha->topo->valor;
    }
    else return -1;
}

int pilha_vazia(TPilha *topo) {
    if(topo == NULL) return 1;
    else return 0;
}

void impressao(TPilha *pilha) {
    for(TLista *p = pilha->topo; p != NULL; p = p->proximo) {
        printf("%d \n", p->valor);
    }
    printf("\n");
}
