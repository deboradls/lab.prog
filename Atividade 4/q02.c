#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void gerarSenhaNormal(char senha[]) {
    int i;
    for (i = 0; i < 3; i++) {
        senha[i] = 'A' + rand() % 26; // Letras maiúsculas aleatórias
    }
    senha[3] = rand() % 10 + '0'; // Dígito aleatório
    senha[4] = '\0'; // Adiciona o terminador de string
}

void gerarSenhaPrioridade(char senha[]) {
    int i;
    for (i = 0; i < 2; i++) {
        senha[i] = 'P'; // Prefixo 'P' para indicar prioridade
    }
    for (i = 2; i < 5; i++) {
        senha[i] = 'A' + rand() % 26; // Letras maiúsculas aleatórias
    }
    senha[5] = rand() % 10 + '0'; // Dígito aleatório
    senha[6] = '\0'; // Adiciona o terminador de string
}

int main() {
    srand(time(NULL)); 

    int i, qtdNormais = 0, qtdPrioridade = 0;
    char senha[7]; // senha de 6 caracteres + 1 para o terminador

    printf("Gerando senhas de guichê:\n");
    for (i = 0; i < 10; i++) {
        if (rand() % 3 == 0 && qtdPrioridade < 3) {
            gerarSenhaPrioridade(senha);
            qtdPrioridade++;
        } else {
            gerarSenhaNormal(senha);
            qtdNormais++;
        }
        printf("Senha %d: %s\n", i + 1, senha);
    }

    printf("\nQuantidade de senhas normais: %d\n", qtdNormais);
    printf("Quantidade de senhas de prioridade: %d\n", qtdPrioridade);
return 0; 

}