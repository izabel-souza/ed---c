#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct pilha {
    int valor;
} TPilha;

void inicializa(int *limite, int *topo, int *base);
int push(TPilha *pilha, int *topo, int limite, int i);
int pop(TPilha *pilha, int *topo, int base);
int peek(TPilha *pilha, int *topo, int base);
int pilha_cheia(int limite, int *topo);
int pilha_vazia(int base, int *topo);
void impressao(TPilha *pilha);