#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void gerarSenha(int *senha, bool *isPrioridade)
{
    if (rand() % 3 == 0)
    {
        *isPrioridade = true;
        *senha = rand() % 1000;
    }
    else
    {
        *isPrioridade = false;
        *senha = rand() % 100;
    }
}

void mostrarTodasSenhas(int *senhas, bool *prioridades, int numSenhasGeradas)
{
    printf("Todas as senhas geradas:\n");
    for (int i = 0; i < numSenhasGeradas; i++)
    {
        printf("Senha: %03d (%s)\n", senhas[i], prioridades[i] ? "Prioridade" : "Normal");
    }
}

void consumirSenhaAleatoria(int *senhas, bool *prioridades, int *numSenhasGeradas)
{
    if (*numSenhasGeradas > 0)
    {
        int indice = rand() % *numSenhasGeradas;

        printf("Consumindo senha: %03d (%s)\n", senhas[indice], prioridades[indice] ? "Prioridade" : "Normal");

        for (int i = indice; i < *numSenhasGeradas - 1; i++)
        {
            senhas[i] = senhas[i + 1];
            prioridades[i] = prioridades[i + 1];
        }
        (*numSenhasGeradas)--;
    }
    else
    {
        printf("Não há mais senhas para consumir!\n");
    }
}

int main()
{
    srand(time(NULL));

    int senhas[100];
    bool prioridades[100];
    int numSenhasGeradas = 0;

    int opcao;
    do
    {
        printf("\nMenu:\n");
        printf("1. Gerar 10 senhas\n");
        printf("2. Consumir senha aleatoriamente\n");
        printf("3. Mostrar todas as senhas geradas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Gerando 10 senhas...\n");
            for (int i = 0; i < 10; i++)
            {
                gerarSenha(&senhas[numSenhasGeradas], &prioridades[numSenhasGeradas]);
                numSenhasGeradas++;
            }
            printf("Senhas geradas com sucesso!\n");
            break;
        case 2:
            consumirSenhaAleatoria(senhas, prioridades, &numSenhasGeradas);
            break;
        case 3:
            mostrarTodasSenhas(senhas, prioridades, numSenhasGeradas);
            break;
        case 0:
            printf("Tchau!\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}