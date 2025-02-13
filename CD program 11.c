#include <stdio.h>
#include <math.h>

int main() {
    double result1, result2, result3, result4;

    result1 = (3 + 5) * 2;

    result2 = 4 + 3 * 2;

    result3 = pow(2, 3) * 4;

    result4 = 10 / 2 + 5;

    printf("Demonstration of Operator Precedence (PEMDAS):\n");
    printf("(3 + 5) * 2  = %.2f\n", result1);
    printf("4 + 3 * 2    = %.2f\n", result2);
    printf("pow(2,3) * 4 = %.2f\n", result3);
    printf("10 / 2 + 5   = %.2f\n", result4);

    return 0;
}
