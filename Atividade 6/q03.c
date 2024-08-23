#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da struct para a Data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Definição da struct para a Informação Financeira
typedef struct {
    Data data;       // Data da transação
    float valor;     // Valor da transação
    char tipo[20];   // Tipo da transação (ex: "Despesa", "Receita")
    char nome[50];   // Nome da transação (ex: "Aluguel", "Salário")
} InformacaoFinanceira;

// Definição da struct para o Titular
typedef struct {
    char nome[50];                    // Nome do titular
    InformacaoFinanceira transacoes[10];  // Lista de transações financeiras
    int num_transacoes;               // Número de transações registradas
} Titular;

// Função para comparar datas
int compararData(const void *a, const void *b) {
    InformacaoFinanceira *t1 = (InformacaoFinanceira *)a;
    InformacaoFinanceira *t2 = (InformacaoFinanceira *)b;
    
    if (t1->data.ano != t2->data.ano) 
        return t1->data.ano - t2->data.ano;
    if (t1->data.mes != t2->data.mes) 
        return t1->data.mes - t2->data.mes;
    return t1->data.dia - t2->data.dia;
}

// Função para comparar tipos
int compararTipo(const void *a, const void *b) {
    InformacaoFinanceira *t1 = (InformacaoFinanceira *)a;
    InformacaoFinanceira *t2 = (InformacaoFinanceira *)b;
    
    return strcmp(t1->tipo, t2->tipo);
}

// Função para comparar valores
int compararValor(const void *a, const void *b) {
    InformacaoFinanceira *t1 = (InformacaoFinanceira *)a;
    InformacaoFinanceira *t2 = (InformacaoFinanceira *)b;
    
    if (t1->valor > t2->valor) 
        return 1;
    if (t1->valor < t2->valor) 
        return -1;
    return 0;
}

// Função para exibir as transações
void exibirTransacoes(Titular titular) {
    printf("Titular: %s\n\n", titular.nome);
    
    for(int i = 0; i < titular.num_transacoes; i++) {
        InformacaoFinanceira t = titular.transacoes[i];
        printf("Transação %d:\n", i + 1);
        printf("Data: %02d/%02d/%d\n", t.data.dia, t.data.mes, t.data.ano);
        printf("Valor: R$%.2f\n", t.valor);
        printf("Tipo: %s\n", t.tipo);
        printf("Nome: %s\n\n", t.nome);
    }
}

int main() {
    // Exemplo de uso
    Titular titular;
    
    // Definindo o nome do titular
    strcpy(titular.nome, "Maria");
    
    // Inicializando o número de transações
    titular.num_transacoes = 0;
    
    // Adicionando a primeira transação
    InformacaoFinanceira transacao1;
    transacao1.data.dia = 25;
    transacao1.data.mes = 3;
    transacao1.data.ano = 2021;
    transacao1.valor = 535.20;
    strcpy(transacao1.tipo, "Tesouro Direto");
    strcpy(transacao1.nome, "Selic");
    titular.transacoes[titular.num_transacoes++] = transacao1;
    
    // Adicionando a segunda transação
    InformacaoFinanceira transacao2;
    transacao2.data.dia = 29;
    transacao2.data.mes = 3;
    transacao2.data.ano = 2021;
    transacao2.valor = 101.00;
    strcpy(transacao2.tipo, "Renda Fixa");
    strcpy(transacao2.nome, "LCA agro");
    titular.transacoes[titular.num_transacoes++] = transacao2;

    // Adicionando a terceira transação
    InformacaoFinanceira transacao3;
    transacao3.data.dia = 22;
    transacao3.data.mes = 2;
    transacao3.data.ano = 2022;
    transacao3.valor = 913.00;
    strcpy(transacao3.tipo, "Renda Fixa");
    strcpy(transacao3.nome, "CDB maj");
    titular.transacoes[titular.num_transacoes++] = transacao3;

    // Adicionando a quarta transação
    InformacaoFinanceira transacao4;
    transacao4.data.dia = 22;
    transacao4.data.mes = 8;
    transacao4.data.ano = 2022;
    transacao4.valor = 127.38;
    strcpy(transacao4.tipo, "Tesouro Direto");
    strcpy(transacao4.nome, "Prefixado");
    titular.transacoes[titular.num_transacoes++] = transacao4;

    // Perguntar ao usuário o tipo de ordenação desejado
    int opcao;
    printf("Escolha o tipo de ordenação:\n");
    printf("1 - Ordenar por Data\n");
    printf("2 - Ordenar por Tipo\n");
    printf("3 - Ordenar por Valor\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    
    // Realizar a ordenação com base na escolha do usuário
    switch(opcao) {
        case 1:
            qsort(titular.transacoes, titular.num_transacoes, sizeof(InformacaoFinanceira), compararData);
            printf("\nTransações Ordenadas por Data:\n");
            break;
        case 2:
            qsort(titular.transacoes, titular.num_transacoes, sizeof(InformacaoFinanceira), compararTipo);
            printf("\nTransações Ordenadas por Tipo:\n");
            break;
        case 3:
            qsort(titular.transacoes, titular.num_transacoes, sizeof(InformacaoFinanceira), compararValor);
            printf("\nTransações Ordenadas por Valor:\n");
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }
    
    // Exibir as transações ordenadas
    exibirTransacoes(titular);

    return 0;
}