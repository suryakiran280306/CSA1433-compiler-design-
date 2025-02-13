#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

int is_valid_identifier(char *identifier) {

    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        return 0;
    }
    for (int i = 1; i < strlen(identifier); i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            return 0;
        }
    }

    return 1;
}

int main() {
    char identifier[MAX_LENGTH];

    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (is_valid_identifier(identifier)) {
        printf("%s is a valid identifier.\n", identifier);
    } else {
        printf("%s is not a valid identifier.\n", identifier);
    }

    return 0;
}



