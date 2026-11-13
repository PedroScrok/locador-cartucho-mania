#ifndef JOGOS_H
#define JOGOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOGOS 50

// --------------------------------------------------
// MODULO 2: JOGOS
// Autor: Eduardo Piana Passos da Silva - RGM 48545015
// -------------------------------------------------

struct Jogo {
    int idJogo;
    char nomeJogo[50];
    int plataforma; // 1 = nintendo 2 = megadrive
    int estoque;
    float valorAluguel; 
    int ativo; // 1 = ativo, 0 = removido
};

struct Jogo listaJogos[MAX_JOGOS];
int totalJogos = 0;

// ---- Autor: Eduardo Piana Passos da Silva - RGM 48545015 ---

void limparEntradaJogo() {   
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF) {
    }
}

void salvarJogosCSV() {
    FILE *arquivo = fopen("jogos.csv", "w"); //ponteiro e "w" apaga o conteudo antigo
    if (arquivo == NULL) {
        printf("Erro: nao foi possivel abrir jogos.csv para gravar.\n");
        return;
    }

    for (int i = 0; i < totalJogos; i++) {
        fprintf(arquivo, "%d;%s;%d;%d;%.2f;%d\n",
                listaJogos[i].idJogo,
                listaJogos[i].nomeJogo,
                listaJogos[i].plataforma,
                listaJogos[i].estoque,
                listaJogos[i].valorAluguel,
                listaJogos[i].ativo);
    }

    fclose(arquivo);
}

void carregarJogosCSV() {
    FILE *arquivo = fopen("jogos.csv", "r");
    if (arquivo == NULL) {
        return;
    }

    totalJogos = 0;
    while (totalJogos < MAX_JOGOS &&
           fscanf(arquivo, "%d;%49[^;];%d;%d;%f;%d\n",
                  &listaJogos[totalJogos].idJogo,
                  listaJogos[totalJogos].nomeJogo, //string, endereço de onde começa na memória
                  &listaJogos[totalJogos].plataforma,
                  &listaJogos[totalJogos].estoque,
                  &listaJogos[totalJogos].valorAluguel,
                  &listaJogos[totalJogos].ativo) == 6) { //conferir se todos os campos foram lifos
                
        totalJogos++;
    }

    fclose(arquivo);
}

// Autor: Eduardo Piana Passos da Silva - RGM 48545015
void cadastrarJogo() {
    printf("\n========== Cadastrar Jogo ==========\n");
    if (totalJogos >= MAX_JOGOS) {
        printf("Erro: Limite de jogos cadastrados atingido.\n");
        return;
    }

    listaJogos[totalJogos].idJogo = totalJogos + 1;

    printf("Nome do jogo: ");
    scanf(" %49[^\n]", listaJogos[totalJogos].nomeJogo);

    int plataforma;

    do {
        printf("Plataforma (1 - Nintendo, 2 - Mega Drive): ");
        if (scanf("%d", &plataforma) != 1) {
            limparEntradaJogo();
            plataforma = 0; //se a pessoa digitou letra, com 0 no próximo if ele mostra o erro e depois repete a pergunta 
        }
        if (plataforma != 1 && plataforma != 2) {
            printf("Erro: Plataforma invalida. Digite 1 para Nintendo ou 2 para Mega Drive.\n");
        }
    } while (plataforma != 1 && plataforma != 2);

    listaJogos[totalJogos].plataforma = plataforma;

    int estoque;

    do {
        printf("Quantidade em estoque: ");
        if (scanf("%d", &estoque) != 1) {
            limparEntradaJogo();
            estoque = -1;
        }
        if (estoque < 0) {
            printf("Erro: Quantidade em estoque invalida. Digite um numero valido.\n");
        }
    } while (estoque < 0);

    listaJogos[totalJogos].estoque = estoque;

    float valorAluguel;

    do {
        printf("Valor do aluguel: ");
        if (scanf("%f", &valorAluguel) != 1) {
            limparEntradaJogo();
            valorAluguel = 0; 
        }
        if (valorAluguel <= 0) {
            printf("Erro: Valor do aluguel invalido. Digite um valor maior que zero.\n");
        }
    } while (valorAluguel <= 0);

    listaJogos[totalJogos].valorAluguel = valorAluguel;

    listaJogos[totalJogos].ativo = 1;

    printf("Jogo cadastrado com sucesso! ID: %d | %s\n", listaJogos[totalJogos].idJogo, listaJogos[totalJogos].nomeJogo);

    totalJogos++;

    salvarJogosCSV(); //pro novo jogo entrar na contagem
}

// Autor: Eduardo Piana Passos da Silva - RGM 48545015

