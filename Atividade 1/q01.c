#include <stdio.h>

int main() {
    int numero;

    // Solicitar um número inteiro
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    // Realizar um deslocamento de 4 bits para a direita
    int resultado = numero >> 4;

    // Imprimir o resultado
    printf("O número %d com 4 bits deslocados a direita é: %d\n", numero, resultado);

    return 0;
}
