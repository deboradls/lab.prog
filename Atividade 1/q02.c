#include <stdio.h>

int main()
{
    int numero;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);

    // Verificar se o número é ímpar ou par
    int resultado = (numero % 2 == 1) ? 1 : 0;

    // Imprimir o resultado
    printf("%d\n", resultado);

    return 0;
}
