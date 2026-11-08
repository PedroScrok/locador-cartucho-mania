
#include <stdio.h>

int menuPrincipal() {
    int opcaoPrincipal = 0;
    int resultadoLeitura = 0;

    printf("\n========== Locadora Cartucho Mania ==========\n");
    printf("[1] - Modulo clientes\n");
    printf("[2] - Modulo jogos\n");
    printf("[3] - Modulo funcionarios\n");
    printf("[4] - PDV / alugueis\n");
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

int menuClientes() {
    int opcaoClientes = 0;

    do {
        printf("\n========== Locadora Cartucho Mania - Clientes ==========\n");
        printf("[1] - Cadastrar cliente\n");
        printf("[2] - Listar cadastros de clientes\n");
        printf("[3] - Atualizar cadastro de cliente\n");
        printf("[4] - Remover cadastro de cliente\n");
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
            case 2:
            case 3:
            case 4:
                printf("Funcionalidade ainda nao implementada.\n");
                break;
            case 9:
                break;
            default:
                printf("Erro: Opcao invalida.\n");
        }

    } while (opcaoClientes != 9);

    return opcaoClientes;
}

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

struct Jogo listaJogos[50];
int totalJogos = 0;

// ---- Autor: Eduardo Piana Passos da Silva - RGM 48545015 ---
// Descarta tudo o que sobrou digitado no teclado ate o "Enter"
// Usar quando um scanf de numero falhar (no caso da pessoa digitar letra)

void limparEntradaJogo() {   
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF) {
    }
}

// Autor: Eduardo Piana Passos da Silva - RGM 48545015
void cadastrarJogo() {
    printf("\n========== Cadastrar Jogo ==========\n");
    if (totalJogos >= 50) {
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
            estoque = -1; //se a pessoa digitou letra, com -1 no próximo if ele mostra o erro e depois repete a pergunta 
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
}

int menuJogos() {
    int opcaoJogos = 0;

    do {
        printf("\n========== Locadora Cartucho Mania - Jogos ==========\n");
        printf("[1] - Cadastrar jogo\n");
        printf("[2] - Listar cadastros de jogos\n");
        printf("[3] - Atualizar cadastro do jogo\n");
        printf("[4] - Remover cadastro do jogo\n");
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
            case 3:
            case 4:
                printf("Funcionalidade ainda nao implementada.\n");
                break;
            case 9:
                break;
            default:
                printf("Erro: Opcao invalida.\n");
        }

    } while (opcaoJogos != 9);

    return opcaoJogos;
}

int menuFuncionarios() {
    int opcaoFuncionarios = 0;

    do {
        printf("\n========== Locadora Cartucho Mania - Funcionarios ==========\n");
        printf("[1] - Cadastrar funcionario\n");
        printf("[2] - Listar cadastro de funcionarios\n");
        printf("[3] - Atualizar cadastro de funcionarios\n");
        printf("[4] - Remover cadastro de funcionario\n");
        printf("[9] - Voltar ao menu principal\n");
        printf("Opcao desejada: ");

        if (scanf("%d", &opcaoFuncionarios) != 1) {
            int caractere;
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
            }
            printf("Erro: Entrada invalida, digite um numero.\n");
            opcaoFuncionarios = -1;
            continue;
        }

        switch (opcaoFuncionarios) {
            case 1:
            case 2:
            case 3:
            case 4:
                printf("Funcionalidade ainda nao implementada.\n");
                break;
            case 9:
                break;
            default:
                printf("Erro: Opcao invalida.\n");
        }

    } while (opcaoFuncionarios != 9);

    return opcaoFuncionarios;
}

int menuPDV() {
    int opcaoPDV = 0;

    do {
        printf("\n========== Locadora Cartucho Mania - PDV ==========\n");
        printf("[1] - Cadastrar registro de aluguel\n");
        printf("[2] - Listar registros de alugueis\n");
        printf("[3] - Atualizar registro de aluguel\n");
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
            case 2:
            case 3:
            case 4:
                printf("Funcionalidade ainda nao implementada.\n");
                break;
            case 9:
                break;
            default:
                printf("Erro: Opcao invalida.\n");
        }

    } while (opcaoPDV != 9);

    return opcaoPDV;
}

int main() {
    int opcaoMain;

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
                menuFuncionarios();
                break;
            case 4:
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
