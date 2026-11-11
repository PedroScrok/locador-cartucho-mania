// MODULO 1: CLIENTES
// Autor: Pedro Scrok Bernardo - RGM 47153695

#ifndef CLIENTES_H
#define CLIENTES_H

#include <stdio.h>


#define MAX_CLIENTES 50

// Struct com as informacoes de cada cliente
struct dadosClientes{
    int idCliente;
    char nomeCliente[50];
    int idade;
    char telefone[15]; // char pois int nao aceita 11 digitos
    char cpf[12];      // char pois int nao aceita 11 digitos
    float saldo;
    int ativo;         // 1 = ativo, 0 = removido
};


struct dadosClientes clientes[MAX_CLIENTES];
int totalClientes = 0;

// Autor: Pedro Scrok Bernardo
// Grava todos os clientes no arquivo clientes.csv (uma linha por cliente)
void salvarClientesCSV(){
    FILE *arquivo = fopen("clientes.csv", "w");
    if(arquivo == NULL){
        printf("Erro: nao foi possivel abrir clientes.csv para gravar.\n");
        return;
    }

    for(int i = 0; i < totalClientes; i++){
        fprintf(arquivo, "%d;%s;%d;%s;%s;%.2f;%d\n",
                clientes[i].idCliente,
                clientes[i].nomeCliente,
                clientes[i].idade,
                clientes[i].telefone,
                clientes[i].cpf,
                clientes[i].saldo,
                clientes[i].ativo);
    }

    fclose(arquivo);
}

// Autor: Pedro Scrok Bernardo
// Le o arquivo clientes.csv e coloca os clientes de volta no vetor
void carregarClientesCSV(){
    FILE *arquivo = fopen("clientes.csv", "r");
    if(arquivo == NULL){
        return; // primeira vez: o arquivo ainda nao existe
    }

    totalClientes = 0;
    while(totalClientes < MAX_CLIENTES &&
          fscanf(arquivo, "%d;%49[^;];%d;%14[^;];%11[^;];%f;%d\n",
                 &clientes[totalClientes].idCliente,
                 clientes[totalClientes].nomeCliente,
                 &clientes[totalClientes].idade,
                 clientes[totalClientes].telefone,
                 clientes[totalClientes].cpf,
                 &clientes[totalClientes].saldo,
                 &clientes[totalClientes].ativo) == 7){
        totalClientes++;
    }

    fclose(arquivo);
}

// Autor: Pedro Scrok Bernardo
void cadastrando(){

    if(totalClientes >= MAX_CLIENTES){
        printf("Numero maximo de clientes atingido!\n");
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

    clientes[totalClientes].idCliente = totalClientes + 1;
    clientes[totalClientes].ativo = 1;

    totalClientes++;
    salvarClientesCSV();

    printf("Cliente cadastrado!\n");
}

// Autor: Pedro Scrok Bernardo
void listar(){
    int escolha;
    printf("Qual ID do cliente que deseja saber as informacoes: \n");
    scanf("%d", &escolha);
    if(escolha < 1 || escolha > totalClientes){
        printf("O ID informado nao eh valido.\n");
        return;
    }

    escolha = escolha - 1; // ID 1 fica na posicao 0 do vetor

    if(clientes[escolha].ativo == 0){
        printf("O ID do cliente solicitado foi removido\n");
        return;
    }

    printf("ID: %d\n", clientes[escolha].idCliente);
    printf("NOME: %s\n", clientes[escolha].nomeCliente);
    printf("IDADE: %d\n", clientes[escolha].idade);
    printf("TELEFONE: %s\n", clientes[escolha].telefone);
    printf("CPF: %s\n", clientes[escolha].cpf);
}

// Autor: Pedro Scrok Bernardo
void atualizarCadastro(){
    int escolha;
    printf("Qual ID do cliente que deseja alterar as informacoes: \n");
    scanf("%d", &escolha);
    if(escolha < 1 || escolha > totalClientes){
        printf("O ID informado nao eh valido.\n");
        return;
    }

    escolha = escolha - 1;

    if(clientes[escolha].ativo == 0){
        printf("O ID do cliente solicitado foi removido\n");
        return;
    }

    printf("Esses sao os dados do cliente solicitado: \n");
    printf("ID: %d\n", clientes[escolha].idCliente);
    printf("NOME: %s\n", clientes[escolha].nomeCliente);
    printf("IDADE: %d\n", clientes[escolha].idade);
    printf("TELEFONE: %s\n", clientes[escolha].telefone);
    printf("CPF: %s\n", clientes[escolha].cpf);

    printf("NOVO NOME: \n");
    scanf(" %49[^\n]", clientes[escolha].nomeCliente);
    printf("NOVA IDADE: \n");
    scanf("%d", &clientes[escolha].idade);
    printf("NOVO TELEFONE: \n");
    scanf(" %14s", clientes[escolha].telefone);
    printf("NOVO CPF: \n");
    scanf(" %11s", clientes[escolha].cpf);

    salvarClientesCSV();
    printf("Dados do cliente alterado com sucesso!\n");
}

// Autor: Pedro Scrok Bernardo
void removerCadastroCliente(){
    int escolha;
    int confirmacao;
    printf("Qual ID do cliente que deseja remover o cadastro? \n");
    scanf("%d", &escolha);
    if(escolha < 1 || escolha > totalClientes){
        printf("O ID informado nao eh valido!\n");
        return;
    }

    escolha = escolha - 1;

    if(clientes[escolha].ativo == 0){
        printf("O ID do cliente solicitado ja foi removido\n");
        return;
    }

    printf("Esses sao os dados do cliente solicitado: \n");
    printf("ID: %d\n", clientes[escolha].idCliente);
    printf("NOME: %s\n", clientes[escolha].nomeCliente);
    printf("IDADE: %d\n", clientes[escolha].idade);
    printf("TELEFONE: %s\n", clientes[escolha].telefone);
    printf("CPF: %s\n", clientes[escolha].cpf);

    printf("Deseja mesmo remover este cliente?\n");
    printf("[1] REMOVER [0] NAO REMOVER\n");
    scanf("%d", &confirmacao);

    if(confirmacao != 0 && confirmacao != 1){
        printf("Opcao invalida!\n");
        return;
    } else if(confirmacao == 0){
        printf("Cliente NAO REMOVIDO!\n");
    } else if(confirmacao == 1){
        clientes[escolha].ativo = 0;
        salvarClientesCSV();
        printf("Cliente REMOVIDO\n");
    }
}

// Autor: Pedro Scrok Bernardo
void listarTodosClientes(){
    int i;
    int encontrados = 0;

    printf("===== CLIENTES CADASTRADOS =====\n");

    for(i = 0; i < totalClientes; i++){
        if(clientes[i].ativo == 1){
            printf("ID: %d | NOME: %s | IDADE: %d | TEL: %s | CPF: %s\n",
                   clientes[i].idCliente, clientes[i].nomeCliente, clientes[i].idade,
                   clientes[i].telefone, clientes[i].cpf);
            encontrados++;
        }
    }

    if(encontrados == 0){
        printf("Nenhum cliente cadastrado.\n");
    }
}

#endif