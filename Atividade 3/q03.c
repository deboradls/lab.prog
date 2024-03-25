#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// preenche um vetor com números aleatórios em ordem crescente
void preencherVetorOrdenado(int vetor[], int tamanho)
{
    vetor[0] = rand() % 10; // primeiro elemento
    for (int i = 1; i < tamanho; i++)
    {
        vetor[i] = vetor[i - 1] + rand() % 10 + 1; // incremento aleatório
    }
}

//  imprime os elementos de um vetor
void imprimirVetor(int vetor[], int tamanho)
{
    printf("[ ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

// busca binária
int buscaBinaria(int vetor[], int tamanho, int chave)
{
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == chave)
            return meio; // elemento encontrado
        else if (vetor[meio] < chave)
            inicio = meio + 1; // metade direita
        else
            fim = meio - 1; // metade esquerda
    }
    return -1; // elemento não encontrado
}

int main()
{
    srand(time(NULL)); // gerador de números aleatórios com o tempo atual

    int tamanho = 100;
    int vetor[tamanho];

    // vetor ordenado
    preencherVetorOrdenado(vetor, tamanho);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    // busca binária 10 vezes
    for (int i = 0; i < 10; i++)
    {
        int chave = rand() % (vetor[tamanho - 1] + 1); // chave aleatória
        int resultado = buscaBinaria(vetor, tamanho, chave);
        if (resultado != -1)
        {
            printf("\nChave %d encontrada na posição %d.\n", chave, resultado);
        }
        else
        {
            printf("\nChave %d não encontrada.\n", chave);
        }
    }

    return 0;
}
