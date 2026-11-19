#ifndef PDV_H
#define PDV_H

#include <stdio.h>
#include "jogos.h"            // listaJogos, buscarIndiceJogo, salvarJogosCSV
#include "cadastrosClientes.h" // clientes, totalClientes

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
// Joga fora o que sobrou digitado no teclado ate o Enter
void limparEntradaPDV() {
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF) {
    }
}

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
// Chave-mestra dos alugueis: devolve a posicao do aluguel no vetor,
// ou -1 se o ID nao existe ou o aluguel foi removido
int buscarIndiceAluguel(int id) {
    for (int i = 0; i < totalAlugueis; i++) {
        if (listaAlugueis[i].idAluguel == id && listaAlugueis[i].status != 0) {
            return i;
        }
    }
    return -1;
}

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
// Procura o cliente no vetor do modulo Clientes: devolve a posicao dele,
// ou -1 se o ID nao existe ou o cliente foi removido
int buscarIndiceClientePDV(int id) {
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].idCliente == id && clientes[i].ativo == 1) {
            return i;
        }
    }
    return -1;
}

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
// Cruzamento: confere o cliente (modulo Clientes) e o jogo (modulo Jogos),
// bloqueia se nao houver estoque e da baixa de 1 unidade no jogo
void cadastrarAluguel() {
    int idCliente = 0;
    int idJogo = 0;

    if (totalAlugueis >= MAX_ALUGUEIS) {
        printf("Erro: limite de alugueis atingido.\n");
        return;
    }

    printf("ID do cliente: ");
    if (scanf("%d", &idCliente) != 1) {
        limparEntradaPDV();
        printf("Erro: ID invalido.\n");
        return;
    }
    int posCliente = buscarIndiceClientePDV(idCliente);
    if (posCliente == -1) {
        printf("Erro: cliente com ID %d nao encontrado.\n", idCliente);
        return;
    }

    printf("ID do jogo: ");
    if (scanf("%d", &idJogo) != 1) {
        limparEntradaPDV();
        printf("Erro: ID invalido.\n");
        return;
    }
    int posJogo = buscarIndiceJogo(idJogo);
    if (posJogo == -1) {
        printf("Erro: jogo com ID %d nao encontrado.\n", idJogo);
        return;
    }

    if (listaJogos[posJogo].estoque <= 0) {
        printf("Bloqueado: %s esta sem unidades em estoque.\n", listaJogos[posJogo].nomeJogo);
        return;
    }

    listaAlugueis[totalAlugueis].idAluguel = totalAlugueis + 1;
    listaAlugueis[totalAlugueis].idCliente = idCliente;
    listaAlugueis[totalAlugueis].idJogo = idJogo;
    listaAlugueis[totalAlugueis].valorAluguel = listaJogos[posJogo].valorAluguel;
    listaAlugueis[totalAlugueis].status = 1;
    totalAlugueis++;

    listaJogos[posJogo].estoque--; // baixa de estoque
    salvarJogosCSV();
    salvarAlugueisCSV();

    printf("Aluguel %d registrado: %s alugou %s por R$ %.2f. Estoque restante: %d\n",
           totalAlugueis,
           clientes[posCliente].nomeCliente,
           listaJogos[posJogo].nomeJogo,
           listaJogos[posJogo].valorAluguel,
           listaJogos[posJogo].estoque);
}

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
// Lista os alugueis com o nome do cliente e do jogo (cruza os tres modulos)
void listarAlugueis() {
    int mostrados = 0;

    printf("\n========== Alugueis ==========\n");
    for (int i = 0; i < totalAlugueis; i++) {
        if (listaAlugueis[i].status != 0) {
            int posCliente = buscarIndiceClientePDV(listaAlugueis[i].idCliente);
            int posJogo = buscarIndiceJogo(listaAlugueis[i].idJogo);

            printf("ID: %d | Cliente: ", listaAlugueis[i].idAluguel);
            if (posCliente != -1) {
                printf("%s", clientes[posCliente].nomeCliente);
            } else {
                printf("(cliente removido)");
            }

            printf(" | Jogo: ");
            if (posJogo != -1) {
                printf("%s", listaJogos[posJogo].nomeJogo);
            } else {
                printf("(jogo removido)");
            }

            printf(" | R$ %.2f | ", listaAlugueis[i].valorAluguel);
            if (listaAlugueis[i].status == 1) {
                printf("Em aberto\n");
            } else {
                printf("Devolvido\n");
            }
            mostrados++;
        }
    }

    if (mostrados == 0) {
        printf("Nenhum aluguel registrado.\n");
    }
}

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
// Devolucao: muda o status para 2 e devolve 1 unidade ao estoque, uma vez so
void atualizarAluguel() {
    int id = 0;
    printf("ID do aluguel para devolver: ");
    if (scanf("%d", &id) != 1) {
        limparEntradaPDV();
        printf("Erro: ID invalido.\n");
        return;
    }

    int posicao = buscarIndiceAluguel(id);
    if (posicao == -1) {
        printf("Erro: aluguel com ID %d nao encontrado.\n", id);
        return;
    }

    if (listaAlugueis[posicao].status != 1) {
        printf("Este aluguel ja foi devolvido.\n");
        return;
    }

    listaAlugueis[posicao].status = 2;
    int posJogo = buscarIndiceJogo(listaAlugueis[posicao].idJogo);
    if (posJogo != -1) {
        listaJogos[posJogo].estoque++;
    }

    salvarJogosCSV();
    salvarAlugueisCSV();
    printf("Jogo devolvido!\n");
}

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
// Remocao logica: status 0. Se o aluguel ainda estava aberto, devolve 1 unidade
void removerAluguel() {
    int id = 0;
    printf("ID do aluguel que deseja remover: ");
    if (scanf("%d", &id) != 1) {
        limparEntradaPDV();
        printf("Erro: ID invalido.\n");
        return;
    }

    int posicao = buscarIndiceAluguel(id);
    if (posicao == -1) {
        printf("Erro: aluguel com ID %d nao encontrado.\n", id);
        return;
    }

    if (listaAlugueis[posicao].status == 1) {
        int posJogo = buscarIndiceJogo(listaAlugueis[posicao].idJogo);
        if (posJogo != -1) {
            listaJogos[posJogo].estoque++;
        }
    }
    listaAlugueis[posicao].status = 0;

    salvarJogosCSV();
    salvarAlugueisCSV();
    printf("Aluguel removido!\n");
}

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
// Relatorio: quantos alugueis existem e quanto a locadora faturou
void relatorioFaturamento() {
    float total = 0;
    int abertos = 0;
    int devolvidos = 0;

    for (int i = 0; i < totalAlugueis; i++) {
        if (listaAlugueis[i].status == 1) {
            abertos++;
            total = total + listaAlugueis[i].valorAluguel;
        } else if (listaAlugueis[i].status == 2) {
            devolvidos++;
            total = total + listaAlugueis[i].valorAluguel;
        }
    }

    int quantidade = abertos + devolvidos;
    printf("\n========== Relatorio de faturamento ==========\n");
    printf("Alugueis registrados: %d (em aberto: %d | devolvidos: %d)\n", quantidade, abertos, devolvidos);
    printf("Faturamento total: R$ %.2f\n", total);
    if (quantidade > 0) {
        printf("Valor medio por aluguel: R$ %.2f\n", total / quantidade);
    }
}

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
// Matriz 2D: linhas = plataforma do jogo, colunas = status do aluguel
//            matriz[0][0] = Nintendo em aberto, matriz[1][1] = Mega Drive devolvido
void relatorioMatrizPlataforma() {
    int matriz[2][2];
    char nomesPlataforma[2][15] = {"Nintendo", "Mega Drive"};

    for (int linha = 0; linha < 2; linha++) {
        for (int coluna = 0; coluna < 2; coluna++) {
            matriz[linha][coluna] = 0;
        }
    }

    for (int i = 0; i < totalAlugueis; i++) {
        if (listaAlugueis[i].status == 0) {
            continue; // aluguel removido nao entra no relatorio
        }
        int posJogo = buscarIndiceJogo(listaAlugueis[i].idJogo);
        if (posJogo == -1) {
            continue; // jogo saiu do catalogo
        }
        int linha = listaJogos[posJogo].plataforma - 1; // 1 vira 0, 2 vira 1
        int coluna = listaAlugueis[i].status - 1;       // 1 vira 0, 2 vira 1
        if (linha < 0 || linha > 1) {
            continue; // plataforma invalida no CSV: nao sai da matriz
        }
        matriz[linha][coluna]++;
    }

    printf("\n========== Alugueis por plataforma e status ==========\n");
    printf("%-12s | %9s | %9s | %5s\n", "Plataforma", "Em aberto", "Devolvido", "Total");
    for (int linha = 0; linha < 2; linha++) {
        printf("%-12s | %9d | %9d | %5d\n",
               nomesPlataforma[linha],
               matriz[linha][0],
               matriz[linha][1],
               matriz[linha][0] + matriz[linha][1]);
    }
}

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
// Ranking: jogos mais alugados, do maior para o menor (Bubble Sort)
void relatorioRankingJogos() {
    int contagem[MAX_JOGOS]; // contagem[p] = quantas vezes o jogo da posicao p foi alugado
    int ordem[MAX_JOGOS];    // posicoes dos jogos que entram no ranking
    int quantidade = 0;

    for (int p = 0; p < totalJogos; p++) {
        contagem[p] = 0;
    }

    for (int i = 0; i < totalAlugueis; i++) {
        if (listaAlugueis[i].status != 0) {
            int posJogo = buscarIndiceJogo(listaAlugueis[i].idJogo);
            if (posJogo != -1) {
                contagem[posJogo]++;
            }
        }
    }

    for (int p = 0; p < totalJogos; p++) {
        if (contagem[p] > 0) {
            ordem[quantidade] = p;
            quantidade++;
        }
    }

    if (quantidade == 0) {
        printf("Nenhum aluguel registrado ainda.\n");
        return;
    }

    // Bubble Sort: troca vizinhos quando o da esquerda foi menos alugado
    for (int passada = 0; passada < quantidade - 1; passada++) {
        for (int j = 0; j < quantidade - 1 - passada; j++) {
            if (contagem[ordem[j]] < contagem[ordem[j + 1]]) {
                int troca = ordem[j];
                ordem[j] = ordem[j + 1];
                ordem[j + 1] = troca;
            }
        }
    }

    printf("\n========== Ranking dos jogos mais alugados ==========\n");
    for (int k = 0; k < quantidade; k++) {
        printf("%2d. %s - %d aluguel(is)\n",
               k + 1,
               listaJogos[ordem[k]].nomeJogo,
               contagem[ordem[k]]);
    }
}

#endif
