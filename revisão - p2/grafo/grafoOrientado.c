#include "grafo.h"

int main (void) {

    TGrafo *g = NULL;

    g = insere_vertice(g, 0);
    g = insere_vertice(g, 1);
    g = insere_vertice(g, 2);
    g = insere_vertice(g, 3);
    insere_aresta(g, 0, 1);
    insere_aresta(g, 0, 2);
    insere_aresta(g, 1, 3);
    insere_aresta(g, 2, 3);

    imprime(g);

    g = retira_vertice(g, 0);

    imprime(g);

    libera_grafo(g);

    return 0;
}

void imprime(TGrafo *g) {
    if(g != NULL) {
        printf("Vertice: %d\n", g->id_vertice);
        printf("Vizinhos: ");

        TVizinho *v = g->primeiro_vizinho;
        while(v) {
            printf("%d ", v->id_vizinho);
            v = v->proximo;
        }
        printf("\n\n");
        imprime(g->proximo);
    }
}

void libera_vizinhos(TVizinho *v) {
    if(v != NULL) {
        libera_vizinhos(v->proximo);
        free(v);
    }
}

void libera_grafo(TGrafo *g) {
    if(g != NULL) {
        libera_vizinhos(g->primeiro_vizinho);
        libera_grafo(g->proximo);
        free(g);
    }
}

TGrafo *busca_vertice(TGrafo *g, int id_vertice) {
    while((g != NULL) && (g->id_vertice != id_vertice)) {
        g = g->proximo;
    }
    return g;
}

TGrafo *insere_vertice(TGrafo *g, int id_vertice) {
    TGrafo *novo = busca_vertice(g, id_vertice);
    if(novo == NULL) {
        novo = malloc(sizeof(TGrafo));
        novo->id_vertice = id_vertice;
        novo->primeiro_vizinho = NULL;
        novo->proximo = g;
        g = novo;
    }
    return novo;
}

TVizinho *busca_aresta(TGrafo *g, int vertice1, int vertice2) {
    TGrafo *v1 = busca_vertice(g, vertice1);
    TGrafo *v2 = busca_vertice(g, vertice2);
    TVizinho *resposta = NULL;

    if((v1 != NULL) && (v2 != NULL)) {
        resposta = v1->primeiro_vizinho;
        while((resposta != NULL) && (resposta->id_vizinho != vertice2)) {
            resposta = resposta->proximo;
        }
    }
    return resposta;
}

void insere_um_sentido(TGrafo *g, int vertice1, int vertice2) {
    TGrafo *temp = busca_vertice(g, vertice1);
    TVizinho *novo = malloc(sizeof(TVizinho));
    novo->id_vizinho = vertice2;
    novo->proximo = temp->primeiro_vizinho;
    temp->primeiro_vizinho = novo;
}

void insere_aresta(TGrafo *g, int vertice1, int vertice2) {
    TVizinho *v = busca_aresta(g, vertice1, vertice2);
    if(v == NULL) {
        insere_um_sentido(g, vertice1, vertice2);
    }
}

void retira_um_sentido(TGrafo *g, int vertice1, int vertice2) {
    TGrafo *temp = busca_vertice(g, vertice1);
    if(temp != NULL) {
        TVizinho *anterior = NULL;
        TVizinho *atual = temp->primeiro_vizinho;

        while((atual) && (atual->id_vizinho != vertice2)) {
            anterior = atual;
            atual = atual->proximo;
        }

        if(anterior == NULL) {
            temp->primeiro_vizinho = atual->proximo;
        }
        else {
            anterior->proximo = atual->proximo;
        }

        free(atual);
    }
}

void retira_aresta(TGrafo *g, int vertice1, int vertice2) {
    TVizinho *v = busca_aresta(g, vertice1, vertice2);
    if(v != NULL) {
        retira_um_sentido(g, vertice1, vertice2);
    }
}

TGrafo *retira_vertice(TGrafo *g, int id_vertice) {
    TGrafo *atual = g;
    TGrafo *anterior = NULL;

    if((atual != NULL) && (atual->id_vertice != id_vertice)) {
        anterior = atual;
        atual = anterior;
    }

    if(atual != NULL) {
        while(atual->primeiro_vizinho != NULL) {
            retira_aresta(g, id_vertice, atual->primeiro_vizinho->id_vizinho);
        }

        if(anterior == NULL) {
            g = atual->proximo;
        }
        else {
            anterior->proximo = atual->proximo;
        }
        free(atual);
    }
    return g;
}
