#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "gerenciamento_investimento.h"

//Função para salvar os dados de investimento
void salvarDados(Titular * Titular);

//Função para carregar os dados de investimentos
void carregarDados(Titular *titular);

#endif