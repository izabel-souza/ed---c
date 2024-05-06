#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct no {
    char info;
    struct no *esq, *dir;
} TNo;

void imprime(TNo *no, int tab) {

    printf("\n");

    for(int i = 0; i < tab; i++) {
        printf("-");
    }

    if(no != NULL) {
        printf("%c\n", no->info);
        imprime(no->esq, tab + 2);
        printf("\n");
        imprime(no->dir, tab + 2);
    }
    else printf("No vazio");
}

TNo *insercao(char info) {
    TNo *novo = malloc(sizeof(TNo));
    novo->info = info;
    novo->esq = NULL, novo->dir = NULL;

    return novo;
}

void profundidade(TNo *no, int *cont) {
    if(no != NULL) {
        (*cont)++;
        profundidade(no->esq, cont);
        profundidade(no->dir, cont);
    }
}

void contagemNos(TNo *no, int *cont) {
    if(no != NULL) {
        profundidade(no, cont);
    }
}

int contagemNiveis(TNo *no) {

    int nivelEsq = 0;
    int nivelDir = 0;

    if(no == NULL) return 0;

    else {
        nivelEsq = 1 + contagemNiveis(no->esq);
        nivelDir = 1 + contagemNiveis(no->dir);
    }

    if(nivelEsq > nivelDir) return nivelEsq;
    else return nivelDir;
}

int verificacaoArvoreCheia(int nosTotal, int niveisTotal) {
    if(nosTotal == (pow(2, niveisTotal)-1)) return 1;
    else return 0;
}

int main (void) {

    TNo *raiz = NULL, *noB = NULL, *noC = NULL, *noD = NULL, *noE = NULL;
    raiz = insercao('A');
    noB = insercao('B');
    noC = insercao('C');

    raiz->esq = noB;
    raiz->dir = noC;

    noD = insercao('D');
    noE = insercao('E');

    noC->esq = noD, noC->dir = noE;

    // TNo *raiz = NULL, *noB = NULL, *noC = NULL, *noD = NULL, *noE = NULL, *noF = NULL, *noG = NULL;
    // raiz = insercao('A');
    // noB = insercao('B');
    // noC = insercao('C');

    // raiz->esq = noB;
    // raiz->dir = noC;

    // noD = insercao('D');
    // noE = insercao('E');
    // noF = insercao('F');
    // noG = insercao('G');

    // noB->esq = noD, noB->dir = noE;
    // noC->esq = noF, noC->dir = noG;

    imprime(raiz, 0);
    printf("\n");

    int nosTotal = 0;
    contagemNos(raiz, &nosTotal);
    printf("\nTOTAL NOS = %d", nosTotal);

    int niveisTotal = contagemNiveis(raiz);
    printf("\nTOTAL NIVEIS = %d\n", niveisTotal);

    int resultado = verificacaoArvoreCheia(nosTotal, niveisTotal);
    (resultado == 1) ? printf("Arvore cheia") : printf("A arvore nao e cheia");

    return 0;
}
