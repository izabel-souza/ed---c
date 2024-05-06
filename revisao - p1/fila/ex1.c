#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int valor;
    struct lista *proximo;
} TLista;

typedef struct fila {
    TLista *inicio;
    TLista *fim;
} TFila;

TFila *criacao(void) {
    TFila *novo = malloc(sizeof(TFila));
    novo->inicio = NULL;
    novo->fim = NULL;

    return novo;
}

void imprime(TFila *f) {
    for(TLista *i = f->inicio; i != NULL; i = i->proximo) {
        printf("%d\n", i->valor);
    }
    printf("\n");
}

int fila_vazia(TFila *f) {
    if(f->inicio == NULL) return 1;
    else return 0;
}

void push(TFila *f, int x) {
    
    TLista *novo = malloc(sizeof(TLista));
    novo->valor = x;
    novo->proximo = NULL;

    if(fila_vazia(f)) {
        f->inicio = novo;
    }
    else {
        f->fim->proximo = novo;
    }
    f->fim = novo;
}

int pop(TFila *f) {

    if(!fila_vazia(f)) {
        int valor_comeco = f->inicio->valor;
        TFila *aux = f->inicio;
        f->inicio = f->inicio->proximo;

        free(aux);
        return valor_comeco;
    }
    else return -1;
}

void peek(TFila *f) {
    if(!fila_vazia(f)) {
        printf("INICIO = %d\nFIM = %d\n", f->inicio->valor, f->fim->valor);
    }
}

int main (void) {

    TFila *f = NULL;
    f = criacao();

    //Atribuicao de valores na fila
    printf("\nFILA ORIGINAL:\n");
    push(f, 43);
    push(f, 71);
    push(f, 68);
    push(f, 52);
    push(f, 99);
    push(f, 23);

    imprime(f);

    peek(f);

    int x = pop(f);
    printf("\nELEMENTO RETIRADO = %d\n", x);
    printf("\nFILA APOS RETIRAR INICIO:\n");
    imprime(f);

    peek(f);

    return 0;
}