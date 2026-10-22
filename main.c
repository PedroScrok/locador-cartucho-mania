#include <stdio.h>

int menuPrincipal () {
    int opcaoPrincipal = 0;
    printf("========== Locadora Cartucho Mania ==========\n");
    printf("[1] - Modulo usuarios\n");
    printf("[2] - Modulo jogos\n");
    printf("[3] - PDV\n");
    printf("[0] - Sair\n");
    scanf("%d", &opcaoPrincipal);
  
    return opcaoPrincipal;
};
int menuCadastros () {
    int opcaoCadastros = 0;
    printf("========== Locadora Cartucho Mania - Cadastros ==========\n");
    printf("[1] - Cadastrar cliente\n");
    printf("[2] - Listar cadastros de clientes\n");
    printf("[3] - Atualizar cadastro de cliente\n");
    printf("[4] - Remover cadastro\n");
    printf("[9] - Voltar ao menu principal\n");
    printf("Opcao desejada: ");
    scanf("%d", &opcaoCadastros);

    return opcaoCadastros;
};
int main() {
    int opcaoMain;

    do
    {
        opcaoMain = menuPrincipal();
        switch (opcaoMain)
        {
        case 1:
            menuCadastros();
            break;
        
        default:
            break;
        }
    } while (opcaoMain != 0);
    
}