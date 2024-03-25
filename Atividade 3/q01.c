#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para preencher um vetor com números aleatórios
void preencherVetor(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % 100; // Gerando números aleatórios entre 0 e 99
    }
}

// Função para imprimir os elementos de um vetor
void imprimirVetor(int *vetor, int tamanho)
{
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com o tempo atual

    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));

    preencherVetor(vetor, tamanho);
    imprimirVetor(vetor, tamanho);

    free(vetor); // Libera a memória alocada para o vetor

    return 0;
}
