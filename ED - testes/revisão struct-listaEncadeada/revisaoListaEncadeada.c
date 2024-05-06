#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int valor;
    struct lista *proximo;
}Lista;

Lista *insercao_fim(Lista *lista_fim, int n);
Lista *insercao_comeco(Lista *lista_comeco, int n);
Lista *insercao_ordenado(Lista *lista, int n);
void impressao(Lista *lista);

int main (void) {

    Lista *lista1 = NULL, *lista2 = NULL, *lista3 = NULL;
    lista1 = insercao_comeco(lista1, 5);
    lista1 = insercao_comeco(lista1, 4);
    lista1 = insercao_comeco(lista1, 7);
    lista1 = insercao_comeco(lista1, 9);
    lista1 = insercao_comeco(lista1, 8);
    printf("LISTA DA INSERCAO NO COMECO: \n");
    impressao(lista1);

    lista2 = insercao_fim(lista2, 5);
    lista2 = insercao_fim(lista2, 4);
    lista2 = insercao_fim(lista2, 7);
    lista2 = insercao_fim(lista2, 9);
    lista2 = insercao_fim(lista2, 8);
    printf("LISTA DA INSERCAO NO FIM: \n");
    impressao(lista2);

    lista3 = insercao_ordenado(lista3, 5);
    lista3 = insercao_ordenado(lista3, 4);
    lista3 = insercao_ordenado(lista3, 7);
    lista3 = insercao_ordenado(lista3, 9);
    lista3 = insercao_ordenado(lista3, 8);
    printf("LISTA DA INSERCAO ORDENADA: \n");
    impressao(lista3);

    return 0;
}

Lista *insercao_fim(Lista *lista_fim, int n) {
    Lista *novo = malloc(sizeof(Lista));
    Lista *p = lista_fim, *anterior = NULL;

    novo->valor = n;

    while(p != NULL) {
        anterior = p; p = p->proximo;
    }
    if(anterior == NULL) {
        novo->proximo = lista_fim;
        lista_fim = novo;
    }
    else {
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
    }

    return lista_fim;
}

Lista *insercao_comeco(Lista *lista_comeco, int n) {
    Lista *novo = malloc(sizeof(Lista));
    novo->valor = n;
    novo->proximo = lista_comeco;

    return novo;
}

Lista *insercao_ordenado(Lista *lista, int n) {
    Lista *novo = malloc(sizeof(Lista));
    Lista *p = lista;

    novo->valor = n;

    if(p == NULL) { novo->proximo = NULL; lista = novo; }
    else if(p->valor > n) {
        novo->proximo = lista;
        lista = novo;
    }
    else {
        while(p->proximo != NULL && p->proximo->valor < n) {
            p = p->proximo;
        }
        novo->proximo = p->proximo;
        p->proximo = novo;
    }

    return lista;
}

void impressao(Lista *lista) {
    Lista *p = lista;
    while(p != NULL) {
        printf("%d  ", p->valor);
        p = p->proximo;
    }
    printf("\n");
}