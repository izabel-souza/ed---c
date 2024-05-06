// Dada uma AVL cuja raiz é um nó folha com a chave 50: 

// (a) insira os elementos {1, 64, 12, 18, 66, 38, 95, 58, 59, 70, 68, 39, 62, 7, 60, 43, 16, 67, 34, 35} nesta árvore, indicando as rotações necessárias; 

// (b) retire os elementos {50, 95, 70, 60, 35} desta árvore, explicitando as rotações.

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    int fb;
    struct no *esq, *dir;
} TNoAVL;

void imprime(TNoAVL *raiz, int tab) {

    printf("\n");
    for(int i = 0; i < tab; i++) { printf("-"); }

    if(raiz != NULL) {
        printf("%d\n", raiz->chave);
        imprime(raiz->esq, tab + 2);
        printf("\n");
        imprime(raiz->dir, tab + 2);
    }
    else printf("No vazio");
}

TNoAVL *rotacao_esquerda(TNoAVL *raiz) {
    TNoAVL *u;
    u = raiz->dir;
    raiz->dir = u->esq;
    u->esq = raiz;
    raiz->fb = 0;
    raiz = u;

    return raiz;
}

TNoAVL *rotacao_direita(TNoAVL *raiz) {
    TNoAVL *u;
    u = raiz->esq;
    raiz->esq = u->dir;
    u->dir = raiz;
    raiz->fb = 0;
    raiz = u;

    return raiz;
}

TNoAVL *rotacao_dupla_esquerda(TNoAVL *raiz) {
    raiz->dir = rotacao_direita(raiz->dir);
    raiz = rotacao_esquerda(raiz);
    
    return raiz;
}

TNoAVL *rotacao_dupla_direita(TNoAVL *raiz) {
    raiz->esq = rotacao_esquerda(raiz->esq);
    raiz = rotacao_direita(raiz);

    return raiz;
}

TNoAVL *caso1(TNoAVL *raiz) { //fb = -2
    TNoAVL *u = raiz->esq;

    if(u->fb == -1) {
        printf("\nFazendo rotacao direita em %d", raiz->chave);
        raiz = rotacao_direita(raiz);
    }
    else {
        printf("\nFazendo rotacao dupla direita em %d", raiz->chave);
        raiz = rotacao_dupla_direita(raiz);
    }
    raiz->fb = 0;

    return raiz;
}

TNoAVL *caso2(TNoAVL *raiz) {  //fb = +2
    TNoAVL *u = raiz->dir;

    if(u->fb == 1) {
        printf("\nFazendo rotacao esquerda em %d", raiz->chave);
        raiz = rotacao_esquerda(raiz);
    }
    else {
        printf("\nFazendo rotacao dupla esquerda em %d", raiz->chave);
        raiz = rotacao_dupla_esquerda(raiz);
    }
    raiz->fb = 0;

    return raiz;
}

void consultaFBEsq(TNoAVL *raiz, int *flag) {
    if(*flag) {
        switch(raiz->fb) {
            case -1:
                raiz = caso1(raiz);
                *flag = 0;
                break;
            case 0:
                raiz->fb = -1;
                break;
            case 1:
                raiz->fb = 0;
                *flag = 0;
                break;
        }
    }
}

void consultaFBDir(TNoAVL *raiz, int *flag) {
    if(*flag) {
        switch(raiz->fb) {
            case -1:
                raiz->fb = 0;
                *flag = 0;
                break;
            case 0:
                raiz->fb = 1;
                break;
            case 1:
                raiz = caso2(raiz);
                *flag = 0;
                break;
        }
    }
}

TNoAVL *insere(TNoAVL * raiz, int chave, int *flag) {

    if(raiz == NULL) {

        raiz = (TNoAVL*) malloc(sizeof(TNoAVL));
        raiz->chave = chave;
        raiz->esq = NULL, raiz->dir = NULL;
        raiz->fb = 0;
        *flag = 1;

        printf("\nInseriu %d", raiz->chave);
    }

    else if(chave < (raiz->chave)) {
        raiz->esq = insere(raiz->esq, chave, flag);

        consultaFBEsq(raiz->esq, flag);
    }

    else if(chave > (raiz->chave)) {
        raiz->dir = insere(raiz->dir, chave, flag);

        consultaFBDir(raiz->dir, flag);    
    }
    return raiz;
}

// TNoAVL *maior_no_esquerda(TNoAVL *raiz) {

//     TNoAVL *atual = raiz;
//     while(atual->dir != NULL) {
//         atual = atual->dir;
//     }

//     return atual;
// }

// TNoAVL *remove(TNoAVL *raiz, int chave, int *flag) {

//     if(raiz == NULL) return raiz;

//     else if(chave < raiz->chave) {
//         raiz->esq = remove(raiz->esq, chave, flag);
//     }

//     else if(chave > raiz->chave) {
//         raiz->dir = remove(raiz->dir, chave, flag);
//     }

//     else {

//         if(raiz->esq == NULL) { 
//             TNoAVL *aux = raiz->dir;
//             free(raiz);

//             aux->fb = 0;

//             return aux;
//         }

//         else if(raiz->dir == NULL) {
//             TNoAVL *aux = raiz->esq;
//             free(raiz);

//             aux->fb = 0;

//             return aux;
//         }

//         else {
//             TNoAVL *aux = maior_no_esquerda(raiz->esq);
//             raiz->chave = aux->chave;
//             raiz->esq = remove(raiz->esq, aux->chave, flag);

//             aux->fb = 1;

//         }

//     }
//     return raiz;
// }

int main (void) {

    TNoAVL *raiz = NULL;
    int ok;

    raiz = insere(raiz, 50, &ok);
    insere(raiz, 1, &ok);
    insere(raiz, 64, &ok);
    insere(raiz, 12, &ok);
    insere(raiz, 18, &ok);
    insere(raiz, 66, &ok);
    insere(raiz, 38, &ok);
    insere(raiz, 95, &ok);
    insere(raiz, 58, &ok);
    insere(raiz, 59, &ok);
    insere(raiz, 70, &ok);
    insere(raiz, 68, &ok);
    insere(raiz, 39, &ok);
    insere(raiz, 62, &ok);
    insere(raiz, 7, &ok);
    insere(raiz, 60, &ok);
    insere(raiz, 43, &ok);
    insere(raiz, 16, &ok);
    insere(raiz, 67, &ok);
    insere(raiz, 34, &ok);
    insere(raiz, 35, &ok);

    imprime(raiz, 0);

    return 0;
}