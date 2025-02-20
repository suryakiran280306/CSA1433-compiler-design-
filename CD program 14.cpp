#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EXPR 100

typedef struct {
    char expr[50];
    char temp[10];
} Subexpression;

Subexpression subexpressions[MAX_EXPR];
int subCount = 0;
char* getTempForExpr(const char *expr) {
    for (int i = 0; i < subCount; i++) {
        if (strcmp(subexpressions[i].expr, expr) == 0) {
            return subexpressions[i].temp;
        }
    }
    return NULL;
}
char* storeSubexpression(const char *expr) {
    subexpressions[subCount].temp[0] = 't';
    sprintf(subexpressions[subCount].temp + 1, "%d", subCount + 1);
    strcpy(subexpressions[subCount].expr, expr);
    return subexpressions[subCount++].temp;
}
void optimizeCode(char expressions[][50], int n) {
    printf("Optimized Code:\n");
    for (int i = 0; i < n; i++) {
        char *temp = getTempForExpr(expressions[i]);
        if (temp) {
            printf("%s = %s\n", expressions[i], temp);
        } else {
            char *newTemp = storeSubexpression(expressions[i]);
            printf("%s = %s\n", newTemp, expressions[i]);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of expressions: ");
    scanf("%d", &n);
    getchar(); // Consume newline
    
    char expressions[MAX_EXPR][50];
    printf("Enter the expressions:\n");
    for (int i = 0; i < n; i++) {
        fgets(expressions[i], 50, stdin);
        expressions[i][strcspn(expressions[i], "\n")] = 0; // Remove newline
    }
    
    optimizeCode(expressions, n);
    return 0;
}

