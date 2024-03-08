#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplicarMatrizes(int A[][10], int B[][10], int resultado[][10], int linhaA, int colunaA, int colunaB) {
    for (int i = 0; i < linhaA; i++) {
        for (int j = 0; j < colunaB; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < colunaA; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Gera números aleatórios entre 0 e 9
void gerarMatrizAleatoria(int matriz[][10], int linha, int coluna) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            matriz[i][j] = rand() % 10; 
        }
    }
}

void imprimirMatriz(int matriz[][10], int linha, int coluna) {
    printf("Matriz Resultante:\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhaA, colunaA, linhaB, colunaB;

    printf("Digite o número de linhas e colunas da matriz A (separados por espaço): ");
    scanf("%d %d", &linhaA, &colunaA);

    printf("Digite o número de linhas e colunas da matriz B (separados por espaço): ");
    scanf("%d %d", &linhaB, &colunaB);

    if (colunaA != linhaB) {
        printf("A multiplicação de matrizes não é possível com esses tamanhos.\n");
        return 1;
    }

    srand(time(NULL)); // Inicializa a semente para a geração de números aleatórios

    int matrizA[10][10], matrizB[10][10], resultado[10][10];

    gerarMatrizAleatoria(matrizA, linhaA, colunaA);
    gerarMatrizAleatoria(matrizB, linhaB, colunaB);

    printf("Matriz A gerada aleatoriamente:\n");
    imprimirMatriz(matrizA, linhaA, colunaA);

    printf("\nMatriz B gerada aleatoriamente:\n");
    imprimirMatriz(matrizB, linhaB, colunaB);

    multiplicarMatrizes(matrizA, matrizB, resultado, linhaA, colunaA, colunaB);

    printf("\n");
    imprimirMatriz(resultado, linhaA, colunaB);

    return 0;
}
