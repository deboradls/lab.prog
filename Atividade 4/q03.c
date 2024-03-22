#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>


typedef struct Senha {
    char codigo[7]; 
    bool isPrioridade; 
    struct Senha *prox; 
} Senha;

void gerarSenha(char senha[]) {
    if (rand() % 3 == 0) {
       
        int i;
        for (i = 0; i < 2; i++) {
            senha[i] = 'P'; 
        }
        for (i = 2; i < 5; i++) {
            senha[i] = 'A' + rand() % 26; 
        }
        senha[5] = rand() % 10 + '0'; 
        senha[6] = '\0'; 
    } else {
      
        int i;
        for (i = 0; i < 3; i++) {
            senha[i] = 'A' + rand() % 26;
        }
        senha[3] = rand() % 10 + '0'; 
        senha[4] = '\0'; 
    }
}

void mostrarTodasSenhas(Senha *inicio) {
    Senha *atual = inicio;
    printf("Todas as senhas geradas:\n");
    while (atual != NULL) {
        printf("Senha: %s (%s)\n", atual->codigo, atual->isPrioridade ? "Prioridade" : "Normal");
        atual = atual->prox;
    }
}

void consumirSenhaAleatoria(Senha **inicio) {
    if (*inicio != NULL) {
        int totalSenhas = 0;
        Senha *atual = *inicio;
        while (atual != NULL) {
            totalSenhas++;
            atual = atual->prox;
        }

        int indice = rand() % totalSenhas;

        atual = *inicio;
        Senha *anterior = NULL;
        while (indice > 0) {
            anterior = atual;
            atual = atual->prox;
            indice--;
        }

        if (anterior != NULL) {
            anterior->prox = atual->prox;
        } else {
            *inicio = atual->prox;
        }

        printf("Consumindo senha: %s (%s)\n", atual->codigo, atual->isPrioridade ? "Prioridade" : "Normal");
        free(atual); 
    } else {
        printf("Não há mais senhas para consumir!\n");
    }
}

int main() {
    srand(time(NULL));

    Senha *inicio = NULL;
    Senha *fim = NULL; 

    int numSenhasGeradas = 0;

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Gerar 10 senhas\n");
        printf("2. Consumir senha aleatoriamente\n");
        printf("3. Mostrar todas as senhas geradas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Gerando 10 senhas...\n");
                for (int i = 0; i < 10; i++) {
                    Senha *novaSenha = (Senha *)malloc(sizeof(Senha));
                    if (novaSenha == NULL) {
                        printf("Erro ao alocar memoria para a senha!\n");
                        exit(1);
                    }

                    gerarSenha(novaSenha->codigo);
                    novaSenha->isPrioridade = novaSenha->codigo[0] == 'P';

                    novaSenha->prox = NULL;

                    if (inicio == NULL) {
                        inicio = novaSenha;
                        fim = novaSenha;
                    } else {
                        fim->prox = novaSenha;
                        fim = novaSenha;
                    }

                    numSenhasGeradas++;
                }
                printf("Senhas geradas com sucesso!\n");
                break;
            case 2:
                consumirSenhaAleatoria(&inicio);
                break;
            case 3:
                mostrarTodasSenhas(inicio);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    
    Senha *atual = inicio;
    while (atual != NULL) {
        Senha *prox = atual->prox;
        free(atual);
        atual = prox;
    }

    return 0;
}