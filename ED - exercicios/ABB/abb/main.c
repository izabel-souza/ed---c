#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char info;
    int chave;
    struct no *esq, *dir;
} TNo;

TNo *criacaoNo(char valor, int chave) {
    TNo *novo = malloc(sizeof(TNo));
    novo->info = valor;
    novo->chave = chave;
    novo->esq = NULL, novo->dir = NULL;

    return novo;
}

TNo *buscaIterativo(TNo *arvore, int chave) {
    TNo *aux = arvore;

    while(aux != NULL) {
        if(aux->chave == chave) return aux;
        else {
            if(aux->chave > chave) aux = aux->esq;
            else aux = aux->dir;
        }
    }
    return NULL;
}

TNo *buscaRecursiva(TNo *arvore, int chave) {
    if(arvore == NULL) return NULL;

    else if(arvore->chave == chave) return arvore;

    else if(arvore->chave > chave) return buscaRecursiva(arvore->esq, chave);

    else return buscaRecursiva(arvore->dir, chave);
}

TNo *insercao(TNo *arvore, char valor, int chave) {

    if(arvore == NULL) {
        TNo *novo = malloc(sizeof(TNo));
        novo->info = valor;
        novo->chave = chave;
        novo->esq = NULL, novo->dir = NULL;
        
        return novo;
    }
    else if((arvore->chave) > chave) {
        arvore->esq = insercao(arvore->esq, valor, chave);
    }
    else if((arvore->chave) < chave) {
        arvore->dir = insercao(arvore->dir, valor, chave);
    }
    else printf("Insercao invalida");

    return arvore;
}

TNo *exclusao(TNo *no, int chave) {
    if(no == NULL) return NULL;

    if(no->chave == chave) {
        free(no);
        return NULL;
    }
    else if(no->chave > chave) {
        no->esq = exclusao(no->esq, chave);
    }
    else {
        no->dir = exclusao(no->dir, chave);
    }
    return no;
}

void imprime(TNo *arvore, int tab) {
    printf("\n");
    for(int i = 0; i < tab; i++) {
        printf("-");
    }
    if(arvore != NULL) {
        printf("%c\n", arvore->info);
        imprime(arvore->esq, tab+2);
        printf("\n");
        imprime(arvore->dir, tab+2);
    }
    else printf("Vazio");
}

int main (void) {

    TNo *raiz = NULL, *noB = NULL, *noC = NULL, *noD = NULL, *noE = NULL;
    raiz = criacaoNo('A', 10);

    noB = criacaoNo('B', 20);
    noC = criacaoNo('C', 5);

    raiz->esq = noC;
    raiz->dir = noB;

    noD = criacaoNo('D', 7);
    noE = criacaoNo('E', 23);

    noC->dir = noD;
    noB->dir = noE;

    // imprime(raiz, 0);
    // printf("\n");

    raiz = insercao(raiz, 'F', 4);

    // imprime(raiz, 0);

    // TNo *busca = NULL;
    // busca = buscaIterativo(raiz, 5);
    // printf("\n%c", busca->info);

    // TNo *busca2 = NULL;
    // busca2 = buscaRecursiva(raiz, 23);
    // printf("\n%c", busca2->info);
    
    // raiz = exclusaoFolha(raiz, 4);
    raiz = exclusaoUmFilho(raiz, 20);
    imprime(raiz, 0);

    return 0;
}