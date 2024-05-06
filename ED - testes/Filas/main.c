#include "main.h"

int main(void) {

    TFila *fila;
    fila = inicializa();
    insere(fila, 5);
    insere(fila, 3);
    insere(fila, 1);
    insere(fila, 7);

    impressao(fila);

    int x = retira(fila);
    impressao(fila);

    return 0;
}

TFila *inicializa(void) {
    TFila *fila = malloc(sizeof(TFila));
    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

void insere(TFila *fila, int i) {
    TLista *novo = malloc(sizeof(TLista));
    novo->valor = i;
    novo->proximo = NULL;

    if(!fila_vazia(fila)) {
        fila->fim->proximo = novo;
    }
    else fila->inicio = novo; 
    fila->fim = novo;

}

int fila_vazia(TFila *fila) {
    if(fila->inicio == NULL) return 1;
    else return 0;
}

int retira(TFila *fila) {

    if(!fila_vazia(fila)) {
        int x = fila->inicio->valor;
        TLista *aux = fila->inicio;
        fila->inicio = fila->inicio->proximo;

        if(fila->inicio == NULL) fila->fim = NULL;
        free(aux);
        return x;
    }
    else exit(1);
}

void impressao(TFila *fila) {
    for(TLista *p = fila->inicio; p != NULL; p = p->proximo) {
        printf("%d \n", p->valor);
    }
    printf("\n");
}
