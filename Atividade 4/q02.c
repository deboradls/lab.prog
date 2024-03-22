

// armazenar as senhas
// corrigir o fato de o codigo forçar a gerar p

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_DE_SENHAS 10
#define PROBABILIDADE_NORMAL 2
#define PROBABILIDADE_PRIORITARIA 1

void gerarSenhas()
{
    int i, contador_normal = 0, contador_prioritaria = 0;

    printf("Senhas geradas:\n");
    for (i = 0; i < NUMERO_DE_SENHAS; i++)
    {
        // número aleatório para decidir se a senha será normal ou prioritária
        int probabilidade = rand() % (PROBABILIDADE_NORMAL + PROBABILIDADE_PRIORITARIA);
        if (probabilidade < PROBABILIDADE_NORMAL && contador_normal < NUMERO_DE_SENHAS * 2 / 3)
        {
            contador_normal++;
            printf("Senha Normal: N%d\n", contador_normal);
        }
        else if (contador_prioritaria < NUMERO_DE_SENHAS / 3)
        {
            contador_prioritaria++;
            printf("Senha Prioritária: P%d\n", contador_prioritaria);
        }
        else
        {
            contador_normal++;
            printf("Senha Normal: N%d\n", contador_normal);
        }
    }
}

int main()
{
    // gerador de números aleatórios com base no tempo atual
    srand(time(NULL));
    gerarSenhas();
    return 0;
}
