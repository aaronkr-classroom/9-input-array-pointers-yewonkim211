#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CH 100
#define NUM_CH (MAX_CH / 2)

int numCheck(char ch) {
    return ch >= '0' && ch <= '9';
}

int checkOp(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

int main(void) {
    char input[MAX_CH];
    char numStr1[NUM_CH], numStr2[NUM_CH];
    char operator = '\0';
    int i = 0, j = 0;

    printf("Enter a simple math formula (e.g., 12+34):\n");
    fgets(input, sizeof(input), stdin);

    // 1. Read first number
    while (input[i] != '\0' && numCheck(input[i])) {
        numStr1[j++] = input[i++];
    }
    numStr1[j] = '\0';

    // 2. Read operator
    if (checkOp(input[i])) {
        operator = input[i++];
    }
    else {
        printf("Error: invalid operator\n");
        return 1;
    }

    // 3. Read second number
    j = 0;
    while (input[i] != '\0' && numCheck(input[i])) {
        numStr2[j++] = input[i++];
    }
    numStr2[j] = '\0';

    // 4. Convert to integers
    int num1 = atoi(numStr1);
    int num2 = atoi(numStr2);
    int result = 0;

    // 5. Compute result
    switch (operator) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0)
            result = num1 / num2;
        else {
            printf("Error: division by zero\n");
            return 1;
        }
        break;
    default:
        printf("Error: unknown operator\n");
        return 1;
    }

    printf("Result: %d %c %d = %d\n", num1, operator, num2, result);
    return 0;
}
