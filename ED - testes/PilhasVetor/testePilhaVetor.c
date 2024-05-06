#include "testePilhaVetor.h"

int limite, topo, base;
int main (void) {

    TPilha *pilha[MAX];
    inicializa(&limite, &topo, &base);

    int x = push(pilha, &topo, limite, 5);
    x = push(pilha, &topo, limite, 3);
    x = push(pilha, &topo, limite, 1);
    x = push(pilha, &topo, limite, 7);
    x = push(pilha, &topo, limite, 2);
    x = push(pilha, &topo, limite, 6);
    x = push(pilha, &topo, limite, 8);
    x = push(pilha, &topo, limite, 10);
    x = push(pilha, &topo, limite, 5);
    x = push(pilha, &topo, limite, 11);
    x = push(pilha, &topo, limite, 32);
    x = push(pilha, &topo, limite, 94);
    impressao(pilha);

    x = pop(pilha, &topo, base);
    impressao(pilha);

    int y = peek(pilha, &topo, base);
    printf("%d ", y);

    return 0;
}

void inicializa(int *limite, int *topo, int *base) {
    *topo = -1;
    *base = 0;
    *limite = 9;
}

int push(TPilha *pilha, int *topo, int limite, int i){
    if(!pilha_cheia(limite, *topo)) {
        *topo = *topo + 1;
        pilha[*topo].valor = i;
        return i;
    }
    else return -1;
}

int pop(TPilha *pilha, int *topo, int base) {
    if(!pilha_vazia(base, &topo)) {
        int aux = pilha[*topo].valor;
        *topo = *topo - 1;
        return aux;
    }
    else {
        printf("Pilha vazia"); exit(1);
    }
}

int peek(TPilha *pilha, int *topo, int base) {
    if(!pilha_vazia(base, &topo)) {
        return pilha[*topo].valor;
    }
    else return -1;
}

int pilha_cheia(int limite, int *topo){
    if(topo == limite) return 1;
    else return 0;
}

int pilha_vazia(int base, int *topo){
    if(topo < base) return 1;
    else return 0;
}

void impressao(TPilha *pilha) {
    for(int x = topo; x >= 0; x--) {
        printf("%d \n", pilha[x].valor);
    }
    printf("\n");
}
