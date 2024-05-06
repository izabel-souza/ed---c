#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq, *dir;
} No;

No *criaNo(int i) {
    No *novo = malloc(sizeof(No));
    novo->valor = i;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}