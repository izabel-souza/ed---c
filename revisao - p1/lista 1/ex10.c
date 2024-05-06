// Escreva uma função que decida se uma dada árvore binária é ou não é de busca.

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *esq, *dir;
} TNo;

void imprime(TNo *no, int tab) {
    printf("\n");

    for(int i = 0; i < tab; i++) { printf("-"); }
    
    if(no != NULL) {
        printf("%d\n", no->info);
        imprime(no->esq, tab + 2);
        printf("\n");
        imprime(no->dir, tab + 2);
    }
    else printf("No vazio");
}

TNo *criaNo(int valor) {
    TNo *novo = malloc(sizeof(TNo));
    novo->info = valor;
    novo->esq = NULL, novo->dir = NULL;

    return novo;
}

int verificacaoABB(TNo *no) {

    if(no == NULL) return 1;

    else if((no->esq != NULL && (no->info <= no->esq->info)) || (no->dir != NULL && (no->info >= no->dir->info))) return 0;

    return verificacaoABB(no->esq) && verificacaoABB(no->dir);
}

int main (void) {

    TNo *raiz = NULL, *noA = NULL, *noB = NULL, *noC = NULL, *noD = NULL;
    raiz = criaNo(2);
    noA = criaNo(1);
    noB = criaNo(4);
    noC = criaNo(5);
    noD = criaNo(3);

    //TESTES COM NÓS EM DIFERENTES SUB-ARVORES PARA VERIFICACAO

    raiz->esq = noA, raiz->dir = noB;

    noA->dir = noD;
    noB->esq = noC;

    // noB->esq = noD, noB->dir = noC;


    int resultado = verificacaoABB(raiz);
    (resultado == 1) ? printf("\nA arvore e uma abb\n") : printf("\nA arvore nao e abb\n");

    return 0;
}