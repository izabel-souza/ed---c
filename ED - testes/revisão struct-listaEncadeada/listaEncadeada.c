#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int valor;
    struct lista *proximo;
}Lista;

Lista *insere_inicio(Lista *lst, int i);
Lista *insere_final(Lista *lst, int i);
Lista *insere_ordenado(Lista *lst, int i);
Lista *insere_final_recursivo(Lista *lst, int i);
Lista *insere_ordenado_recursivo(Lista *lst, int i);
// Lista *excluir(Lista *lst, int i);
// Lista *filtragem(Lista *lst, int max, int min);
// Lista *copia(Lista *lst);
void impressao(Lista *lst);

int main(void) {

    Lista *l1 = NULL;
    Lista *l2 = NULL;
    Lista *l3 = NULL;
    Lista *l4 = NULL;
    Lista *l5 = NULL;

    l1 = insere_inicio(l1, 4);
    l1 = insere_inicio(l1, 2);
    l1 = insere_inicio(l1, 6);
    l1 = insere_inicio(l1, 1);
    l1 = insere_inicio(l1, 8);
    printf("Lista 1:\n");
    impressao(l1);

    l2 = insere_final(l2, 6);
    l2 = insere_final(l2, 12);
    l2 = insere_final(l2, 18);
    l2 = insere_final(l2, 24);
    l2 = insere_final(l2, 30);
    printf("Lista 2:\n");
    impressao(l2);

    l3 = insere_ordenado(l3, 90);
    l3 = insere_ordenado(l3, 40);
    l3 = insere_ordenado(l3, 70);
    l3 = insere_ordenado(l3, 10);
    l3 = insere_ordenado(l3, 20);
    printf("Lista 3:\n");
    impressao(l3);

    l4 = insere_final_recursivo(l4, 2);
    l4 = insere_final_recursivo(l4, 6);
    l4 = insere_final_recursivo(l4, 94);
    l4 = insere_final_recursivo(l4, 23);
    l4 = insere_final_recursivo(l4, 73);
    printf("Lista 4:\n");
    impressao(l4);

    l5 = insere_ordenado_recursivo(l5, 52);
    l5 = insere_ordenado_recursivo(l5, 79);
    l5 = insere_ordenado_recursivo(l5, 48);
    l5 = insere_ordenado_recursivo(l5, 102);
    l5 = insere_ordenado_recursivo(l5, 1);
    printf("Lista 5: \n");
    impressao(l5);

    return 0;
}

Lista *insere_inicio(Lista *lst, int i) {
    Lista *novo = malloc(sizeof(Lista));
    novo->valor = i;
    novo->proximo = lst;

    return novo;
}

Lista *insere_final(Lista *lst, int i) {
    Lista *novo = malloc(sizeof(Lista));
    novo->valor = i;
    novo->proximo = NULL;

    if(lst == NULL) { lst = novo; }
    else {
        Lista *p = lst;
        while(p->proximo != NULL) { 
            p = p->proximo; 
        }
        p->proximo = novo;
    }
    return lst;
}

Lista *insere_ordenado(Lista *lst, int i) {
    Lista *novo = malloc(sizeof(Lista));
    novo->valor = i;
    Lista *p = lst, *anterior = NULL;

    if(anterior == NULL) { novo->proximo = lst; lst = novo; }
    else {
        while(p != NULL && p->valor < i) {
            anterior = p;
            p = p->proximo;
        }
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
    }
    
    return lst;
}

Lista *insere_final_recursivo(Lista *lst, int i) {
    Lista *novo = malloc(sizeof(Lista));
    novo->valor = i;
    novo->proximo = NULL;

    if(lst == NULL) { lst = novo; }
    else if(lst->proximo == NULL) {
        lst->proximo = novo;
    }
    else {
        lst->proximo = insere_final_recursivo(lst->proximo, i);
    }

    return lst;
}

Lista *insere_ordenado_recursivo(Lista *lst, int i) {
    Lista *novo = malloc(sizeof(Lista));
    novo->valor = i;

    if(lst == NULL) { novo->proximo = NULL; lst = novo;}

    else if(lst->proximo == NULL){
        if(lst->valor > i) {
            novo->proximo = lst;
            lst = novo;
        }
        else {
            novo->proximo = NULL;
            lst->proximo = novo;
        }
    }
    else {
        lst->proximo = insere_ordenado_recursivo(lst->proximo, i);
    }

    return lst;
}

// Lista *excluir(Lista *lst, int i) {

// }

// Lista *filtragem(Lista *lst, int max, int min) {

// }

// Lista *copia(Lista *lst) {

// }

void impressao(Lista *lst) {
    Lista *p;
    for(p = lst; p != NULL; p = p->proximo) {
        printf("%d ", p->valor);
    }
    printf("\n");
}
