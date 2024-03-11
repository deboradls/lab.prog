#include <stdio.h>

// Função para verificar se um número é primo
int ehPrimo(int numero)
{
    if (numero <= 1)
    {
        return 0; // Números menores ou iguais a 1 não são primos
    }

    for (int i = 2; i * i <= numero; i++)
    {
        if (numero % i == 0)
        {
            return 0; // Se o número for divisível por algum número entre 2 e sqrt(numero), não é primo
        }
    }

    return 1; // Se não foi divisível por nenhum número entre 2 e sqrt(numero), é primo
}

int main()
{
    int numero;

    // Solicita ao usuário para inserir um número inteiro
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    // Verifica se o número é primo e imprime ou retorna o resultado
    if (ehPrimo(numero))
    {
        printf("%d é um número primo.\n", numero);
    }
    else
    {
        printf("%d não é um número primo.\n", numero);
    }

    return 0;
}
