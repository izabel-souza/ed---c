#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int valor;
    struct lista *proximo;
} TLista;

typedef struct pilha {
    int base;
    TLista *topo;
} TPilha;

TPilha *criacao (void) {
    TPilha *novo = malloc(sizeof(TPilha));
    novo->topo = NULL;

    return novo;
}

void imprime(TPilha *p) {
    for(TLista *i = p->topo; i != NULL; i = i->proximo) {
        printf("%d\n", i->valor);
    }
    printf("\n");
}

int pilha_vazia(TPilha *p) {
    if(p->topo == NULL) return 1;
    else return 0;
}

TPilha *push(TPilha *p, int x) {

    TLista *novo = malloc(sizeof(TLista));
    novo->valor = x;
    novo->proximo = p->topo;
    p->topo = novo;

    return p;
}

int pop(TPilha *p) {
    if(!pilha_vazia(p)) {
        int valor = p->topo->valor;
        p->topo = p->topo->proximo;

        return valor;
    }
    else exit(1);
}

void inverte(TPilha *p) {

    TPilha *aux = NULL;
    aux = criacao();

    while(!pilha_vazia(p)) {
        push(aux, p->topo->valor);
        pop(p);
    }
    printf("\nPILHA AUXILIAR INVERSA\n");
    imprime(aux);
}

int main (void) {

    TPilha *p = NULL;
    p = criacao();

    //atribuicao de valores na pilha
    p = push(p, 50);
    p = push(p, 13);
    p = push(p, 43);
    p = push(p, 21);
    p = push(p, 48);
    p = push(p, 72);
    printf("\nPILHA ORIGINAL:\n");
    imprime(p);

    inverte(p);

    return 0;
}