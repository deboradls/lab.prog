#include "gerenciamento_investimento.h"

// Função para converter o tipo de enumeração para string
const char* tipoParaString(TipoInvestimento tipo) {
    switch (tipo) {
        case PREFIXADO: return "Prefixado";
        case IPCA_PLUS: return "IPCA+";
        case SELIC: return "Selic";
        case CDI: return "CDI";
        default: return "Desconhecido";
    }
}

// Função para converter string para o tipo de enumeração
TipoInvestimento stringParaTipo(const char *tipo) {
    if (strcmp(tipo, "Prefixado") == 0) return PREFIXADO;
    if (strcmp(tipo, "IPCA+") == 0) return IPCA_PLUS;
    if (strcmp(tipo, "Selic") == 0) return SELIC;
    if (strcmp(tipo, "CDI") == 0) return CDI;
    return -1; // Retorna um valor inválido caso não corresponda a nenhum tipo
}

// Função para perguntar os dados financeiros
void perguntarDadosFinanceiros(DadosFinanceiros *dados) {
    printf("Informe a data de aplicação (dd/mm/aaaa): ");
    scanf("%s", dados->dataAplicacao);

    printf("Informe a data de vencimento (dd/mm/aaaa): ");
    scanf("%s", dados->dataVencimento);

    // printf("Informe o valor bruto (R$): ");
    // scanf("%f", &dados->valorBruto);

    printf("Informe o valor aplicado (R$): ");
    scanf("%f", &dados->valorAplicado);

    dados->valorBruto = dados->valorAplicado;

    printf("Informe a taxa de juros (%%): ");
    scanf("%f", &dados->taxaJuros);

    // printf("Informe o valor do imposto (R$): ");
    // scanf("%f", &dados->imposto);

    char tipo[50];
    printf("Informe o tipo de investimento (Prefixado, IPCA+, Selic, CDI): ");
    scanf(" %[^\n]s", tipo);  // Permite ler string com espaços
    dados->tipo = stringParaTipo(tipo);

    printf("Informe o nome do investimento: ");
    scanf(" %[^\n]s", dados->nome);  // Permite ler string com espaços
}

// Função para perguntar o nome do titular
void perguntarNomeTitular(Titular *titular) {
    printf("Informe o nome do titular: ");
    scanf(" %[^\n]s", titular->titular);  // Permite ler string com espaços
}

// Funções de comparação para qsort
int compararPorDataAplicacao(const void *a, const void *b) {
    DadosFinanceiros *d1 = (DadosFinanceiros *)a;
    DadosFinanceiros *d2 = (DadosFinanceiros *)b;
    return converterData(d1->dataAplicacao) - converterData(d2->dataAplicacao);
}

int compararPorValorBruto(const void *a, const void *b) {
    DadosFinanceiros *d1 = (DadosFinanceiros *)a;
    DadosFinanceiros *d2 = (DadosFinanceiros *)b;
    if (d1->valorBruto < d2->valorBruto) return -1;
    if (d1->valorBruto > d2->valorBruto) return 1;
    return 0;
}

int compararPorTipo(const void *a, const void *b) {
    DadosFinanceiros *d1 = (DadosFinanceiros *)a;
    DadosFinanceiros *d2 = (DadosFinanceiros *)b;
    return d1->tipo - d2->tipo;
}

// Função para calcular e imprimir o valor bruto total e valor líquido total
void imprimirTotais(Titular *titular) {
    float valorBrutoTotal = 0.0;
    float valorLiquidoTotal = 0.0;

    for (int i = 0; i < titular->num_investimentos; i++) {
        valorBrutoTotal += titular->investimentos[i].valorBruto;
        valorLiquidoTotal += titular->investimentos[i].valorBruto - titular->investimentos[i].imposto;
    }

    printf("\n=== Valores ===\n");
    printf("Valor Bruto Total: R$ %.2f\n", valorBrutoTotal);
    printf("Valor Líquido Total: R$ %.2f\n", valorLiquidoTotal);
}

// Função para exibir dados do titular e seus investimentos
void exibirTitular(Titular *titular) {
    printf("\n=== Nome e Investimentos do Titular ===\n");
    printf("Nome: %s\n", titular->titular);
    printf("Número de Investimentos: %d\n", titular->num_investimentos);

    for (int i = 0; i < titular->num_investimentos; i++) {
        printf("\nInvestimento %d:\n", i + 1);
        printf("Data de Aplicação: %s\n", titular->investimentos[i].dataAplicacao);
        printf("Data de Vencimento: %s\n", titular->investimentos[i].dataVencimento);
        printf("Valor Bruto: R$ %.2f\n", titular->investimentos[i].valorBruto);
        printf("Valor Aplicado: R$ %.2f\n", titular->investimentos[i].valorAplicado);
        printf("Taxa de Juros: %.2f%%\n", titular->investimentos[i].taxaJuros);
        printf("Imposto: R$ %.2f\n", titular->investimentos[i].imposto);
        printf("Tipo: %s\n", tipoParaString(titular->investimentos[i].tipo));
        printf("Nome: %s\n", titular->investimentos[i].nome);
        printf("---------------------------\n");
    }
}

// Função para inserir novos investimentos
void inserirInvestimentos(Titular *titular) {
    printf("Informe o número de novos investimentos: ");
    int novos_investimentos;
    scanf("%d", &novos_investimentos);

    titular->investimentos = realloc(titular->investimentos, (titular->num_investimentos + novos_investimentos) * sizeof(DadosFinanceiros));

    for (int i = 0; i < novos_investimentos; i++) {
        printf("\n=== Novo Investimento %d ===\n", titular->num_investimentos + 1);
        perguntarDadosFinanceiros(&titular->investimentos[titular->num_investimentos]);
        titular->num_investimentos++;
    }
}

// Função para agrupar por tipo e ordenar por data de aplicação
void agruparPorTipoOrdenar(Titular *titular) {
    // Primeiro, ordenar por tipo
    qsort(titular->investimentos, titular->num_investimentos, sizeof(DadosFinanceiros), compararPorTipo);

    // Depois, dentro de cada tipo, ordenar por data de aplicação
    int start = 0, end = 0;
    while (end < titular->num_investimentos) {
        while (end < titular->num_investimentos && titular->investimentos[start].tipo == titular->investimentos[end].tipo) {
            end++;
        }
        qsort(titular->investimentos + start, end - start, sizeof(DadosFinanceiros), compararPorDataAplicacao);
        start = end;
    }
}

// Função para converter data de dd/mm/aaaa para aaaammdd (para fins de comparação)
int converterData(const char *data) {
    int dia, mes, ano;
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);
    return ano * 10000 + mes * 100 + dia;
}