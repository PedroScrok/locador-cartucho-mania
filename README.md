## Projeto  C - Sistema de aluguel de cartuchos em C.
- **Tema:** locadora de cartuchos de SNES e Mega.
- **Menu principal:** Usuários, Jogos, Funcionários, PDV/Aluguéis e Sair.
- **Usuários:** cadastrar, listar, atualizar, remover e voltar.
- **Jogos:** cadastrar, listar, atualizar nome/estoque/valor do aluguel, remover e voltar.
- **Funcionários:** cadastrar, listar, atualizar, remover e voltar.
- **PDV/Aluguéis:** criar aluguel, listar por status, atualizar status, remover e voltar.
- **Um aluguel corresponde a um jogo.**
- **Cada aluguel registra o funcionário que realizou a operação.**
- **Branch:** `issue/XXXX` (exemplo atual: `issue/001`).
- **Tipo de mudança fica na mensagem do commit**, como `feat: ...`, `fix: ...` ou `docs: ...`.

## Padrão dos menus

- O menu principal mostra as quatro áreas e a opção Sair.
- No menu principal, `0` significa Sair.
- Em todos os submenus, usar `9` para Voltar ao menu principal.
- Depois de tratar uma opção de submenu, exibir novamente o submenu, exceto quando a pessoa escolher Voltar.
- Se a escolha não for válida, mostrar uma mensagem e exibir novamente o menu atual.
- Manter os números e a escrita das opções consistentes entre a tela, o código e os cards do Trello.
- Os módulos ainda não implementados podem mostrar uma mensagem temporária enquanto a navegação é construída.

## Padrão das operações CRUD

Aplicar o mesmo comportamento geral em Usuários, Jogos e Funcionários:

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

- Cada registro de aluguel se refere a um usuário, um jogo e o funcionário que fez a operação.
- O aluguel começa em um status ativo; a lista deve permitir consultar aluguéis por status.
- Ao devolver um jogo, atualizar o status e o estoque apenas uma vez.
- O grupo ainda precisa decidir se Remover apaga o aluguel ou registra um cancelamento, preservando o histórico.

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

- Campos de cadastro de Usuários e Funcionários.
- Dados que serão armazenados no aluguel, além de usuário, jogo, funcionário e status.
- Representação da matriz de controle exigida na disciplina.
- Regras de remoção para registros ligados ao histórico de aluguéis.
- Como conciliar os quatro módulos funcionais com as quatro responsabilidades técnicas descritas no material da disciplina.
- Os dados ficam em memória conforme o exercício da disciplina; assim, são perdidos ao fechar o programa. Salvar em arquivo pode ser avaliado como melhoria, se couber no escopo e nas regras da disciplina.
