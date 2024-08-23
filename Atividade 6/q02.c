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

int main() {
    // Exemplo de uso
    Titular titular;
    
    // Definindo o nome do titular
    strcpy(titular.nome, "Maria");
    
    // Inicializando o número de transações
    titular.num_transacoes = 0;
    
    // Adicionando uma transação
    InformacaoFinanceira transacao1;
    transacao1.data.dia = 25;
    transacao1.data.mes = 3;
    transacao1.data.ano = 2021;
    transacao1.valor = 535.20;
    strcpy(transacao1.tipo, "Tesouro Direto");
    strcpy(transacao1.nome, "Selic");
    
    titular.transacoes[titular.num_transacoes++] = transacao1;
    
    // Adicionando outra transação
    InformacaoFinanceira transacao2;
    transacao2.data.dia = 29;
    transacao2.data.mes = 03;
    transacao2.data.ano = 2021;
    transacao2.valor = 101.00;
    strcpy(transacao2.tipo, "Renda Fixa");
    strcpy(transacao2.nome, "LCA agro");
    
    titular.transacoes[titular.num_transacoes++] = transacao2;
    
    // Exibindo as informações do titular e suas transações
    printf("Titular: %s\n\n", titular.nome);
    
    for(int i = 0; i < titular.num_transacoes; i++) {
        InformacaoFinanceira t = titular.transacoes[i];
        printf("Transação %d:\n", i + 1);
        printf("Data: %02d/%02d/%d\n", t.data.dia, t.data.mes, t.data.ano);
        printf("Valor: R$%.2f\n", t.valor);
        printf("Tipo: %s\n", t.tipo);
        printf("Nome: %s\n\n", t.nome);
    }
    
    return 0;
}
