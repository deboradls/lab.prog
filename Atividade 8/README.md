# ATIVIDADE 8
## Questão 1
- Organizem o código dos laboratórios anteriores para refletir em um projeto organizado dentro de uma pasta
- Separem um arquivo para cada uma das funcionalidades:
    - Cálculo de investimento (Atualizar investimento, Juros…)
    - Gerenciamento de investimento (adicionar, excluir, atualizar)
    - Arquivo principal (Menu, acesso a todas as funcionalidades)

## Questão 2
- Crie arquivos de cabeçalho e mova as declarações respectivas para cada arquivo:
  - Define condicional do próprio arquivo (Guarda de Inclusão)
  - Declarações de struct, enum
  - Declarações de funções
  - Definições de macros (caso hajam)
- Crie o makefile do projeto

## Questão 3
- Utilizando a função atualizarInvestimento:
  - Para calcular o juros agora ela deverá lidar com rendimentos que variam a cada mês
    - Exemplo: se o tipo de investimento for IPCA, para cada mês existe uma taxa de juros diferente (dica: utilizem ponteiros para função para atualizar o investimento)
    - Dessa forma, vocês devem criar uma função:
      - Que calcula a quantidade de meses entre hoje e a data da aplicação;
      - Acessa um vetor que tenha o juros referente a cada mês desde a data da aplicação;
      - Calcula o iterativamente até chegar ao mês atual.