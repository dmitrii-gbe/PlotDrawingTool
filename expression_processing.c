#include "expression_processing.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

void RemoveWhiteSpaces(char** string) {
    char* buffer = (char*)calloc(MAX_EXPRESSION_SIZE, sizeof(char));
    char* init_position_string = *string;
    char* init_position_buffer = buffer;
    while (**string) {
        if (**string != ' ') {
            *buffer++ = **string;
        }
        ++(*string);
    }
    *buffer = **string;

    char* tmp = init_position_buffer;
    init_position_buffer = init_position_string;
    *string = tmp;
    free(init_position_buffer);
}

void strreplace(char* string, const char* find, const char* replaceWith) {
    while (strstr(string, find) != NULL) {
        char* temporaryString = malloc(strlen(strstr(string, find) + strlen(find)) + 1);
        strcpy(temporaryString, strstr(string, find) + strlen(find));
        *strstr(string, find) = '\0';
        strcat(string, replaceWith);
        strcat(string, temporaryString);
        free(temporaryString);
    }
}

void ShortenOpearations(char** string) {
    strreplace(*string, "sin", "s");
    strreplace(*string, "cos", "c");
    strreplace(*string, "tan", "t");
    strreplace(*string, "ctg", "g");
    strreplace(*string, "sqrt", "q");
    strreplace(*string, "sqrt", "q");
    strreplace(*string, "ln", "l");
}

void InitializePriority(int* priority) {
    priority['('] = 0;
    priority['+'] = 1;
    priority['-'] = 1;
    priority['*'] = 2;
    priority['/'] = 2;
    priority['^'] = 3;
    priority['~'] = 4;
    priority['s'] = 4;
    priority['c'] = 4;
    priority['t'] = 4;
    priority['g'] = 4;
    priority['q'] = 4;
    priority['l'] = 4;
}

int IsDigit(char c) { return c >= '0' && c <= '9'; }

int IsOpearator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '~' || c == 's' || c == 't' ||
           c == 'c' || c == 'g' || c == 'q' || c == 'l';
}

char* GetPostfixNotation(char* infix_notation, int* flag) {
    const char* string_start = infix_notation;
    int priority[MAX_INDEX];
    InitializePriority(priority);
    char* postfix_notation = (char*)malloc(MAX_EXPRESSION_SIZE * sizeof(char));
    int string_index = 0;
    c_Stack stack = c_init();
    while (*infix_notation != '\n') {
        if (IsDigit(*infix_notation)) {
            while (IsDigit(*infix_notation) || *infix_notation == '.') {
                postfix_notation[string_index++] = *infix_notation;
                ++infix_notation;
            }
            postfix_notation[string_index++] = ' ';
        } else if (*infix_notation == 'x') {
            postfix_notation[string_index++] = *infix_notation;
            postfix_notation[string_index++] = ' ';
            ++infix_notation;
        } else if (*infix_notation == '(') {
            c_push(&stack, *infix_notation);
            ++infix_notation;
        } else if (*infix_notation == ')') {
            while (!c_empty(&stack) && c_top(&stack) != '(') {
                postfix_notation[string_index++] = c_top(&stack);
                postfix_notation[string_index++] = ' ';
                c_pop(&stack);
            }
            if (c_empty(&stack)) {
                *flag = 0;
            }
            c_pop(&stack);
            ++infix_notation;
        } else if (IsOpearator(*infix_notation)) {
            if (*infix_notation == '-' && (infix_notation == string_start || infix_notation[-1] == '(' ||
                                           IsOpearator(infix_notation[-1]))) {
                *infix_notation = '~';
            }

            while (!c_empty(&stack) && priority[(int)c_top(&stack)] >= priority[(int)*infix_notation]) {
                postfix_notation[string_index++] = c_top(&stack);
                postfix_notation[string_index++] = ' ';
                c_pop(&stack);
            }
            c_push(&stack, *infix_notation);
            ++infix_notation;
        }
    }
    while (!c_empty(&stack)) {
        postfix_notation[string_index++] = c_top(&stack);
        postfix_notation[string_index++] = ' ';
        if (c_top(&stack) == '(') {
            *flag = 0;
        }
        c_pop(&stack);
    }
    postfix_notation[string_index - 1] = '\0';
    c_destroy(&stack);
    return postfix_notation;
}

int InValidExpression(char* expression) { return strstr(expression, " 0 /") || strstr(expression, " 0 l"); }

void ProcessExpression(char** input) {
    RemoveWhiteSpaces(input);
    ShortenOpearations(input);
}
