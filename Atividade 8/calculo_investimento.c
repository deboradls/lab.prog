#include "calculo_investimento.h"

// Função para calcular o imposto baseado na quantidade de dias desde a aplicação
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

// Função para calcular a diferença de dias entre duas datas
int calcularDiferencaDias(const char *dataInicial, const char *dataFinal) {
    struct tm tm_inicial, tm_final;

    // Converte a dataInicial para struct tm
    sscanf(dataInicial, "%d/%d/%d", &tm_inicial.tm_mday, &tm_inicial.tm_mon, &tm_inicial.tm_year);
    tm_inicial.tm_mon -= 1;   // struct tm usa meses de 0 a 11
    tm_inicial.tm_year -= 1900; // struct tm usa anos desde 1900

    // Converte a dataFinal para struct tm
    sscanf(dataFinal, "%d/%d/%d", &tm_final.tm_mday, &tm_final.tm_mon, &tm_final.tm_year);
    tm_final.tm_mon -= 1;   // struct tm usa meses de 0 a 11
    tm_final.tm_year -= 1900; // struct tm usa anos desde 1900

    // Converte para time_t (segundos desde o Epoch)
    time_t time_inicial = mktime(&tm_inicial);
    time_t time_final = mktime(&tm_final);

    // Calcula a diferença em dias
    double diferencaSegundos = difftime(time_final, time_inicial);
    int diferencaDias = diferencaSegundos / (60 * 60 * 24);  // Converte de segundos para dias

    return diferencaDias;
}

// Função para calcular juros compostos e atualizar o valor bruto e imposto
void atualizarInvestimento(DadosFinanceiros *dados) {
    // Calcula a diferença de dias entre a data de aplicação e a data atual
    int dias = calcularDiferencaDias(dados->dataAplicacao, dataAtual);

    // Converte a taxa de juros anual para diária
    float taxaJurosDiaria = dados->taxaJuros / 365;

    // Calcula o valor bruto aplicando juros compostos
    dados->valorBruto = dados->valorAplicado * pow(1 + (taxaJurosDiaria / 100), dias);

    // Calcula o imposto com base na quantidade de dias
    float percentualImposto = calcularImposto(dias);
    dados->imposto = dados->valorBruto * (percentualImposto / 100);

    // Exibe os resultados da atualização
    printf("\n=== Investimento Atualizado ===\n");
    printf("Data de Aplicação: %s\n", dados->dataAplicacao);
    printf("Dias desde aplicação: %d\n", dias);
    printf("Valor Bruto atualizado: R$ %.2f\n", dados->valorBruto);
    printf("Imposto calculado (%.1f%%): R$ %.2f\n", percentualImposto, dados->imposto);
}
