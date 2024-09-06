#include <stdio.h>
#include <string.h>
#include <math.h> // Para a função pow()

// Definição da struct para a Data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Variável global que armazena a data atual
Data dataAtual = {6, 9, 2024}; // Exemplo de data atual (06 de setembro de 2024)

// Enum para os tipos de investimento
typedef enum {
    PREFIXADO,
    IPCA_PLUS,
    SELIC,
    CDI
} TipoInvestimento;

// Função para converter o enum para string
const char* tipoInvestimentoParaString(TipoInvestimento tipo) {
    switch(tipo) {
        case PREFIXADO: return "Prefixado";
        case IPCA_PLUS: return "IPCA+";
        case SELIC: return "Selic";
        case CDI: return "CDI";
        default: return "Desconhecido";
    }
}

// Definição da struct para a Informação Financeira
typedef struct {
    Data dataAplicacao;    // Data de aplicação da transação
    Data dataVencimento;   // Data de vencimento da transação
    float valorBruto;      // Valor bruto da transação
    float valorAplicado;   // Valor inicialmente aplicado na transação
    float taxaJuros;       // Taxa de juros da transação (anual em %)
    float imposto;         // Imposto aplicado sobre a transação
    TipoInvestimento tipo; // Tipo da transação (enum)
    char nome[50];         // Nome da transação (ex: "Aluguel", "Salário")
} InformacaoFinanceira;

// Definição da struct para o Titular
typedef struct {
    char nome[50];                    // Nome do titular
    InformacaoFinanceira transacoes[10];  // Lista de transações financeiras
    int num_transacoes;               // Número de transações registradas
} Titular;

// Função para calcular a diferença em dias entre duas datas
int calcularDias(Data data1, Data data2) {
    // Convertendo as datas para o número de dias desde uma data base (01/01/0001)
    int dias1 = data1.ano * 365 + data1.dia;
    int dias2 = data2.ano * 365 + data2.dia;
    
    // Adicionando os dias dos meses
    int meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < data1.mes - 1; i++) {
        dias1 += meses[i];
    }
    for (int i = 0; i < data2.mes - 1; i++) {
        dias2 += meses[i];
    }
    
    // Ajuste para anos bissextos
    dias1 += (data1.ano / 4 - data1.ano / 100 + data1.ano / 400);
    dias2 += (data2.ano / 4 - data2.ano / 100 + data2.ano / 400);
    
    return dias2 - dias1;
}

// Função para calcular o imposto com base no número de dias
float calcularImposto(int dias) {
    if (dias <= 180) {
        return 22.5;
    } else if (dias <= 360) {
        return 20.0;
    } else if (dias <= 720) {
        return 17.5;
    } else {
        return 15.0;
    }
}

// Função para atualizar o valor bruto com base nos juros compostos e calcular o imposto
void atualizarInvestimento(InformacaoFinanceira *investimento) {
    // Calculando a quantidade de dias entre dataAplicacao e dataAtual
    int dias = calcularDias(investimento->dataAplicacao, dataAtual);
    
    // Calculando o juros diário a partir da taxa anual
    float taxaJurosDiaria = investimento->taxaJuros / 100 / 365;
    
    // Calculando o valor bruto usando a fórmula de juros compostos
    investimento->valorBruto = investimento->valorAplicado * pow(1 + taxaJurosDiaria, dias);
    
    // Calculando o imposto com base no número de dias
    float percentualImposto = calcularImposto(dias);
    investimento->imposto = investimento->valorBruto * (percentualImposto / 100);
}

// Função para imprimir o valor bruto total de todas as transações
void imprimirValorBrutoTotal(Titular titular) {
    float totalBruto = 0.0;
    for(int i = 0; i < titular.num_transacoes; i++) {
        totalBruto += titular.transacoes[i].valorBruto;
    }
    printf("Valor Bruto Total: R$%.2f\n", totalBruto);
}

// Função para imprimir o valor líquido total de todas as transações
void imprimirValorLiquidoTotal(Titular titular) {
    float totalLiquido = 0.0;
    for(int i = 0; i < titular.num_transacoes; i++) {
        float valorLiquido = titular.transacoes[i].valorBruto - titular.transacoes[i].imposto;
        totalLiquido += valorLiquido;
    }
    printf("Valor Líquido Total: R$%.2f\n", totalLiquido);
}

int main() {
    // Exibindo a data atual
    printf("Data Atual: %02d/%02d/%d\n\n", dataAtual.dia, dataAtual.mes, dataAtual.ano);

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
    transacao1.valorAplicado = 500.00;
    transacao1.taxaJuros = 7.5;
    transacao1.tipo = SELIC; // Usando o enum para tipo
    strcpy(transacao1.nome, "Selic");
    
    titular.transacoes[titular.num_transacoes++] = transacao1;
    
    // Atualizando o valor bruto e o imposto da transação
    atualizarInvestimento(&titular.transacoes[0]);
    
    // Adicionando outra transação
    InformacaoFinanceira transacao2;
    transacao2.dataAplicacao.dia = 29;
    transacao2.dataAplicacao.mes = 3;
    transacao2.dataAplicacao.ano = 2021;
    transacao2.dataVencimento.dia = 29;
    transacao2.dataVencimento.mes = 3;
    transacao2.dataVencimento.ano = 2023;
    transacao2.valorAplicado = 100.00;
    transacao2.taxaJuros = 6.0;
    transacao2.tipo = CDI; // Usando o enum para tipo
    strcpy(transacao2.nome, "LCA agro");
    
    titular.transacoes[titular.num_transacoes++] = transacao2;
    
    // Atualizando o valor bruto e o imposto da segunda transação
    atualizarInvestimento(&titular.transacoes[1]);
    
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
        printf("Tipo: %s\n", tipoInvestimentoParaString(t.tipo)); // Usando a função para converter enum para string
        printf("Nome: %s\n\n", t.nome);
    }
    
    // Exibindo os totais
    imprimirValorBrutoTotal(titular);
    imprimirValorLiquidoTotal(titular);
    
    return 0;
}
