#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int tempVarCount = 1;
char* newTempVar() {
    char *temp = (char*)malloc(5);
    sprintf(temp, "t%d", tempVarCount++);
    return temp;
}
void generateTAC(char* expr) {
    char stack[100][10];
    int top = -1;
    
    printf("Three Address Code:\n");
    for (int i = 0; expr[i] != '\0'; i++) {
        if (isalnum(expr[i])) { // Operand
            char op[2] = {expr[i], '\0'};
            strcpy(stack[++top], op);
        } else { // Operator
            if (top < 1) {
                printf("Invalid Expression\n");
                return;
            }
            char *op2 = stack[top--];
            char *op1 = stack[top--];
            char *temp = newTempVar();
            printf("%s = %s %c %s\n", temp, op1, expr[i], op2);
            strcpy(stack[++top], temp);
        }
    }
    if (top != 0) {
        printf("Invalid Expression\n");
    }
}

int main() {
    char expr[100];
    printf("Enter a postfix expression: ");
    scanf("%s", expr);
    generateTAC(expr);
    return 0;
}

