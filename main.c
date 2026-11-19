
#include <stdio.h>
#include <stdlib.h>  // system, usado no limparTela
#include <string.h>
#include <locale.h>  // setlocale
#include "jogos.h"
#include "cadastrosClientes.h"
#include "pdv.h"

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
// Limpa o terminal: "cls" no Windows e "clear" no Linux/Mac
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
int menuPrincipal() {
    int opcaoPrincipal = 0;
    int resultadoLeitura = 0;

    printf("\n========== Locadora Cartucho Mania ==========\n");
    printf("[1] - Modulo clientes\n");
    printf("[2] - Modulo jogos\n");
    printf("[3] - PDV / alugueis\n");
    printf("[0] - Sair\n");
    printf("Opcao desejada: ");

    resultadoLeitura = scanf("%d", &opcaoPrincipal);

    if (resultadoLeitura != 1) {
        int caractere;
        while ((caractere = getchar()) != '\n' && caractere != EOF) {
        }
        return -1;
    }

    return opcaoPrincipal;
}



// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
int menuClientes() {
    int opcaoClientes = 0;

    do {
        printf("\n========== Locadora Cartucho Mania - Clientes ==========\n");
        printf("[1] - Cadastrar cliente\n");
        printf("[2] - Listar cadastros de clientes\n");
        printf("[3] - Atualizar cadastro de cliente\n");
        printf("[4] - Remover cadastro de cliente\n");
        printf("[5] - Listar todos os clientes\n");
        printf("[9] - Voltar ao menu principal\n");
        printf("Opcao desejada: ");

        if (scanf("%d", &opcaoClientes) != 1) {
            int caractere;
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
            }
            printf("Erro: Entrada invalida, digite um numero.\n");
            opcaoClientes = -1;
            continue;
        }

        switch (opcaoClientes) {
            case 1:
                cadastrando();
                break;
            case 2:
                listar();
                break;
            case 3:
                atualizarCadastro();
                break;
            case 4:
                removerCadastroCliente();
                break;
            case 5:
                listarTodosClientes();
                break;
            case 9:
                break;
            default:
                printf("Erro: Opcao invalida.\n");
        }

    } while (opcaoClientes != 9);

    return opcaoClientes;
}


// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
int menuPDV() {
    int opcaoPDV = 0;

    do {
        printf("\n========== Locadora Cartucho Mania - PDV ==========\n");
        printf("[1] - Cadastrar registro de aluguel\n");
        printf("[2] - Listar registros de alugueis\n");
        printf("[3] - Atualizar registro de aluguel (devolucao)\n");
        printf("[4] - Remover registro de aluguel\n");
        printf("[5] - Relatorio de faturamento\n");
        printf("[6] - Matriz: alugueis por plataforma e status\n");
        printf("[7] - Ranking dos jogos mais alugados\n");
        printf("[9] - Voltar ao menu principal\n");
        printf("Opcao desejada: ");

        if (scanf("%d", &opcaoPDV) != 1) {
            int caractere;
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
            }
            printf("Erro: Entrada invalida, digite um numero.\n");
            opcaoPDV = -1;
            continue;
        }

        switch (opcaoPDV) {
            case 1:
                cadastrarAluguel();
                break;
            case 2:
                listarAlugueis();
                break;
            case 3:
                atualizarAluguel();
                break;
            case 4:
                removerAluguel();
                break;
            case 5:
                relatorioFaturamento();
                break;
            case 6:
                relatorioMatrizPlataforma();
                break;
            case 7:
                relatorioRankingJogos();
                break;
            case 9:
                break;
            default:
                printf("Erro: Opcao invalida.\n");
        }

    } while (opcaoPDV != 9);

    return opcaoPDV;
}

// Autor: Pedro Henrique Pereira Dallavale - RGM 48123170
int main() {
    int opcaoMain;
    setlocale(LC_CTYPE, "Portuguese");
    carregarJogosCSV();
    carregarClientesCSV();
    carregarAlugueisCSV();
    limparTela();
    do {
        opcaoMain = menuPrincipal();

        switch (opcaoMain) {
            case 1:
                limparTela();
                menuClientes();
                limparTela();
                break;
            case 2:
                limparTela();
                menuJogos();
                limparTela();
                break;
            case 3:
                limparTela();
                menuPDV();
                limparTela();
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            case -1:
                printf("Erro: Entrada invalida, digite um numero.\n");
                break;
            default:
                printf("Erro: Opcao invalida.\n");
        }

    } while (opcaoMain != 0);

    return 0;
}
