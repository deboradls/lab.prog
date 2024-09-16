#ifndef GERENCIAMENTO_INVESTIMENTO_H
#define GERENCIAMENTO_INVESTIMENTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variável global para armazenar a data atual no formato: dd/mm/aaaa
extern char dataAtual[11];

// Enumeração para os tipos de investimento
typedef enum {
    PREFIXADO,
    IPCA_PLUS,
    SELIC,
    CDI
} TipoInvestimento;

// Definição da estrutura para os dados financeiros
typedef struct {
    char dataAplicacao[11];
    char dataVencimento[11];
    float valorBruto;
    float valorAplicado;
    float taxaJuros;
    float imposto;
    TipoInvestimento tipo;
    char nome[50];
} DadosFinanceiros;

// Definição da estrutura para o titular
typedef struct {
    char titular[50];
    int num_investimentos;
    DadosFinanceiros *investimentos;
} Titular;

// Função para converter o tipo de enumeração para string
const char* tipoParaString(TipoInvestimento tipo);

// Função para converter string para o tipo de enumeração
TipoInvestimento stringParaTipo(const char *tipo);

// Função para perguntar os dados financeiros
void perguntarDadosFinanceiros(DadosFinanceiros *dados);

// Função para perguntar o nome do titular
void perguntarNomeTitular(Titular *titular);

// Funções de comparação para qsort
int compararPorDataAplicacao(const void *a, const void *b);

int compararPorValorBruto(const void *a, const void *b);

int compararPorTipo(const void *a, const void *b);

// Função para calcular e imprimir o valor bruto total e valor líquido total
void imprimirTotais(Titular *titular);

// Função para exibir dados do titular e seus investimentos
void exibirTitular(Titular *titular);

// Função para inserir novos investimentos
void inserirInvestimentos(Titular *titular);

// Função para agrupar por tipo e ordenar por data de aplicação
void agruparPorTipoOrdenar(Titular *titular);

// Função para converter data de dd/mm/aaaa para aaaammdd (para fins de comparação)
int converterData(const char *data);

#endif