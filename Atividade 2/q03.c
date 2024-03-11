#include <stdio.h>
#include <math.h>

// Função para calcular a potência de base elevada a expoente
double calcularPotencia(int base, int expoente) {
    if (expoente >= 0) {
        return pow(base, expoente);
    } else {
        return 1.0 / pow(base, -expoente);
    }
}

int main() {
    int base, expoente;

    // Solicita ao usuário para inserir os números inteiros
    printf("Digite a base (número inteiro): ");
    scanf("%d", &base);

    printf("Digite o expoente (número inteiro): ");
    scanf("%d", &expoente);

    // Calcula a potência e imprime o resultado
    double resultado = calcularPotencia(base, expoente);
    printf("%d elevado a %d é igual a %.6f\n", base, expoente, resultado);

    return 0;
}
