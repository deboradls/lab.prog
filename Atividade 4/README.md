# Questões

## Questão 01
- Implemente um menu interativo na qual o usuário pode selecionar números para ir para trechos específicos do programa
 - Ex:
    - Se o usuário digitar 1 vá para uma calculadora de soma
    - Se o usuário digitar 2 vá para uma calculadora de subtração
    - Se o usuário digitar 3 vá para uma calculadora de multiplicação
    - Se o usuário digitar 4 vá para uma calculadora de divisão
    - Se o usuário digitar 5 vá para uma calculadora de resto

## Questão 02
- Implemente um gerador de senha de guichê
- Toda vez que a função for executada vocês devem gerar 10 senhas para clientes e devem possuir rotulação.
- Percorra as senhas uma a uma e rotule como prioridade ou normal
- A rotulação deve ter 67%  de ocorrer normal e 33% de ocorrer prioridade.
- Mostre que o gerador é capaz de gerar números de formas assimétricas (contador).

## Questão 03
- Implemente o consumidor de senhas geradas
- Toda vez que o consumidor é executado ele consome uma senha. Mas deve alternar em cada chamada, se na ultima ele chamou prioridade, deve chamar uma senha normal, e vice-versa. Caso uma das senhas esteja esgotada deve chamar outra.
- O programa deve mostrar se está chamando prioridade ou normal
- Una todos em um único menu:
    - 1 para gerar 10 senhas
    - 2 para consumir
    - 3 para mostrar as senhas restantes