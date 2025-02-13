#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValidString(const char* str, int start, int end) {
    
    if (start > end) {
        return true;
    }

    if (str[start] == 'a' && str[end] == 'b') {
    
        return isValidString(str, start + 1, end - 1);
    }

    return false;
}

int main() {
    char input[100];

       printf("Enter a string to check if it satisfies the grammar S -> aSb | e: ");
    scanf("%s", input);

    int length = strlen(input);

    if (isValidString(input, 0, length - 1)) {
        printf("The string \"%s\" is valid according to the grammar.\n", input);
    } else {
        printf("The string \"%s\" is invalid according to the grammar.\n", input);
    }

    return 0;
}
