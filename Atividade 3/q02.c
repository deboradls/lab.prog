#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para preencher um vetor com números aleatórios
void preencherVetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % 1000; // Gerando números aleatórios entre 0 e 999
    }
}

// Função para imprimir os elementos de um vetor
void imprimirVetor(int vetor[], int tamanho)
{
    printf("[ ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

// Algoritmo de ordenação: Selection Sort
void selectionSort(int vetor[], int tamanho)
{
    int i, j, min_idx;
    for (i = 0; i < tamanho - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < tamanho; j++)
        {
            if (vetor[j] < vetor[min_idx])
            {
                min_idx = j;
            }
        }
        // Troca o menor elemento com o primeiro elemento não ordenado
        int temp = vetor[min_idx];
        vetor[min_idx] = vetor[i];
        vetor[i] = temp;
    }
}

// Algoritmo de ordenação: Bubble Sort
void bubbleSort(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                // Troca os elementos se estiverem na ordem errada
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Algoritmo de ordenação: Insertion Sort
void insertionSort(int vetor[], int tamanho)
{
    int chave, j;
    for (int i = 1; i < tamanho; i++)
    {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave)
        {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

// Ponteiro para função de ordenação
typedef void (*FuncaoOrdenacao)(int vetor[], int tamanho);

// Função para ordenar um vetor usando um determinado algoritmo de ordenação
void ordenarVetor(int vetor[], int tamanho, FuncaoOrdenacao algoritmo)
{
    algoritmo(vetor, tamanho);
}

int main()
{
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com o tempo atual

    int tamanho = 100;
    int vetor[tamanho];

    // Preenche o vetor com números aleatórios
    preencherVetor(vetor, tamanho);

    printf("Vetor antes da ordenacao:\n");
    imprimirVetor(vetor, tamanho);

    // Ordena o vetor com Selection Sort
    ordenarVetor(vetor, tamanho, selectionSort);
    printf("\nVetor ordenado com Selection Sort:\n");
    imprimirVetor(vetor, tamanho);

    // Preenche o vetor novamente com números aleatórios
    preencherVetor(vetor, tamanho);

    // Ordena o vetor com Bubble Sort
    ordenarVetor(vetor, tamanho, bubbleSort);
    printf("\nVetor ordenado com Bubble Sort:\n");
    imprimirVetor(vetor, tamanho);

    // Preenche o vetor novamente com números aleatórios
    preencherVetor(vetor, tamanho);

    // Ordena o vetor com Insertion Sort
    ordenarVetor(vetor, tamanho, insertionSort);
    printf("\nVetor ordenado com Insertion Sort:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}
