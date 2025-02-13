
#include <stdio.h>
#include <string.h>
#define MAX_RULES 10
#define MAX_SYMBOLS 10
typedef struct {
    char lhs;       
    char rhs[MAX_SYMBOLS][MAX_SYMBOLS]; 
    int rhs_count;  
} ProductionRule;


void eliminateLeftRecursion(ProductionRule rules[], int rule_count) {
    for (int i = 0; i < rule_count; i++) {
        for (int j = 0; j < i; j++) {
            
            for (int k = 0; k < rules[i].rhs_count; k++) {
                if (rules[i].rhs[k][0] == rules[j].lhs) {
                    
                    char new_rhs[MAX_SYMBOLS][MAX_SYMBOLS];
                    int new_rhs_count = 0;

                    for (int l = 0; l < rules[j].rhs_count; l++) {
                        char temp[MAX_SYMBOLS];
                        strcpy(temp, rules[j].rhs[l]);
                        strcat(temp, rules[i].rhs[k] + 1);
                        strcpy(new_rhs[new_rhs_count++], temp);
                    }

                    
                    for (int l = k; l < rules[i].rhs_count - 1; l++) {
                        strcpy(rules[i].rhs[l], rules[i].rhs[l + 1]);
                    }
                    rules[i].rhs_count--;

                    
                    for (int l = 0; l < new_rhs_count; l++) {
                        strcpy(rules[i].rhs[rules[i].rhs_count++], new_rhs[l]);
                    }
                }
            }
        }

        
        int has_left_recursion = 0;
        for (int j = 0; j < rules[i].rhs_count; j++) {
            if (rules[i].rhs[j][0] == rules[i].lhs) {
                has_left_recursion = 1;
                break;
            }
        }

        if (has_left_recursion) {
            
            char new_non_terminal = rules[i].lhs + 1;

            
            ProductionRule new_rule;
            new_rule.lhs = new_non_terminal;
            new_rule.rhs_count = 0;

            for (int j = 0; j < rules[i].rhs_count; j++) {
                if (rules[i].rhs[j][0] == rules[i].lhs) {
                    
                    char temp[MAX_SYMBOLS];
                    strcpy(temp, rules[i].rhs[j] + 1);
                    strcat(temp, &new_non_terminal);
                    strcpy(new_rule.rhs[new_rule.rhs_count++], temp);
                } else {
                    
                    strcat(rules[i].rhs[j], &new_non_terminal);
                }
            }

            
            strcpy(new_rule.rhs[new_rule.rhs_count++], "e");

    
            rules[rule_count++] = new_rule;
        }
    }
}


void printRules(ProductionRule rules[], int rule_count) {
    for (int i = 0; i < rule_count; i++) {
        printf("%c -> ", rules[i].lhs);
        for (int j = 0; j < rules[i].rhs_count; j++) {
            printf("%s", rules[i].rhs[j]);
            if (j < rules[i].rhs_count - 1) {
                printf(" | ");
            }
        }
        printf("\n");
    }
}

int main() {
    ProductionRule rules[MAX_RULES];
    int rule_count;


    rule_count = 2;
    rules[0].lhs = 'A';
    strcpy(rules[0].rhs[0], "Aa");
    strcpy(rules[0].rhs[1], "b");
    rules[0].rhs_count = 2;

    rules[1].lhs = 'B';
    strcpy(rules[1].rhs[0], "Bc");
    strcpy(rules[1].rhs[1], "d");
    rules[1].rhs_count = 2;

    printf("Original Grammar:\n");
    printRules(rules, rule_count);

    eliminateLeftRecursion(rules, rule_count);

    printf("\nGrammar after eliminating left recursion:\n");
    printRules(rules, rule_count);

    return 0;
}
