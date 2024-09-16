#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  // Biblioteca para lidar com datas
#include <math.h>  // Biblioteca para função pow

#include "calculo_investimento.h"
#include "gerenciamento_investimento.h"

char dataAtual[11] = "15/09/2024";

// Função para o submenu de agrupamento
void submenuAgrupamento(Titular *titular) {
    int opcao;
    printf("\n=== Submenu de Agrupamento ===\n");
    printf("1 - Agrupar e ordenar por tipo\n");
    printf("2 - Agrupar por tipo e ordenar por data de aplicação\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            // Agrupar e ordenar por tipo
            qsort(titular->investimentos, titular->num_investimentos, sizeof(DadosFinanceiros), compararPorTipo);
            printf("\nInvestimentos agrupados e ordenados por tipo:\n");
            exibirTitular(titular);
            break;
        case 2:
            // Agrupar por tipo e ordenar por data de aplicação
            agruparPorTipoOrdenar(titular);
            printf("\nInvestimentos agrupados por tipo e ordenados por data de aplicação:\n");
            exibirTitular(titular);
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

int main() {
    Titular titular;
    titular.num_investimentos = 0;
    titular.investimentos = NULL;

    // Solicitar o nome do titular
    perguntarNomeTitular(&titular);

    int opcao;

    do {
        printf("\n=== Menu de Opções ===\n");
        printf("1 - Inserir novos investimentos\n");
        printf("2 - Exibir nome e investimentos do titular\n");
        printf("3 - Atualizar valor bruto de um investimento\n");
        printf("4 - Agrupar e ordenar investimentos\n");
        printf("5 - Imprimir valor bruto e líquido\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirInvestimentos(&titular);
                break;
            case 2:
                exibirTitular(&titular);
                break;
            case 3: {
                int indice;
                printf("Escolha o número do investimento a atualizar (1 a %d): ", titular.num_investimentos);
                scanf("%d", &indice);
                if (indice >= 1 && indice <= titular.num_investimentos) {
                    atualizarInvestimento(&titular.investimentos[indice - 1]);
                } else {
                    printf("Investimento inválido!\n");
                }
                break;
            }
            case 4:
                submenuAgrupamento(&titular);
                break;
            case 5:
                imprimirTotais(&titular);  // Chama a função para imprimir totais
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);

    free(titular.investimentos);
    return 0;
}

