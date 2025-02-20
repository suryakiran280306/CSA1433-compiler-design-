#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure for operator handling
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Stack functions
void push(Stack *s, char item) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    return (s->top == -1) ? '\0' : s->items[s->top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    s.top = -1;
    int i = 0, j = 0;
    char token;
    
    while ((token = infix[i++]) != '\0') {
        if (isdigit(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&s, token);
        } else if (token == ')') {
            while (peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        } else { // Operator
            while (s.top != -1 && precedence(peek(&s)) >= precedence(token)) {
                postfix[j++] = pop(&s);
            }
            push(&s, token);
        }
    }

    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

// Generate assembly-like instructions
void generateAssembly(char* postfix) {
    Stack s;
    s.top = -1;
    int reg = 0;
    
    printf("\nGenerated Assembly Code:\n");
    for (int i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];

        if (isdigit(token)) {
            printf("MOV R%d, %c\n", reg, token);
            push(&s, reg + '0');  // Store register number as char
            reg++;
        } else {
            int op2 = pop(&s) - '0';
            int op1 = pop(&s) - '0';
            
            switch (token) {
                case '+': printf("ADD R%d, R%d\n", op1, op2); break;
                case '-': printf("SUB R%d, R%d\n", op1, op2); break;
                case '*': printf("MUL R%d, R%d\n", op1, op2); break;
                case '/': printf("DIV R%d, R%d\n", op1, op2); break;
            }
            push(&s, op1 + '0'); // Push the result register back
        }
    }
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an arithmetic expression (e.g., 3+5*2): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    generateAssembly(postfix);

    return 0;
}