void listarJogos() {
    printf("\n========== Lista de Jogos ==========\n");

    if (totalJogos == 0) {
        printf("Nenhum jogo cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalJogos; i++) {
        if (listaJogos[i].ativo == 1) {
            printf("ID: %d | %s | ", listaJogos[i].idJogo, listaJogos[i].nomeJogo);
            if (listaJogos[i].plataforma == 1) {
                printf("Plataforma: Nintendo ");
            } else if (listaJogos[i].plataforma == 2) {
                printf("Plataforma: Mega Drive ");
            }
            printf(" | Estoque: %d | R$ %.2f\n", listaJogos[i].estoque, listaJogos[i].valorAluguel);
        }
    }
}

// Autor: Eduardo Piana Passos da Silva - RGM 48545015
int buscarIndiceJogo(int id) {
    for (int i = 0; i < totalJogos; i++) {
        if (listaJogos[i].idJogo == id && listaJogos[i].ativo == 1) {
            return i;
        }
    }
    return -1;
}


// Autor: Eduardo Piana Passos da Silva - RGM 48545015
void removerJogo() {
    printf("\n========== Remover Jogo ==========\n");

    int id;
    printf("Digite o ID do jogo que deseja remover: ");
    if (scanf("%d", &id) != 1) {
        limparEntradaJogo();
        printf("Erro: ID invalido.\n");
        return;
    }

    int posicao = buscarIndiceJogo(id);
    if (posicao == -1) { //nenhuma posição do vetor é negativa 
        printf("Erro: jogo com ID %d nao encontrado.\n", id);
        return;
    }

    listaJogos[posicao].ativo = 0;
    printf("Jogo removido: %s\n", listaJogos[posicao].nomeJogo);
    salvarJogosCSV();
}

// Autor: Eduardo Piana Passos da Silva - RGM 48545015
void atualizarJogo() {
    printf("\n========== Atualizar Jogo ==========\n");

    int id;
    printf("Digite o ID do jogo que deseja atualizar: ");
    if (scanf("%d", &id) != 1) {
        limparEntradaJogo();
        printf("Erro: ID invalido.\n");
        return;
    }

    int posicao = buscarIndiceJogo(id);
    if (posicao == -1) {
        printf("Erro: jogo com ID %d nao encontrado.\n", id);
        return;
    }

    int campo;
    int novoEstoque;
    float novoValor;

    printf("Jogo encontrado: %s\n", listaJogos[posicao].nomeJogo);
    printf("[1] - Nome\n");
    printf("[2] - Estoque\n");
    printf("[3] - Valor do aluguel\n");
    printf("O que deseja atualizar? ");
    if (scanf("%d", &campo) != 1) {
        limparEntradaJogo();
        campo = 0;
    }

    switch (campo) {
        case 1:
            printf("Novo nome: ");
            scanf(" %49[^\n]", listaJogos[posicao].nomeJogo);
            break;
        case 2:
            do {
                printf("Novo estoque: ");
                if (scanf("%d", &novoEstoque) != 1) {
                    limparEntradaJogo();
                    novoEstoque = -1;
                }
                if (novoEstoque < 0) {
                    printf("Erro: digite um numero maior ou igual a 0.\n");
                }
            } while (novoEstoque < 0);
            listaJogos[posicao].estoque = novoEstoque;
            break;
        case 3:
            do {
                printf("Novo valor do aluguel: ");
                if (scanf("%f", &novoValor) != 1) {
                    limparEntradaJogo();
                    novoValor = 0;
                }
                if (novoValor <= 0) {
                    printf("Erro: digite um valor maior que zero.\n");
                }
            } while (novoValor <= 0);
            listaJogos[posicao].valorAluguel = novoValor;
            break;
        default:
            printf("Opcao invalida. Nada foi alterado.\n");
            return;
    }

    salvarJogosCSV();
    printf("Jogo atualizado com sucesso!\n");
}

// Autor: Eduardo Piana Passos da Silva - RGM 48545015
// Mostra os jogos ativos cujo nome contem o texto digitado (busca parcial com strstr).
void buscarJogoPorNome() {
    printf("\n========== Buscar Jogo por Nome ==========\n");

    char termo[50];
    printf("Digite o nome ou parte do nome: ");
    scanf(" %49[^\n]", termo);

    int encontrados = 0;

    for (int i = 0; i < totalJogos; i++) {
        if (listaJogos[i].ativo == 1 && strstr(listaJogos[i].nomeJogo, termo) != NULL) {
            printf("ID: %d | %s | Estoque: %d | R$ %.2f\n", listaJogos[i].idJogo, listaJogos[i].nomeJogo, listaJogos[i].estoque, listaJogos[i].valorAluguel);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum jogo encontrado com esse nome.\n");
    }
}

// Autor: Eduardo Piana Passos da Silva - RGM 48545015
int menuJogos() {
    int opcaoJogos = 0;

    do {
        printf("\n========== Locadora Cartucho Mania - Jogos ==========\n");
        printf("[1] - Cadastrar jogo\n");
        printf("[2] - Listar cadastros de jogos\n");
        printf("[3] - Atualizar cadastro do jogo\n");
        printf("[4] - Remover cadastro do jogo\n");
        printf("[5] - Buscar jogo por nome\n");
        printf("[9] - Voltar ao menu principal\n");
        printf("Opcao desejada: ");

        if (scanf("%d", &opcaoJogos) != 1) {
            int caractere;
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
            }
            printf("Erro: Entrada invalida, digite um numero.\n");
            opcaoJogos = -1;
            continue;
        }

        switch (opcaoJogos) {
            case 1:
                cadastrarJogo();
                break;
            case 2:
                listarJogos();
                break;
            case 3:
                atualizarJogo();
                break;
            case 4:
                removerJogo();
                break;
            case 5:
                buscarJogoPorNome();
                break;
            case 9:
                break;
            default:
                printf("Erro: Opcao invalida.\n");
        }

    } while (opcaoJogos != 9);

    return opcaoJogos;
}

#endif