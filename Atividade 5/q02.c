#include <stdio.h>

int main()
{
    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int comprimento = strlen(palavra);

    printf("Palavra invertida: ");
    for (int i = comprimento - 1; i >= 0; i--)
    {
        printf("%c", palavra[i]);
    }
    printf("\n");

    return 0;
}