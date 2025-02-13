#include <stdio.h>
#include <string.h>
void eliminateLeftFactoring(char production[][100], int n) {
    for (int i = 0; i < n; i++) {
        char nonTerminal = production[i][0];
        char alpha[100], beta[100];
        int alphaIndex = 0, betaIndex = 0;
        int j = 3; // Start after "A ->"
        while (production[i][j] == production[i + 1][j] && production[i][j] != '\0') {
            alpha[alphaIndex++] = production[i][j];
            j++;
        }
        alpha[alphaIndex] = '\0';

        if (alphaIndex > 0) {
            while (production[i][j] != '\0') {
                beta[betaIndex++] = production[i][j];
                j++;
            }
            beta[betaIndex] = '\0';

            printf("%c -> %s%c'\n", nonTerminal, alpha, nonTerminal);
            printf("%c' -> %s | e\n", nonTerminal, beta);
        } else {
            printf("%s\n", production[i]);
        }
    }
}

int main() {
    char production[][100] = {
        "A -> abB | abC",
        "B -> b",
        "C -> c"
    };

    int n = sizeof(production) / sizeof(production[0]);

    printf("Original Grammar:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", production[i]);
    }

    printf("\nGrammar after eliminating left factoring:\n");
    eliminateLeftFactoring(production, n);

    return 0;
}
