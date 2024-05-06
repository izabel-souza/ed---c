// Suponha que as chaves  50 30 70 20 40 60 80 15 25 35 45 36  são inseridas, nesta ordem, numa árvore de busca inicialmente vazia. Desenhe a árvore que resulta. Em seguida remova o nó que contém 30.

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} TNoABB;

void imprime(TNoABB *raiz, int tab) {

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

TNoABB *insere(TNoABB *raiz, int chave) {

    if(raiz == NULL) {
        raiz = (TNoABB *) malloc(sizeof(TNoABB));
        raiz->chave = chave;
        raiz->esq = NULL, raiz->dir = NULL;
    }

    else if(chave < (raiz->chave)) {
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

TNoABB *maior_no_esquerda(TNoABB *raiz) {

    TNoABB *atual = raiz;
    while(atual->dir != NULL) {
        atual = atual->dir;
    }
    return atual;
}

TNoABB *exclui(TNoABB *raiz, int chave) {

    if (raiz == NULL) return raiz;

	// Se chave é menor do que a chave da raiz, procura na subárvore esquerda
	if (chave < raiz->chave) {
		raiz->esq = exclui(raiz->esq, chave);
    }

	// Se chave é maior do que a chave da raiz, procura na subárvore direita
	else if (chave > raiz->chave) {
		raiz->dir = exclui(raiz->dir, chave);
    }

	// Senão, a chave é igual e esse é o nó que tem que ser excluído
	else {

		// só tem subárvore direita ou nenhuma subárvore
		if (raiz->esq == NULL){
            TNoABB *aux = raiz->dir;
            free(raiz);
			return aux;
		} 

		// só tem subárvore esquerda ou nenhuma subárvore
        else if (raiz->dir == NULL){
            TNoABB *aux = raiz->esq;
            free(raiz);
			return aux;
		} 
        
        // nó com 2 filhos - pega o maior da subárvore esquerda
        else { 
            TNoABB *aux = maior_no_esquerda(raiz->esq);
            raiz->chave = aux->chave;
            raiz->esq = exclui(raiz->esq, aux->chave);
		}
	}
	return raiz;
}

int main (void) {

    TNoABB *raiz = NULL;
    raiz = insere(raiz, 50);
    insere(raiz, 30);
    insere(raiz, 70);
    insere(raiz, 20);
    insere(raiz, 40);
    insere(raiz, 60);
    insere(raiz, 80);
    insere(raiz, 15);
    insere(raiz, 25);
    insere(raiz, 35);
    insere(raiz, 45);
    insere(raiz, 36);

    printf("ARVORE ORIGINAL:\n");
    imprime(raiz, 0);

    exclui(raiz, 30);
    printf("\nARVORE APOS EXCLUSAO:\n");
    imprime(raiz, 0);

    return 0;
}