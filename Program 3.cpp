#include <stdio.h>
#include <string.h>
#include <ctype.h>

void recognizeOperators(const char *input) {
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            printf("Operator found: %c\n", input[i]);
        }
    }
}
int main() {
    const char *expression = "3 + 5 - 2 * 4 / 2";
    recognizeOperators(expression);
    return 0;
}

