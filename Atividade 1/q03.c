#include <stdio.h>

int main()
{
    // Variável signed int para armazenar o número
    int numero;

    // Solicitar um número inteiro
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    // Imprimir o valor original (signed int)
    printf("Valor original (signed int): %d\n", numero);

    // Utilizar modificador unsigned para interpretar o mesmo valor sem sinal
    unsigned int numeroSemSinal = (unsigned int)numero;

    // Imprimir o valor sem sinal
    printf("Valor sem sinal: %u\n", numeroSemSinal);

    return 0;
}