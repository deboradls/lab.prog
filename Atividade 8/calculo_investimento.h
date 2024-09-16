#ifndef CALCULO_INVESTIMENTO_H
#define CALCULO_INVESTIMENTO_H

#include <stdio.h>
#include <time.h>
#include <math.h>

#include "gerenciamento_investimento.h"

// Função para calcular o imposto baseado na quantidade de dias desde a aplicação
float calcularImposto(int dias);

// Função para calcular a diferença de dias entre duas datas
int calcularDiferencaDias(const char *dataInicial, const char *dataFinal);

// Função para calcular juros compostos e atualizar o valor bruto e imposto
void atualizarInvestimento(DadosFinanceiros *dados);

#endif