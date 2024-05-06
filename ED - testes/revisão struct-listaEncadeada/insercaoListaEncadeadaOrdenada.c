#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int valor;
    struct lista *proximo;
}Lista;

Lista *insercao_ordenado(Lista *lst, int i);
Lista *insercao_ordenado_recursivo(Lista *lst, int i);
void impressao(Lista *lst);

int main(void) {

    Lista *lista1 = NULL;
    lista1 = insercao_ordenado(lista1, 4);
    lista1 = insercao_ordenado(lista1, 2);
    lista1 = insercao_ordenado(lista1, 3);
    lista1 = insercao_ordenado(lista1, 9);
    lista1 = insercao_ordenado(lista1, 7);
    printf("Lista 1:\n");
    impressao(lista1);

    Lista *lista2 = NULL;
    lista2 = insercao_ordenado_recursivo(lista2, 0);
    lista2 = insercao_ordenado_recursivo(lista2, 1);
    lista2 = insercao_ordenado_recursivo(lista2, 8);
    lista2 = insercao_ordenado_recursivo(lista2, 5);
    lista2 = insercao_ordenado_recursivo(lista2, 6);
    printf("Lista 2:\n");
    impressao(lista2);

    return 0;
}

Lista *insercao_ordenado(Lista *lst, int i) {
    Lista *novo = malloc(sizeof(Lista));
    Lista *p = lst, *anterior = NULL;
    novo->valor = i;

    while(p != NULL && p->valor < i) {
        anterior = p; p = p->proximo;
    }
    if(anterior == NULL) { novo->proximo = lst; lst = novo;}
    else {
        anterior->proximo = novo;
        novo->proximo = p;
    }

    return lst;
}

Lista *insercao_ordenado_recursivo(Lista *lst, int i) {
    Lista *novo = malloc(sizeof(Lista));
    novo->valor = i;

    if(lst == NULL || lst->proximo == NULL) {
        if(lst == NULL) {
            novo->proximo = lst;
            lst = novo;
        }
        else {
            if(lst->valor > i) {
                novo->proximo = lst;
                lst = novo;
            }
            else {
                novo->proximo = NULL;
                lst->proximo = novo;
            }
        }
    }
    else {
        if(lst->valor > i) {
            novo->proximo = lst;
            lst = novo;
        }
        else {
            lst->proximo = insercao_ordenado_recursivo(lst->proximo, i);
        }
    }

    return lst;
}

void impressao(Lista *lst) {
    Lista *p;
    for(p = lst; p != NULL; p = p->proximo) {
        printf("%d ", p->valor);
    }
    printf("\n");
}