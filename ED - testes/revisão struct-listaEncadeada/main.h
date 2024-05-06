#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int valor; 
    struct lista *proximo;
}Lista;

Lista *inserir_inicio(Lista *lst, int i);
Lista *inserir_final(Lista *lst, int i);
Lista *inserir_ordenado(Lista *lst, int i);
Lista *inserir_final_recursivo(Lista *lst, int i);
Lista *inserir_ordenado_recursivo(Lista *lst, int i);
Lista *excluir(Lista *lst, int i);
Lista *copiar(Lista *lst);
Lista *filtrar(Lista *lst, int max, int min);
void impressao(Lista *lst);
void menu();