// Considere uma pilha P vazia e uma fila F não vazia. Utilizando apenas os testes de fila
// e pilha vazias, as operações enfila(), desenfila(), empilha(), desempilha(), de acordo com a
// necessidade, escreva uma função que inverta a ordem dos elementos da fila F.
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int valor;
    struct lista *proximo;
} TLista;

typedef struct fila {
    TLista *inicio, *fim;
} TFila;

typedef struct pilha {
    TLista *topo;
} TPilha;

TFila *criacao_fila(void) {
    TFila *novo = malloc(sizeof(TFila));
    novo->inicio = NULL, novo->fim = NULL;

    return novo;
}

TPilha *criacao_pilha(void) {
    TPilha *novo = malloc(sizeof(TPilha));
    novo->topo = NULL;

    return novo;
}

void imprime_fila(TFila *f) {
    for(TLista *i = f->inicio; i != NULL; i = i->proximo) {
        printf("%d\n", i->valor);
    }
    printf("\n");
}

void imprime_pilha(TPilha *p) {
    for(TLista *i = p->topo; i != NULL; i = i->proximo) {
        printf("%d\n", i->valor);
    }
    printf("\n");
}

int fila_vazia(TFila *f) {
    if(f->inicio == NULL) return 1;
    else return 0;
}

int pilha_vazia(TPilha *p) {
    if(p->topo == NULL) return 1;
    else return 0;
}

void push_fila(TFila *f, int x) {
    TLista *novo = malloc(sizeof(TLista));
    novo->valor = x;
    novo->proximo = NULL;

    if(!fila_vazia(f)) {
        f->fim->proximo = novo;
    }
    else f->inicio = novo;
    f->fim = novo;
}

TPilha *push_pilha(TPilha *p, int x) {

    TLista *novo = malloc(sizeof(TLista));
    novo->valor = x;
    novo->proximo = p->topo;
    p->topo = novo;

    return novo;
}

int pop_fila(TFila *f) {

    if(!fila_vazia(f)) {
        int valor_retirado = f->inicio->valor;
        TFila *aux = f->inicio;
        f->inicio = f->inicio->proximo;

        free(aux);
        return valor_retirado;
    }
    else return -1;
}

int pop_pilha(TPilha *p) {
    if(!pilha_vazia(p)) {
        int x = p->topo->valor;
        p->topo = p->topo->proximo;

        return x;
    }
    else return -1;
}

TPilha *enpila(TPilha *p, TFila *f) {
    while(!fila_vazia(f)) {
        push_pilha(p, f->inicio->valor);
        pop_fila(f);
    }
    return p;
}

TFila *enfilera(TPilha *p, TFila *f) {
    while(!pilha_vazia(p)) {
        push_fila(f, p->topo->valor);
        pop_pilha(p);
    }
    return f;
}

int main (void) {

    TFila *f = NULL;
    f = criacao_fila();

    //atribuicao de valores na fila
    push_fila(f, 1);
    push_fila(f, 2);
    push_fila(f, 3);
    push_fila(f, 4);
    push_fila(f, 5);

    printf("FILA:\n");
    imprime_fila(f);

    TPilha *p = NULL;
    p = criacao_pilha();
    p = enpila(p, f);

    printf("PILHA:\n");
    imprime_pilha(p);

    f = enfilera(p, f);
    printf("FILA INVERTIDA:\n");
    imprime_fila(f);

    return 0;
}