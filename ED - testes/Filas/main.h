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

TFila *inicializa(void);
void insere(TFila *fila, int i);
int fila_vazia(TFila *fila);
int retira(TFila *fila);
void impressao(TFila *fila);