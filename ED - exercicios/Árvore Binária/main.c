#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char info;
    struct no *esq, *dir;
} No;

No *criaRaiz(char nome);
No *criaNo(char nome);
void exluicNo(No *no);
void imprime(No *arvore, int tab);

int main (void) {
    
    No *raiz = criaRaiz('A');
    No *noB = criaNo('B');
    No *noC = criaNo('C');

    raiz->esq = noB;
    raiz->dir = noC;

    No *noD = criaNo('D');
    No *noE = criaNo('E');

    noC->esq = noD;
    noC->dir = noE;

    printf("\nARVORE ORIGINAL\n");
    imprime(raiz, 0);

    exluicNo(noC);

    printf("\nARVORE SEM NO 'E'\n");
    imprime(raiz, 0);

    return 0;
}

No *criaRaiz(char nome) {
    No *raiz = malloc(sizeof(No));
    raiz->info = nome;
    raiz->esq = NULL;
    raiz->dir = NULL;
    
    return raiz;
}

No *criaNo(char nome) {
    No *novo_no = malloc(sizeof(No));
    novo_no->info = nome;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    
    return novo_no;
}

void exluicNo(No *no) {
    No *aux = no->dir;
    no->dir = NULL;

    free(aux);
}

void imprime(No *arvore, int tab) {
    for(int i = 0; i < tab; i++) {
        printf("-");
    }
    if(arvore != NULL) {
        printf("%c\n", arvore->info);
        imprime(arvore->esq, tab + 2);
        printf("\n");
        imprime(arvore->dir, tab + 2);
        printf("\n");
    }
    else printf("Vazio");
}
