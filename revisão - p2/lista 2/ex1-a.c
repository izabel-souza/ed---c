#include <stdio.h>
#include <stdlib.h>

typedef struct vizinho {
    int id_vizinho;
    struct vizinho *prox;
} TVizinho;

typedef struct grafo {
    int id_vertice;
    TVizinho *prim_vizinho;
    struct grafo *prox;
} TGrafo;

void imprime(TGrafo *g) {
    while(g != NULL) {
        printf("Vertice %d\n", g->id_vertice);
        TVizinho *v = g->prim_vizinho;
        printf("Vizinhos: ");

        while(v != NULL) {
            printf("%d ", v->id_vizinho);
            v = v->prox;
        }
        printf("\n\n");
        g = g->prox;
    }
}

int main (void) {

    TGrafo *g = NULL;

   return 0;
}