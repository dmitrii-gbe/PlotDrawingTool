#include "evaluation.h"

#include <math.h>
#include <string.h>

#include "stack.h"

double SolveExpression(const char *s, double x) {
    const char *token = NULL;
    char *s_copy = strdup(s);
    Stack stack = init();
    if (s_copy == NULL) {
        return 1;
    }

    double left_operand, right_operand, result;

    token = strtok(s_copy, " ");
    while (token != NULL) {
        if (token[strlen(token) - 1] >= '0' && token[strlen(token) - 1] <= '9') {
            push(&stack, atof(token));
        } else if (token[0] == 'x') {
            push(&stack, x);
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            right_operand = top(&stack);
            pop(&stack);
            left_operand = top(&stack);
            pop(&stack);
            result = CalculateBin(left_operand, right_operand, token[0]);
            push(&stack, result);
        } else if (token[0] == 's' || token[0] == 'c' || token[0] == 't' || token[0] == 'g' ||
                   token[0] == 'q' || token[0] == 'l' || token[0] == '~') {
            left_operand = top(&stack);
            pop(&stack);
            result = CalculateUnary(left_operand, token[0]);
            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }
    double release = top(&stack);
    destroy(&stack);
    free(s_copy);
    return release;
}

double CalculateBin(double left_operand, double right_operand, char operation) {
    double result = 0;
    switch (operation) {
        case '+':
            result = left_operand + right_operand;
            break;
        case '-':
            result = left_operand - right_operand;
            break;
        case '*':
            result = left_operand * right_operand;
            break;
        case '/':
            result = left_operand / right_operand;
            break;
    }
    return result;
}

double CalculateUnary(double operand, char operation) {
    double result = 0;
    switch (operation) {
        case '~':
            result = operand * (-1);
            break;
        case 's':
            result = sin(operand);
            break;
        case 'c':
            result = cos(operand);
            break;
        case 't':
            result = tan(operand);
            break;
        case 'g':
            result = 1.0 / tan(operand);
            break;
        case 'q':
            result = sqrt(operand);
            break;
        case 'l':
            result = log(operand);
            break;
    }
    return result;
}