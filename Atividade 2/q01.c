#include <stdio.h>

int fibonacci(int n, int memo[]) {
    if (n <= 1) {
        return n;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);

    return memo[n];
}

int main() {
    int n;

    // Solicita ao usuário para inserir o valor de n dentro do intervalo permitido
    do {
        printf("Digite um inteiro entre 0 e 30 para n: "); // solicitei que fosse entre 0 e 30 pois números grandes o programa demora a fazer o cálculo
        scanf("%d", &n);

        // Verifica se n está dentro do intervalo permitido
        if (n < 0 || n > 30) {
            printf("Por favor, insira um inteiro entre 0 e 30.\n");
        }
    } while (n < 0 || n > 30);

    // Inicializa o array de memoização com -1 (indicando que nenhum valor foi calculado ainda)
    int memo[n + 1];
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    // Chama a função fibonacci e exibe o resultado
    printf("O %d-ésimo termo da sequência de Fibonacci é: %d\n", n, fibonacci(n, memo));

    return 0;
}