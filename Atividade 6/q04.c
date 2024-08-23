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

// Função para comparar tipos
int compararTipo(const void *a, const void *b) {
    InformacaoFinanceira *t1 = (InformacaoFinanceira *)a;
    InformacaoFinanceira *t2 = (InformacaoFinanceira *)b;
    
    return strcmp(t1->tipo, t2->tipo);
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

// Função para ordenar e agrupar as transações
void agruparEOrdenar(Titular *titular, int opcao) {
    // Ordenar primeiro por tipo para agrupar
    qsort(titular->transacoes, titular->num_transacoes, sizeof(InformacaoFinanceira), compararTipo);
    
    // Agrupamento e ordenação dentro dos grupos
    int inicioGrupo = 0;
    
    while (inicioGrupo < titular->num_transacoes) {
        int fimGrupo = inicioGrupo;
        
        // Encontrar o final do grupo atual (mesmo tipo)
        while (fimGrupo < titular->num_transacoes && strcmp(titular->transacoes[inicioGrupo].tipo, titular->transacoes[fimGrupo].tipo) == 0) {
            fimGrupo++;
        }
        
        // Ordenar o grupo por valor ou data
        if (opcao == 1) {
            qsort(&titular->transacoes[inicioGrupo], fimGrupo - inicioGrupo, sizeof(InformacaoFinanceira), compararValor);
        } else if (opcao == 2) {
            qsort(&titular->transacoes[inicioGrupo], fimGrupo - inicioGrupo, sizeof(InformacaoFinanceira), compararData);
        }
        
        inicioGrupo = fimGrupo;
    }
}

int main() {
    // Exemplo de uso
    Titular titular;
    
    // Definindo o nome do titular
    strcpy(titular.nome, "Maria");
    
    // Inicializando o número de transações
    titular.num_transacoes = 0;
    
    // Adicionando as transações fornecidas
    InformacaoFinanceira transacao1 = {{25, 3, 2021}, 535.20, "Tesouro Direto", "Selic"};
    titular.transacoes[titular.num_transacoes++] = transacao1;
    
    InformacaoFinanceira transacao2 = {{29, 3, 2021}, 101.00, "Renda Fixa", "LCA agro"};
    titular.transacoes[titular.num_transacoes++] = transacao2;
    
    InformacaoFinanceira transacao3 = {{22, 2, 2022}, 913.00, "Renda Fixa", "CDB maj"};
    titular.transacoes[titular.num_transacoes++] = transacao3;
    
    InformacaoFinanceira transacao4 = {{22, 8, 2022}, 127.38, "Tesouro Direto", "Prefixado"};
    titular.transacoes[titular.num_transacoes++] = transacao4;

    // Perguntar ao usuário o tipo de agrupamento e ordenação desejado
    int opcao;
    printf("Escolha o tipo de ordenação dentro do agrupamento por Tipo:\n");
    printf("1 - Ordenar por Valor dentro de cada Tipo\n");
    printf("2 - Ordenar por Data dentro de cada Tipo\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    
    // Agrupar por tipo e ordenar de acordo com a escolha
    if (opcao == 1 || opcao == 2) {
        agruparEOrdenar(&titular, opcao);
        printf("\nTransações Agrupadas por Tipo e Ordenadas:\n");
        exibirTransacoes(titular);
    } else {
        printf("Opção inválida!\n");
    }

    return 0;
}
