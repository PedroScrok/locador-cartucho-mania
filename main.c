
#include <stdio.h>
#include <string.h>
#include "jogos.h"
#include "cadastrosClientes.h"
#include "pdv.h"

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
                    return 9;
                case 2:
                    listar();
                    return 9;
                case 3:
                    atualizarCadastro();
                    return 9;
                case 4:
                    removerCadastroCliente();
                    return 9;
                case 5:
                    listarTodosClientes();
                    return 9;
               
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
    carregarJogosCSV();
    carregarClientesCSV();
    carregarAlugueisCSV();
    do {
        opcaoMain = menuPrincipal();

        switch (opcaoMain) {
            case 1:
                menuClientes();
                break;
            case 2:
                menuJogos();
                break;
            case 3:
                menuPDV();
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
