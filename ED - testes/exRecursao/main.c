#include "lista-encadeada.h"

TLista *cria_lista(void) {
    return NULL;
}

TLista *insere_fim_recursivo(TLista *li, int i) {
    TLista *novo = malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;

	if(li == NULL || li->prox == NULL) {
        (li == NULL) ? (li = novo) : (li->prox = novo);
    }
    else {
        li->prox = insere_fim_recursivo(li->prox, i);
    }

    return li;
}

void imprime_lista(TLista *li) {
	TLista *p;
    for(p = li; p != NULL; p = p->prox) {
        printf("%d ", p->info);
    }
    printf("\n");
}

TLista* exclui(TLista *li, int i){
    TLista* p;

	//Verificar se a lista está vazia e retornar
	/*FAZER CODIGO AQUI*/
    if(li == NULL) { return li; }

	//Se eh o elemento a ser excluido, exclui
	if(li->info == i) {
        p = li->prox;
        free(li);
        return p;
    }
	//Se não é, chama exclui no li->prox
    else {
        li->prox = exclui(li->prox, i);
    }
	
    return li;
}

int main(void) {
    TLista *l1;
    
    l1 = cria_lista(); 
    l1 = insere_fim_recursivo(l1, 2);
    l1 = insere_fim_recursivo(l1, 3);
    l1 = insere_fim_recursivo(l1, 5);
    l1 = insere_fim_recursivo(l1, 4);
    printf("Lista 1:\n");
    imprime_lista(l1);
    printf("Lista 1 exclui:\n");
    l1 = exclui(l1, 2);
    imprime_lista(l1);

    return 0;
}