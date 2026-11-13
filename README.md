## Projeto  C - Sistema de aluguel de cartuchos em C.
- **Tema:** locadora de cartuchos de SNES e Mega.
- **Menu principal:** Clientes, Jogos, PDV/Aluguéis e Sair.
- **Usuários:** cadastrar, listar, atualizar, remover e voltar.
- **Jogos:** cadastrar, listar, atualizar nome/estoque/valor do aluguel, remover e voltar.
- **PDV/Aluguéis:** criar aluguel, listar, devolver, remover e voltar.
- **Um aluguel corresponde a um jogo.**
- **Cada aluguel registra o cliente, o jogo, o valor e o status.**
- **Branch:** `issue/XXXX` (exemplo atual: `issue/001`).
- **Tipo de mudança fica na mensagem do commit**, como `feat: ...`, `fix: ...` ou `docs: ...`.

## Padrão dos menus

- O menu principal mostra as três áreas e a opção Sair.
- No menu principal, `0` significa Sair.
- Em todos os submenus, usar `9` para Voltar ao menu principal.
- Depois de tratar uma opção de submenu, exibir novamente o submenu, exceto quando a pessoa escolher Voltar.
- Se a escolha não for válida, mostrar uma mensagem e exibir novamente o menu atual.
- Manter os números e a escrita das opções consistentes entre a tela, o código e os cards do Trello.
- Os módulos ainda não implementados podem mostrar uma mensagem temporária enquanto a navegação é construída.

## Padrão das operações CRUD

Aplicar o mesmo comportamento geral em Clientes e Jogos:

- **Cadastrar:** solicitar os dados do registro, validar os campos definidos pelo grupo e informar se o cadastro foi realizado.
- **Listar:** mostrar os registros cadastrados; se não houver registros, informar que a lista está vazia.
- **Atualizar:** localizar o registro escolhido, informar quando ele não existir e confirmar quais dados foram atualizados. Como sugestão, usar um identificador para localizar registros e não alterá-lo durante a atualização.
- **Remover:** localizar o registro escolhido e informar o resultado. As regras para registros relacionados a aluguéis precisam ser definidas antes de implementar a remoção.
- **Voltar:** retornar ao menu principal sem encerrar o programa.

### Regras específicas de Jogos

- A plataforma deve identificar se o cartucho é de SNES ou Mega.
- O estoque não pode ficar negativo.
- Não permitir aluguel de jogo sem unidade disponível.
- Atualizar nome, estoque ou valor sem perder os demais dados do jogo.

### Regras específicas de PDV/Aluguéis

- Cada registro de aluguel guarda os IDs do cliente e do jogo, o valor e o status.
- O aluguel começa em um status ativo; a lista mostra os registros que não foram removidos.
- Ao devolver um jogo, atualizar o status e o estoque apenas uma vez.
- Cadastrar retira uma unidade do estoque. Atualizar registra a devolução.
- Remover marca o registro como removido e devolve uma unidade ao estoque se o aluguel ainda estiver aberto.
- Os três módulos salvam os dados em CSV e carregam ao iniciar o programa.

As regras acima de estoque e integridade são padrões de funcionamento sugeridos para manter os dados coerentes; o grupo deve revisá-las antes de implementá-las.

## 5. Padrões de código para começar

- Usar nomes claros em português e sem acentos nos nomes de funções e variáveis, por exemplo `menuPrincipal` e `opcaoMenu`.
- Manter a mesma convenção de nomes em todo o código.
- Indentar o código de forma consistente (4 espaços).
- Preferir funções pequenas, cada uma com uma responsabilidade fácil de explicar.
- Evitar adicionar conceitos que ainda não foram estudados. Vamos aprender cada recurso de C quando ele for necessário.
- Por enquanto, não exigir arquivos `.h`. Quando a organização em vários arquivos for necessária, aprenderemos o papel dos `.h` antes de adotá-los.
- Conferir limites dos vetores: em C, os índices começam em zero e não podem ultrapassar o tamanho declarado.

## 6. Git e Trello

- Criar uma branch por issue no formato `issue/XXXX`, usando o número definido no card.
- Indicar o tipo da mudança na mensagem do commit (`feat`, `fix` ou `docs`), não no nome da branch.
- Cada card deve ter itens de checklist curtos, independentes e verificáveis.
- Antes de concluir um card, revisar os critérios de aceite e registrar decisões ou pendências no Trello.

## 7. Uso de IA

A IA pode ajudar a interpretar o material da disciplina, organizar requisitos, explicar conceitos, sugerir passos e revisar código. O integrante responsável implementa e entende as alterações; sugestões da IA devem ser revisadas pelo grupo antes de virarem decisões do projeto.

No README final, informar com transparência como a IA foi usada, incluir o link do Trello e descrever como compilar e executar o programa.

## 8. Decisões pendentes

- Representação da matriz de controle exigida na disciplina.
