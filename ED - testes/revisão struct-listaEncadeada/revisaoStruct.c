#include <stdio.h>
#include <stdlib.h>

typedef struct cadastro {
    char nome[81];
    int idade;
} Cadastro;

void atribuicao_valores_dinamicos(Cadastro **vetor_dinamico, int n);
void atribuicao_valores_estaticos(Cadastro *vetor_estatico, int n);
void impressao_dinamico(Cadastro **vetor, int n);
void impressao_estatico(Cadastro *vetor, int n);

int main (void) {

    int n;
    printf("Informe n: ");
    scanf("%d", &n);

    Cadastro **vetor_dinamico = (Cadastro**) malloc(n * sizeof(Cadastro));
    atribuicao_valores_dinamicos(vetor_dinamico, n);
    printf("STRUCT ALOCADO DINAMICAMENTE\n");
    impressao_dinamico(vetor_dinamico, n);

    Cadastro vetor_estatico[3];
    atribuicao_valores_estaticos(vetor_estatico, 3);
    printf("STRUCT ESTATICO\n");
    impressao_estatico(vetor_estatico, 3);

    free(vetor_dinamico);
    return 0;
}

void atribuicao_valores_dinamicos(Cadastro **vetor_dinamico, int n) {
    for(int i = 0; i < n; i++) {
        vetor_dinamico[i] = malloc(sizeof(Cadastro));
        printf("Informe nome: ");
        scanf(" %s", vetor_dinamico[i]->nome);
        printf("Informe idade: ");
        scanf("%d", &vetor_dinamico[i]->idade);
    }
}

void atribuicao_valores_estaticos(Cadastro *vetor_estatico, int n) {
    for(int i = 0; i < n; i++) {
        printf("Informe nome: ");
        scanf(" %s", vetor_estatico[i].nome);
        printf("Informe idade: ");
        scanf("%d", &vetor_estatico[i].idade);
    }
}

void impressao_dinamico(Cadastro **vetor, int n) {
    for(int i = 0; i < n; i++) {
        printf("CADASTRO %d:\nNOME = %s e IDADE = %d\n", i+1, vetor[i]->nome, vetor[i]->idade);
    }
    printf("\n");
}

void impressao_estatico(Cadastro *vetor, int n) {
    for(int i = 0; i < n; i++) {
        printf("CADASTRO %d:\nNOME = %s e IDADE = %d\n", i+1, vetor[i].nome, vetor[i].idade);
    }
    printf("\n");
}