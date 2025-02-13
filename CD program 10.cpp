#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// Global variables
char input[100];
int position = 0;

// Function prototypes
bool E();
bool E_prime();
bool T();
bool T_prime();
bool F();

// Function to check if the current character matches the expected character
bool match(char expected) {
    if (input[position] == expected) {
        position++;
        return true;
    }
    return false;
}

// Function to parse an expression (E -> T E')
bool E() {
    return T() && E_prime();
}

// Function to parse E' (E' -> + T E' | e)
bool E_prime() {
    if (input[position] == '+') {
        position++;
        return T() && E_prime();
    }
    return true; // e production
}

// Function to parse a term (T -> F T')
bool T() {
    return F() && T_prime();
}

// Function to parse T' (T' -> * F T' | e)
bool T_prime() {
    if (input[position] == '*') {
        position++;
        return F() && T_prime();
    }
    return true; // e production
}

// Function to parse a factor (F -> ( E ) | id)
bool F() {
    if (input[position] == '(') {
        position++;
        if (E() && match(')')) {
            return true;
        }
        return false;
    } else if (isalpha(input[position])) { // Check for 'id'
        position++;
        return true;
    }
    return false;
}

int main() {
    // Get input from the user
    printf("Enter an expression: ");
    scanf("%s", input);

    // Start parsing from the beginning of the input
    position = 0;

    // Check if the input is valid and fully consumed
    if (E() && input[position] == '\0') {
        printf("The input is valid.\n");
    } else {
        printf("The input is invalid.\n");
    }

    return 0;
}
