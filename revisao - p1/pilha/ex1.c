// requer operação de consulta topo
// requer operação de consulta base
// requer operação peek
// requer operação pop

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
        int topo = p->topo->valor;
        p->topo = p->topo->proximo;

        return topo;
    }
    else return -1;
}

int pegaBase(TPilha *p) {
    if(!pilha_vazia(p)) {
        for(TLista *i = p->topo; i != NULL; i = i->proximo) {
            if(i->proximo == NULL) {
                return i->valor;
            }
        }
    }
    else return -1;
}

int peek(TPilha *p) {
    if(!pilha_vazia(p)) return p->topo->valor;
    else return -1;
}

void imprime(TPilha *p) {
    for(TLista *i = p->topo; i != NULL; i = i->proximo) {
        printf("%d\n", i->valor);
    }
    printf("\n");
}

int main (void) {

    TPilha *p = NULL;
    p = criacao();

    //atribuicoes de valores na pilha
    p = push(p, 50);
    p = push(p, 13);
    p = push(p, 43);
    p = push(p, 21);
    p = push(p, 48);
    p = push(p, 72);
    printf("\nPILHA ORIGINAL:\n");
    imprime(p);

    int base = pegaBase(p);
    int topo = peek(p);
    printf("BASE = %d\nTOPO = %d\n", base, topo);

    int x = pop(p);
    printf("\nTOPO REMOVIDO = %d\n", x);
    printf("PILHA ATUAL:\n");
    imprime(p);

    return 0;
}