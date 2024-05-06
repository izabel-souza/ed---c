#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct vizinho {
    int id_vizinho;
    int peso_aresta;
    struct vizinho *prox;
} TVizinho;

typedef struct grafo {
    int id_vertice;
    TVizinho *primeiro_vizinho;
    struct grafo *prox;
} TGrafo;

void imprime(TGrafo *g) {
    while(g != NULL) {
        printf("Vertice = %d\n", g->id_vertice);

        TVizinho *u = g->primeiro_vizinho;
        printf("Vizinhos: ");
        while(u != NULL) {
            printf("%d ", u->id_vizinho);
            u = u->prox;
        }
        printf("\n\n");
        g = g->prox;
    }
}

TGrafo *busca_vertice(TGrafo *g, int id) {
    while((g != NULL) && (g->id_vertice != id)) {
        g = g->prox;
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

TGrafo *insere_vertice(TGrafo *g, int id) {
    TGrafo *aux = busca_vertice(g, id);

    if(aux == NULL) {
        aux = malloc(sizeof(TGrafo));
        aux->id_vertice = id;
        aux->primeiro_vizinho = NULL;
        aux->prox = g;
        g = aux;
    }

    return g;
}

void insere_um_sentido(TGrafo *g, int v1, int v2, int peso) {
    TGrafo *aux = busca_vertice(g, v1);
    TVizinho *novo = malloc(sizeof(TVizinho));
    novo->peso_aresta = peso;
    novo->id_vizinho = v2;
    novo->prox = aux->primeiro_vizinho;
    aux->primeiro_vizinho = novo;
}

//void insere_aresta(TGrafo *g, int v1, int v2, int peso) {
//    TVizinho *aux = busca_aresta(g, v1, v2);
//    if(aux == NULL) {
//        insere_um_sentido(g, v1, v2, peso);
//    }
//}

int quantidade_vertices(TGrafo *g) {
    TGrafo *aux = g;
    int contagem = 0;
    while(aux != NULL) {
        contagem ++;
        aux = aux->prox;
    }
    return contagem;
}

void inicializa(int *d, int *p, bool *aberto, int nvertices, int s) {

    for(int i = 0; i < nvertices; i++) {
        d[i] = (INT_MAX/2);
        p[i] = -1;
        aberto[i] = true;
    }
    d[s] = 0;
}

int menorDU(TGrafo *g, int *d, bool *aberto) {

    int i = 0;
    while(!aberto[i] && i < g->id_vertice) i++;

    if(i == g->id_vertice) return -1;

    int menor = i;
    for(i = menor+1; i < g->id_vertice; i++) {
        if(aberto[i] && d[menor] > d[i]) {
            menor = i;
        }
    }
    return menor;
}

bool existeAberto(TGrafo *g, bool *aberto) {
    for(int i = 0; i < g->id_vertice; i++) {
        if(aberto[i] == true) return true;
    }
    return false;
}

void relaxe(TVizinho *v, int u, int *d, int *p) {
    if(d[v->id_vizinho] > (d[u] + v->peso_aresta)) {
        d[v->id_vizinho] = (d[u] + v->peso_aresta);
        p[v->id_vizinho] = u;
    }
}

void dijkstra(TGrafo *g, int *d, int *p, bool *aberto) {

    int nvertices = quantidade_vertices(g);

    inicializa(d, p, aberto, nvertices, 0);

    while(existeAberto(g, aberto)) {
        int menorDistancia = menorDU(g, d, aberto);
        aberto[menorDistancia] = false;

        TGrafo *u = busca_vertice(g, menorDistancia);
        TVizinho *v = u->primeiro_vizinho;

        while(u) {
            relaxe(v, menorDistancia, d, p);
            u = u->prox;
        }
    }

}

void printDistancia(TGrafo *g, int *d) {
    int nvertices = quantidade_vertices(g);
    for(int i = 0; i < nvertices; i++){
        printf("%d, ", d[i]);
    }
    printf("\n");
}

int main (void) {

    TGrafo *g = NULL;
    int *d = NULL, *p = NULL;
    bool *aberto = NULL;

	g = insere_vertice(g, 5);
	g = insere_vertice(g, 4);
	g = insere_vertice(g, 3);
	g = insere_vertice(g, 2);
	g = insere_vertice(g, 1);
	g = insere_vertice(g, 0);
	insere_um_sentido(g, 0, 1, 10);
	insere_um_sentido(g, 0, 2, 5);
	insere_um_sentido(g, 1, 3, 1);
	insere_um_sentido(g, 2, 1, 3);
	insere_um_sentido(g, 2, 3, 8);
	insere_um_sentido(g, 2, 4, 2);
	insere_um_sentido(g, 3, 4, 4);
	insere_um_sentido(g, 3, 5, 4);
	insere_um_sentido(g, 4, 5, 6);

	printf("Grafo: \n");
	imprime(g);

    dijkstra(g, d, p, aberto);
    printDistancia(g, d);

    return 0;
}
