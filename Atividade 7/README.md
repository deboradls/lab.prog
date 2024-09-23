# ATIVIDADE 7
## Questão 1
- Utilizando o modelo do Laboratório anterior, adicione os seguintes campos:
  - dataVencimento
  - taxaJuros
  - valorAplicado
  - imposto

- Modifique os campos anteriores para ajustar suas nomenclaturas:
  - dataAplicacao
  - valorBruto
  - Tipo
  - Nome

## Questão 2
Crie as seguintes funcionalidades: 
- Crie uma variável global que determine a data atual
- Crie a uma função atualizarInvestimento
  - Essa função deve receber o investimento e calcular o juros composto iniciando por dataAplicação até a dataAtual e guardar em valorBruto
    - Obs: encontre a quantidade de dias e calcule o juros diário com base no valor anual que há em taxaJuros 
  - Adicione uma funcionalidade interna que calcule o imposto com base no tempo desde a aplicação. O imposto deve ser calculado com base na quantidade de dias desde a aplicação: 
    - Até 180 dias: 22,5%
    - De 181 a 360 dias: 20%
    - De 361 a 720 dias: 17,5%
    - Acima de 720 dias: 15%

## Questão 3
- Crie uma Enum para os tipos de investimento:
  - Prefixado
  - IPCA+
  - Selic
  - CDI
- Modifique a estrutura para contemplar os valores de Enum
- Crie uma função que imprime o valor bruto total
- Crie uma função que imprime o valor líquido total

