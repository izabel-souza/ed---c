#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int valor;
    struct lista *proximo;
} TLista;

typedef struct pilha {
    TLista *topo;
} TPilha;

TPilha *inicializa();
void push(TPilha *pilha,int i);
int pop(TPilha *pilha);
int peek(TPilha *pilha);
int pilha_vazia(TPilha *topo);
void impressao(TPilha *pilha);