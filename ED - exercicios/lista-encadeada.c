#include "lista-encadeada.h"

TLista* insere_inicio (TLista* li, int i) {
    TLista *novo = malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = li;

    return novo; 
}

TLista* insere_fim (TLista* li, int i) {
    TLista *novo = malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;

    if(li == NULL) { li = novo; }
    else if(li->prox == NULL) { li->prox = novo; }
    else {
        li->prox = insere_fim(li->prox, i);
    }

    return li;
}

TLista* insere_ordenado (TLista* li, int i) {
    TLista *novo = malloc(sizeof(TLista));
    TLista *p = li, *anterior = NULL;
    novo->info = i;


    if(p == NULL) { novo->prox = li; li = novo; }

    else if(p->info > i) {
        novo->prox = li;
        li = novo;
    }
    
    else {
        while(p != NULL && p->info < i) {
            anterior = p;
            p = p->prox;
        }
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }
      
    return li;
}

void imprime (TLista* li) {
    for(TLista *p = li; p != NULL; p = p->prox) {
        printf("%d ", p->info);
    }
    printf("\n");
}

int main (void) {
    TLista* l1 = NULL;
    TLista* l2 = NULL;
    TLista* l3 = NULL ; /* declara listas não inicializadas */
    /* Insere elementos no inicio da lista */
    l1 = insere_inicio(l1, 2);
    l1 = insere_inicio(l1, 3);
    l1 = insere_inicio(l1, 5);
    l1 = insere_inicio(l1, 4);
    printf("Lista 1:\n");
    imprime(l1);

    /* Insere elementos no final da lista*/
    l2 = insere_fim(l2, 2);
    l2 = insere_fim(l2, 3);
    l2 = insere_fim(l2, 5);
    l2 = insere_fim(l2, 4);
    printf("Lista 2:\n");
    imprime(l2);

    /* Insere elementos de forma que a lista esteja sempre ordenada */
    l3 = insere_ordenado(l3, 2);
    l3 = insere_ordenado(l3, 5);
    l3 = insere_ordenado(l3, 3);
    l3 = insere_ordenado(l3, 4);
    l3 = insere_ordenado(l3, 1);
    printf("Lista 3:\n");
    imprime(l3);

    return 0;
}