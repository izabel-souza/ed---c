#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    char letra;
    struct lista *proximo;
} TLista;

typedef struct pilha {
    TLista *topo;
} TPilha;

TPilha *criacao(void) {
    TPilha *novo = malloc(sizeof(TPilha));
    novo->topo = NULL;

    return novo;
}

void imprime(TPilha *p) {
    for(TLista *i = p->topo; i != NULL; i = i->proximo) {
        printf("%c", i->letra);
    }
    printf("\n");
}

int pilha_vazia(TPilha *p) {
    if(p->topo == NULL) return 1;
    else return 0;
}

TPilha *push(TPilha *p, char letra) {

    TLista *novo = malloc(sizeof(TLista));
    novo->letra = letra;
    novo->proximo = p->topo;
    p->topo = novo;

    return p;
}

int pop(TPilha *p) {
    if(!pilha_vazia(p)) {
        char x = p->topo->letra;
        p->topo = p->topo->proximo;

        return x;
    }
    else exit(1);
}

void inverte_string(TPilha *p) {
    
    TPilha *aux = NULL;
    aux = criacao();

    while(!pilha_vazia(p)) {
        push(aux, p->topo->letra);
        pop(p);
    }
    imprime(aux);
}

int main (void) {

    TPilha *p = NULL;
    p = criacao();

    //atribuicao dos caracteres na string
    p = push(p, 'I');
    p = push(p, 'Z');
    p = push(p, 'A');
    p = push(p, 'B');
    p = push(p, 'E');
    p = push(p, 'L');

    imprime(p);

    return 0;
}