// Q11 - Considere árvores binárias de busca cujos nós têm a estrutura indicada abaixo.  Escreva uma função que receba a raiz de uma tal árvore e a chave de um nó x e devolva o endereço do pai de x.

// typedef struct reg {
//    int         chave;
//    int         conteudo;
//    struct reg *esq, *dir; 
// } noh;

// Se x não pertence à árvore, a função deve devolver NULL.  O consumo de tempo de sua função deve ser limitado pela profundidade de x. 

#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
   int chave;
   int conteudo;
   struct reg *esq, *dir; 
} noh;

void imprime(noh *raiz, int tab) {

    printf("\n");

    for(int i = 0; i < tab; i++) {
        printf("-");
    }

    if(raiz != NULL) {
        printf("%d\n", raiz->chave);
        imprime(raiz->esq, tab + 2);
        printf("\n");
        imprime(raiz->dir, tab + 2);
    }
    else printf("No vazio");
}

noh *insere(noh *raiz, int chave) {

    if(raiz == NULL) {
        raiz = malloc(sizeof(noh));
        raiz->chave = chave;
        raiz->esq = NULL, raiz->dir = NULL;
    }

    else if(chave < (raiz->chave)){
        raiz->esq = insere(raiz->esq, chave);
    }

    else if(chave > (raiz->chave)) {
        raiz->dir = insere(raiz->dir, chave);
    }

    else {
        printf("Operacao Invalida");
        exit(1);
    }

    return raiz;
}

noh *buscaPai(noh *raiz, int chave) {

    if(raiz == NULL) return NULL;

    else if((raiz->esq != NULL && (chave == raiz->esq->chave)) || (raiz->dir != NULL && (chave == raiz->dir->chave))) return raiz;

    else if(chave < (raiz->chave)) return buscaPai(raiz->esq, chave);

    else if(chave > (raiz->chave)) return buscaPai(raiz->dir, chave);

    else return NULL;
}

int main (void) {

    noh *raiz = NULL;
    raiz = insere(raiz, 150);
    insere(raiz, 100);
    insere(raiz, 300);
    insere(raiz, 200);
    insere(raiz, 400);
    insere(raiz, 50);
    insere(raiz, 40);
    insere(raiz, 45);

    imprime(raiz, 0);

    noh *busca;
    busca = buscaPai(raiz, 45);
    if(busca != NULL) {
        printf("\nCHAVE DO PAI DO NO = %d", busca->chave);
    }
    else printf("PAI NAO ENCONTRADO");
    
    return 0;
}