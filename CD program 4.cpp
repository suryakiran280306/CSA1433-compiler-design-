#include <stdio.h>
void analyzeWhitespaceAndNewlines(const char *input) {
    int spaceCount = 0;
    int newlineCount = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            spaceCount++; // Count spaces
        } else if (input[i] == '\t') {
            spaceCount++; // Count tabs as spaces
        } else if (input[i] == '\n') {
            newlineCount++; // Count newlines
        }
    }
    printf("Number of whitespaces: %d\n", spaceCount);
    printf("Number of newline characters: %d\n", newlineCount);
}

int main() {
        const char *input =
        "This is a test input.\n"
        "It contains multiple lines.\n"
        "Each line has some spaces and tabs.\t\n"
        "Let's count them!";

    analyzeWhitespaceAndNewlines(input);

    return 0;
}
