#include <stdio.h>

#define MAX_WORD_LENGTH 50
#define MAX_TEXT_LENGTH 1000
#define MAX_WORDS 10

void readWords(char words[MAX_WORDS][MAX_WORD_LENGTH], int numWords) {
    printf("Digite as palavras:\n");
    for (int i = 0; i < numWords; i++) {
        printf("Palavra %d: ", i + 1);
        scanf("%s", words[i]);
    }
}

void replaceWords(char text[], char words[MAX_WORDS][MAX_WORD_LENGTH], int numWords) {
    int i = 0;
    while (text[i] != '\0') {
        int wordStart = -1;
        int j = 0;
        while (text[i] != ' ' && text[i] != '\0') {
            if (wordStart == -1) {
                wordStart = i;
            }
            i++;
            j++;
        }
        if (wordStart != -1) {
            char word[MAX_WORD_LENGTH];
            for (int k = 0; k < j; k++) {
                word[k] = text[wordStart + k];
            }
            word[j] = '\0';
            for (int k = 0; k < numWords; k++) {
                if (strcmp(word, words[k]) == 0) {
                    for (int l = 0; l < j; l++) {
                        text[wordStart + l] = '*';
                    }
                    break;
                }
            }
        }
        if (text[i] != '\0') {
            i++;
        }
    }
}

int main() {
    int numWords;
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    char text[MAX_TEXT_LENGTH];

    printf("Digite a quantidade de palavras: ");
    scanf("%d", &numWords);

    if (numWords > MAX_WORDS || numWords < 1) {
        printf("Quantidade de palavras inválida.\n");
        return 1;
    }

    readWords(words, numWords);

    printf("Digite um texto minimamente grande:\n");
    getchar(); // Limpa o buffer do teclado
    fgets(text, MAX_TEXT_LENGTH, stdin);

    replaceWords(text, words, numWords);

    printf("Texto modificado:\n%s\n", text);

    return 0;
}