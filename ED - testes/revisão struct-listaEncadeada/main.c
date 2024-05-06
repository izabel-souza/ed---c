#include <main.h>

int main (void) {

    Lista *l1 = NULL, *l2 = NULL, *l3 = NULL, *l4 = NULL, *l5 = NULL;
    int opcao;
    menu();
    printf("Informe uma opcao: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1: l1 = inserir_inicio(l1, 3); break;
        case 2: l2 = inserir_final(l2, 3); break;
        case 3: l3 = inserir_ordenado(l3, 4); break;
        case 4: l4 = inserir_final_recursivo(l4, 5); break;
        case 5: l5 = inserir_ordenado_recursivo(l5, 8); break;

        case 6: 
            int valor, lista;
            printf("Informe a lista e o valor a ser excluido: ");
            scanf("%d %d", &lista, &valor);
            
        ; break;
        case 7: ; break;
        case 8:; break;
    }

    return 0;
}

void menu() {
    printf("1- Inserir no inicio\n2- Inserir no final\n3- Inserir ordenado\n4- Inserir final recursivo\n5- Inserir ordenado recursivo\n6- Excluir no especifico\n");
}

Lista *inserir_inicio(Lista *lst, int i) {
    Lista *novo = malloc(sizeof(Lista));
    novo->valor = i;
    novo->proximo = lst;

    return novo;
}

Lista *inserir_final(Lista *lst, int i) {
    Lista *novo = malloc(sizeof(Lista));
    novo->valor = i;
    novo->proximo = NULL;
    Lista *p = lst;

    if(lst == NULL) { lst = novo;}
    else {
        while(p != NULL) {
            p = p->proximo;
        }
        p->proximo = novo;
    }

    return lst;
}

Lista *inserir_ordenado(Lista *lst, int i) {

}

Lista *inserir_final_recursivo(Lista *lst, int i) {
    Lista *novo = malloc(sizeof(Lista));
    novo->valor = i;
    novo->proximo = NULL;

    if(lst ==  NULL) { lst = novo;}
    else {
        lst->proximo = inserir_final_recursivo(lst->proximo, i);
    }
    lst->proximo = novo;

    return lst;
}

Lista *inserir_ordenado_recursivo(Lista *lst, int i) {

}

Lista *excluir(Lista *lst, int i) {

    if(lst == NULL) { return lst; }
    else {
        if(lst->valor == i) {
            Lista *p = lst;
            lst = lst->proximo;
            free(p);
            return lst;
        }
        else {
            lst->proximo = excluir(lst->proximo, i);
        }
    }

    return lst;
}

Lista *copiar(Lista *lst) {

}

Lista *filtrar(Lista *lst, int max, int min) {

}

void impressao(Lista *lst) {
    if(lst != NULL) {
        printf("%d ", lst->valor);
        impressao(lst->proximo);
    }
    printf("\n");
}