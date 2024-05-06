#include "grafo.h"

void imprime(TGrafo *g) {

    while(g != NULL) {
        printf("Vertice = %d\n", g->id_vertice);

        printf("Vizinhos: ");
        TVizinho *v = g->primeiro_vizinho;
        while(v != NULL) {
            printf("%d ", v->id_vizinho);
            v = v->prox;
        }
        printf("\n\n");

        g = g->proximo;
    }
}

void libera_vizinhos(TVizinho *v) {
    while(v != NULL) {
        TVizinho *temp = v;
        v = v->prox;
        free(temp);
    }
}

void libera_vertices(TGrafo *g) {
    while(g != NULL) {
        libera_vizinhos(g->primeiro_vizinho);
        TGrafo *temp = g;
        g = g->proximo;
        free(temp);
    }
}

TGrafo *busca_vertice(TGrafo *g, int x) {
    while((g != NULL) && (g->id_vertice != x)) {
        g = g->proximo;
    }
    return g;
}

TVizinho *busca_aresta(TGrafo *g, int v1, int v2) {

    TGrafo *pv1 = busca_vertice(g, v1);
    TGrafo *pv2 = busca_vertice(g, v2);
    TVizinho *resp = NULL;

    if((pv1 != NULL) && (pv2 != NULL)) {
        resp = pv1->primeiro_vizinho;
        while((resp != NULL) && (resp->id_vizinho != v2)) {
            resp = resp->prox;
        }
    }
    return resp;
}

TGrafo *insercao_vertices(TGrafo *g, int x);
void insercao_um_sentido(TGrafo *g, int v1, int v2);
void insercao_aresta(TGrafo *g, int v1, int v2);


int main (void) {
    
    TGrafo *g = NULL;

}