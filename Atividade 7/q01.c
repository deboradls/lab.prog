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
    Data dataAplicacao;    // Data de aplicação da transação
    Data dataVencimento;   // Data de vencimento da transação
    float valorBruto;      // Valor bruto da transação
    float valorAplicado;   // Valor inicialmente aplicado na transação
    float taxaJuros;       // Taxa de juros da transação
    float imposto;         // Imposto aplicado sobre a transação
    char tipo[20];         // Tipo da transação (ex: "Despesa", "Receita")
    char nome[50];         // Nome da transação (ex: "Aluguel", "Salário")
} InformacaoFinanceira;

// Definição da struct para o Titular
typedef struct {
    char nome[50];                    // Nome do titular
    InformacaoFinanceira transacoes[10];  // Lista de transações financeiras
    int num_transacoes;               // Número de transações registradas
} Titular;

int main() {
    // Exemplo de uso
    Titular titular;
    
    // Definindo o nome do titular
    strcpy(titular.nome, "Maria");
    
    // Inicializando o número de transações
    titular.num_transacoes = 0;
    
    // Adicionando uma transação
    InformacaoFinanceira transacao1;
    transacao1.dataAplicacao.dia = 25;
    transacao1.dataAplicacao.mes = 3;
    transacao1.dataAplicacao.ano = 2021;
    transacao1.dataVencimento.dia = 25;
    transacao1.dataVencimento.mes = 3;
    transacao1.dataVencimento.ano = 2022;
    transacao1.valorBruto = 535.20;
    transacao1.valorAplicado = 500.00;
    transacao1.taxaJuros = 7.5;
    transacao1.imposto = 35.20;
    strcpy(transacao1.tipo, "Tesouro Direto");
    strcpy(transacao1.nome, "Selic");
    
    titular.transacoes[titular.num_transacoes++] = transacao1;
    
    // Adicionando outra transação
    InformacaoFinanceira transacao2;
    transacao2.dataAplicacao.dia = 29;
    transacao2.dataAplicacao.mes = 3;
    transacao2.dataAplicacao.ano = 2021;
    transacao2.dataVencimento.dia = 29;
    transacao2.dataVencimento.mes = 3;
    transacao2.dataVencimento.ano = 2023;
    transacao2.valorBruto = 101.00;
    transacao2.valorAplicado = 100.00;
    transacao2.taxaJuros = 6.0;
    transacao2.imposto = 1.00;
    strcpy(transacao2.tipo, "Renda Fixa");
    strcpy(transacao2.nome, "LCA agro");
    
    titular.transacoes[titular.num_transacoes++] = transacao2;
    
    // Exibindo as informações do titular e suas transações
    printf("Titular: %s\n\n", titular.nome);
    
    for(int i = 0; i < titular.num_transacoes; i++) {
        InformacaoFinanceira t = titular.transacoes[i];
        printf("Transação %d:\n", i + 1);
        printf("Data de Aplicação: %02d/%02d/%d\n", t.dataAplicacao.dia, t.dataAplicacao.mes, t.dataAplicacao.ano);
        printf("Data de Vencimento: %02d/%02d/%d\n", t.dataVencimento.dia, t.dataVencimento.mes, t.dataVencimento.ano);
        printf("Valor Aplicado: R$%.2f\n", t.valorAplicado);
        printf("Taxa de Juros: %.2f%%\n", t.taxaJuros);
        printf("Imposto: R$%.2f\n", t.imposto);
        printf("Valor Bruto: R$%.2f\n", t.valorBruto);
        printf("Tipo: %s\n", t.tipo);
        printf("Nome: %s\n\n", t.nome);
    }
    
    return 0;
}
