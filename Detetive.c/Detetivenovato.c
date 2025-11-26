#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct Sala: representa um cômodo da mansão */
struct Sala {
    char nome[50];
    struct Sala *esq; /* caminho à esquerda */
    struct Sala *dir; /* caminho à direita */
};

/* criarSala(): cria dinamicamente uma sala com nome */
struct Sala* criarSala(char nome[]) {
    struct Sala* nova = (struct Sala*) malloc(sizeof(struct Sala));
    strcpy(nova->nome, nome);
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

/* explorarSalas(): permite ao jogador navegar pela árvore */
void explorarSalas(struct Sala* atual) {
    char opcao;

    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);

        /* verifica se chegou a um nó sem caminhos */
        if (atual->esq == NULL && atual->dir == NULL) {
            printf("Nao ha mais caminhos. Fim da exploracao.\n");
            return;
        }

        printf("Escolha um caminho (e = esquerda, d = direita, s = sair): ");
        scanf(" %c", &opcao);

        if (opcao == 'e') {
            if (atual->esq != NULL) {
                atual = atual->esq;
            } else {
                printf("Nao ha sala à esquerda.\n");
            }
        }
        else if (opcao == 'd') {
            if (atual->dir != NULL) {
                atual = atual->dir;
            } else {
                printf("Nao ha sala à direita.\n");
            }
        }
        else if (opcao == 's') {
            printf("Exploracao encerrada.\n");
            return;
        }
        else {
            printf("Opcao invalida.\n");
        }
    }
}

/* main(): cria o mapa da mansão e inicia a exploração */
int main() {

    /* Criação manual da árvore da mansão */
    struct Sala* hall        = criarSala("Hall de Entrada");
    struct Sala* salaEstar   = criarSala("Sala de Estar");
    struct Sala* cozinha     = criarSala("Cozinha");
    struct Sala* biblioteca  = criarSala("Biblioteca");
    struct Sala* jardim      = criarSala("Jardim");

    /* Montagem da árvore */
    hall->esq = salaEstar;
    hall->dir = cozinha;

    salaEstar->esq = biblioteca;
    salaEstar->dir = jardim;

    /* Início da exploração */
    explorarSalas(hall);

    return 0;
}
