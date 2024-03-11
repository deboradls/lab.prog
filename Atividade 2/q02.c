#include <stdio.h>

// Função para calcular a potência de base elevada a expoente
long long int calcularPotencia(int base, int expoente)
{
    long long int resultado = 1;

    while (expoente > 0)
    {
        resultado *= base;
        expoente--;
    }

    return resultado;
}

int main()
{
    int base, expoente;

    // Solicita ao usuário para inserir os números inteiros positivos
    printf("Digite a base (número inteiro positivo): ");
    scanf("%d", &base);

    printf("Digite o expoente (número inteiro positivo): ");
    scanf("%d", &expoente);

    // Verifica se os números são inteiros positivos
    if (base < 0 || expoente < 0)
    {
        printf("Por favor, insira números inteiros positivos.\n");
        return 1; // Retorna código de erro
    }

    // Calcula a potência e imprime o resultado
    long long int resultado = calcularPotencia(base, expoente);
    printf("%d elevado a %d é igual a %lld\n", base, expoente, resultado);

    return 0;
}
