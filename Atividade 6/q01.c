#include <stdio.h>
#include <string.h>

// Definição da struct para a Data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Definição da struct para a Informação Financeira
typedef struct {
    Data data;       // ata da transação
    float valor;     // Valor da transação
    char tipo[20];   // Tipo da transação (ex: "Despesa", "Receita")
    char nome[50];   // Nome da transação (ex: "Aluguel", "Salário")
} InformacaoFinanceira;

int main() {
    // Exemplo de uso
    InformacaoFinanceira transacao;
    
    // Definindo a data
    transacao.data.dia = 25;
    transacao.data.mes = 03;
    transacao.data.ano = 2021;
    
    // Definindo o valor
    transacao.valor = 535.20;
    
    // Definindo o tipo da transação
    strcpy(transacao.tipo, "Tesouro Direto");
    
    // Definindo o nome da transação
    strcpy(transacao.nome, "Selic");

    // Exibindo as informações da transação
    printf("Data: %02d/%02d/%d\n", transacao.data.dia, transacao.data.mes, transacao.data.ano);
    printf("Valor: R$%.2f\n", transacao.valor);
    printf("Tipo: %s\n", transacao.tipo);
    printf("Nome: %s\n", transacao.nome);
    
    return 0;
}