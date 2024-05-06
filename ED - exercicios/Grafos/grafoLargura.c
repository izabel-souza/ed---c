#include <stdio.h>
#include <stdlib.h>

typedef struct vizinho {
    int id_vizinho;
    struct vizinho *proximo;
} TVizinho;

typedef struct grafo {
    int id_vertice;
    struct grafo *proximo;
    TVizinho *primeiro_vizinho;
} TGrafo;

void imprime(TGrafo *g) {
    while(g != NULL) {
        printf("Vertice: %d\n", g->id_vertice);
        printf("Vizinhos: ");
        TVizinho *v = g->primeiro_vizinho;
        while(v != NULL) {
            printf("%d ", v->id_vizinho);
            v = v->proximo;
        }
        printf("\n\n");
        g = g->proximo;
    }
}

TGrafo *busca_vertice(TGrafo *g, int x) {
    while((g != NULL) && (g->id_vertice != x)) 
        g = g->proximo;
    return g;
}

TVizinho *busca_aresta(TGrafo *g, int v1, int v2) {
    TGrafo *pv1 = busca_vertice(g, v1);
    TGrafo *pv2 = busca_vertice(g, v2);
    TVizinho *resp = NULL;

    if((pv1 != NULL) && (pv2 != NULL)) {
        resp = pv1->primeiro_vizinho;
        while((resp != NULL) && (resp->id_vizinho != v2)) 
            resp = resp->proximo;
    }
    return resp;
}

TGrafo *insere_vertice(TGrafo *g, int x) {
    TGrafo *novo = busca_vertice(g, x);
    if(novo == NULL) {
        novo = malloc(sizeof(TGrafo));
        novo->id_vertice = x;
        novo->primeiro_vizinho = NULL;
        novo->proximo = g;
        g = novo;
    }
    return novo;
}

void insere_um_sentido(TGrafo *g, int v1, int v2) {
    TGrafo *p = busca_vertice(g, v1);
    TVizinho *novo = malloc(sizeof(TVizinho));
    novo->id_vizinho = v2;
    novo->proximo = p->primeiro_vizinho;
    p->primeiro_vizinho = novo;
}

void insere_aresta(TGrafo *g, int v1, int v2) {
    TVizinho *v = busca_aresta(g, v1, v2);
    if(v == NULL) 
        insere_um_sentido(g, v1, v2);
}

void retira_um_sentido(TGrafo *g, int v1, int v2) {
    
}

int main (void) {

    TGrafo *g = NULL;

    return 0;
}