#include <stdio.h>

void soma()
{
    float num1, num2;
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    printf("O resultado da soma é: %.2f\n", num1 + num2);
}

void subtracao()
{
    float num1, num2;
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    printf("O resultado da subtração é: %.2f\n", num1 - num2);
}

void multiplicacao()
{
    float num1, num2;
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    printf("O resultado da multiplicação é: %.2f\n", num1 * num2);
}

void divisao()
{
    float num1, num2;
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    if (num2 != 0)
        printf("O resultado da divisão é: %.2f\n", num1 / num2);
    else
        printf("Erro: Divisão por zero!\n");
}

void resto()
{
    int num1, num2;
    printf("Digite o primeiro número (dividendo): ");
    scanf("%d", &num1);
    printf("Digite o segundo número (divisor): ");
    scanf("%d", &num2);
    printf("O resto da divisão é: %d\n", num1 % num2);
}

int main()
{
    int escolha;
    while (1)
    {
        printf("\nSelecione a operação:\n");
        printf("1. Soma\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("5. Resto\n");
        printf("6. Sair\n");
        printf("Digite o número da operação desejada: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            soma();
            break;
        case 2:
            subtracao();
            break;
        case 3:
            multiplicacao();
            break;
        case 4:
            divisao();
            break;
        case 5:
            resto();
            break;
        case 6:
            printf("Saindo...\n");
            return 0;
        default:
            printf("Opção inválida. Por favor, selecione uma opção válida.\n");
        }
    }
    return 0;
}
