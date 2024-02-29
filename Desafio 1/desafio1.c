#include <stdio.h>

int main()
{
  int num1, num2;

  printf("Digite o primeiro número: ");
  scanf("%d", &num1);

  printf("Digite o segundo número: ");
  scanf("%d", &num2);

  int diff = num1 - num2;
  int sign = (diff >> 31) & 0x1; // Obtém o bit de sinal do número diferença

  // Se o bit de sinal for 0, num1 é maior, senão num2 é maior
  int maior = num1 - sign * diff;

  printf("O número maior é: %d\n", maior);

  getchar();
  
  return 0;
}