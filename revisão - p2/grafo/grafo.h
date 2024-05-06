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

void imprime(TGrafo *g);
void libera_vizinhos(TVizinho *v);
void libera_grafo(TGrafo *g);
TGrafo *busca_vertice(TGrafo *g, int id_vertice);
TGrafo *insere_vertice(TGrafo *g, int id_vertice);
TVizinho *busca_aresta(TGrafo *g, int vertice1, int vertice2);
void insere_um_sentido(TGrafo *g, int vertice1, int vertice2);
void insere_aresta(TGrafo *g, int vertice1, int vertice2);
void retira_um_sentido(TGrafo *g, int vertice1, int vertice2);
void retira_aresta(TGrafo *g, int vertice1, int vertice2);
TGrafo *retira_vertice(TGrafo *g, int id_vertice);