#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciamento_investimento.h"

// Função para salvar os dados de investimentos em um arquivo
void salvarDados(Titular *titular)
{
    FILE *arquivo = fopen("investimentos.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Salva o nome do titular
    fprintf(arquivo, "%s\n", titular->titular);

    // Salva o número de investimentos
    fprintf(arquivo, "%d\n", titular->num_investimentos);

    // Salva os dados de cada investimento
    for (int i = 0; i < titular->num_investimentos; i++)
    {
        DadosFinanceiros inv = titular->investimentos[i];
        fprintf(arquivo, "%s %s %.2f %.2f %.2f %.2f %d %s\n",
                inv.dataAplicacao, inv.dataVencimento, inv.valorBruto, inv.valorAplicado,
                inv.taxaJuros, inv.imposto, inv.tipo, inv.nome);
    }

    fclose(arquivo);
    printf("Dados salvos com sucesso!\n");
}

// Função para carregar os dados de investimentos de um arquivo
void carregarDados(Titular *titular)
{
    FILE *arquivo = fopen("investimentos.txt", "r");
    if (arquivo == NULL)
    {
        printf("Nenhum dado de investimento encontrado.\n");
        return;
    }

    // Carrega o nome do titular
    fgets(titular->titular, 50, arquivo);
    // Remove o \n ao final do nome
    titular->titular[strcspn(titular->titular, "\n")] = 0;

    // Carrega o número de investimentos
    fscanf(arquivo, "%d\n", &titular->num_investimentos);

    // Realoca memória para o array de investimentos
    titular->investimentos = malloc(titular->num_investimentos * sizeof(DadosFinanceiros));

    // Carrega os dados de cada investimento
    for (int i = 0; i < titular->num_investimentos; i++)
    {
        DadosFinanceiros *inv = &titular->investimentos[i];
        fscanf(arquivo, "%s %s %f %f %f %f %d %[^\n]",
               inv->dataAplicacao, inv->dataVencimento, &inv->valorBruto, &inv->valorAplicado,
               &inv->taxaJuros, &inv->imposto, (int *)&inv->tipo, inv->nome);
    }

    fclose(arquivo);
    printf("Dados carregados com sucesso!\n");
}
