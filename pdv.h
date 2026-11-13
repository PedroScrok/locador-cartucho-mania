#ifndef PDV_H
#define PDV_H

#include <stdio.h>

#define MAX_ALUGUEIS 50

// MODULO 3: PDV / ALUGUEIS
// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
struct Aluguel {
    int idAluguel;
    int idCliente;
    int idJogo;
    float valorAluguel;
    int status; // 1 = alugado, 2 = devolvido, 0 = removido
};

struct Aluguel listaAlugueis[MAX_ALUGUEIS];
int totalAlugueis = 0;

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
void salvarAlugueisCSV() {
    FILE *arquivo = fopen("alugueis.csv", "w");
    if (arquivo == NULL) {
        printf("Erro: nao foi possivel abrir alugueis.csv para gravar.\n");
        return;
    }

    for (int i = 0; i < totalAlugueis; i++) {
        fprintf(arquivo, "%d;%d;%d;%.2f;%d\n",
                listaAlugueis[i].idAluguel,
                listaAlugueis[i].idCliente,
                listaAlugueis[i].idJogo,
                listaAlugueis[i].valorAluguel,
                listaAlugueis[i].status);
    }
    fclose(arquivo);
}

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
void carregarAlugueisCSV() {
    FILE *arquivo = fopen("alugueis.csv", "r");
    if (arquivo == NULL) {
        return;
    }

    totalAlugueis = 0;
    while (totalAlugueis < MAX_ALUGUEIS &&
           fscanf(arquivo, "%d;%d;%d;%f;%d\n",
                  &listaAlugueis[totalAlugueis].idAluguel,
                  &listaAlugueis[totalAlugueis].idCliente,
                  &listaAlugueis[totalAlugueis].idJogo,
                  &listaAlugueis[totalAlugueis].valorAluguel,
                  &listaAlugueis[totalAlugueis].status) == 5) {
        totalAlugueis++;
    }
    fclose(arquivo);
}

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
void cadastrarAluguel() {
    int idCliente = 0;
    int idJogo = 0;

    printf("ID do cliente: \n");
    scanf("%d", &idCliente);

    printf("ID do jogo: \n");
    scanf("%d", &idJogo);
    int posicao = idJogo - 1;

    listaAlugueis[totalAlugueis].idAluguel = totalAlugueis + 1;
    listaAlugueis[totalAlugueis].idCliente = idCliente;
    listaAlugueis[totalAlugueis].idJogo = idJogo;
    listaAlugueis[totalAlugueis].valorAluguel = listaJogos[posicao].valorAluguel;
    listaAlugueis[totalAlugueis].status = 1;
    totalAlugueis++;
    listaJogos[posicao].estoque = listaJogos[posicao].estoque - 1;
    salvarJogosCSV();
    salvarAlugueisCSV();
    printf("Aluguel cadastrado!\n");
}

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
void listarAlugueis() {
    printf("Status: 1 = alugado, 2 = devolvido\n");
    for (int i = 0; i < totalAlugueis; i++) {
        if (listaAlugueis[i].status != 0) {
            printf("ID: %d | Cliente: %d | Jogo: %d | Valor: %.2f | Status: %d\n",
                   listaAlugueis[i].idAluguel,
                   listaAlugueis[i].idCliente,
                   listaAlugueis[i].idJogo,
                   listaAlugueis[i].valorAluguel,
                   listaAlugueis[i].status);
        }
    }
}

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
void atualizarAluguel() {
    int escolha = 0;
    printf("ID do aluguel para devolver: \n");
    scanf("%d", &escolha);
    escolha = escolha - 1;
    int posicao = listaAlugueis[escolha].idJogo - 1;
    if (listaAlugueis[escolha].status == 1) {
        listaJogos[posicao].estoque++;
    }
    listaAlugueis[escolha].status = 2;
    salvarJogosCSV();
    salvarAlugueisCSV();
    printf("Jogo devolvido!\n");
}

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
void removerAluguel() {
    int escolha = 0;
    printf("ID do aluguel que deseja remover: \n");
    scanf("%d", &escolha);
    escolha = escolha - 1;
    int posicao = listaAlugueis[escolha].idJogo - 1;
    if (listaAlugueis[escolha].status == 1) {
        listaJogos[posicao].estoque++;
    }
    listaAlugueis[escolha].status = 0;
    salvarJogosCSV();
    salvarAlugueisCSV();
    printf("Aluguel removido!\n");
}

#endif
