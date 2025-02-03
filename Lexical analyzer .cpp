#include <stdio.h>
#include <ctype.h>
#include <string.h>

void analyze(const char *input) {
    while (*input) {
        if (isspace(*input)) { 
            input++; 
            continue; 
        }

        if (*input == '/' && *(input + 1) == '/') 
            break; 

        if (isalpha(*input) || *input == '_') { 
            printf("Identifier: ");
            while (isalnum(*input) || *input == '_') 
                putchar(*input++);
            putchar('\n');
            continue;
        }

        if (isdigit(*input)) { 
            printf("Constant: ");
            while (isdigit(*input)) 
                putchar(*input++);
            putchar('\n');
            continue;
        }

        if (strchr("+-*/=<>!&|", *input)) { 
            printf("Operator: %c\n", *input++);
            continue;
        }

        input++; 
    }
}

int main() {
    const char *code = "int x = 10; // Example";
    analyze(code);
    return 0;
}
