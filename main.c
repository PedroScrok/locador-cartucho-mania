
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

//MODULO 1 CLIENTES: 
//Autor: Pedro Scrok Bernardo RGM:47153695

    #define MAX_CLIENTES 50

    struct dadosClientes{
        int idCliente;
        char nomeCliente[50];
        int idade;
        char telefone[15]; //OBS: definidass como char pois não aceita int com 11 digitos;
        char cpf[12];
        float saldo;

    };

struct dadosClientes clientes[MAX_CLIENTES];
int totalClientes = 0;

void cadastrando(){

    if(totalClientes >= MAX_CLIENTES){
        printf("Numero de máximo de clientes atingido! \n");
        return;
    }
        
    printf("Qual nome: \n");
    scanf(" %49[^\n]", clientes[totalClientes].nomeCliente);
    printf("Qual idade: \n");
    scanf("%d", &clientes[totalClientes].idade);
    printf("Qual telefone: \n");
    scanf(" %14s", clientes[totalClientes].telefone);
    printf("Qual CPF: \n");
    scanf(" %11s", clientes[totalClientes].cpf);

    clientes[totalClientes].idCliente = totalClientes +1;

    totalClientes ++;

    printf("Cliente cadastrado! \n");

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
                cadastrando();
                return 9;
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
