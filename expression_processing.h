#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

#define MAX_INDEX 127
#define MAX_EXPRESSION_SIZE 1000

void RemoveWhiteSpaces(char** string);

void strreplace(char* string, const char* find, const char* replaceWith);

void ShortenOpearations(char** string);

void InitializePriority(int* priority);

int IsDigit(char c);

int IsOpearator(char c);

char* GetPostfixNotation(char* infix_notation, int* flag);

int InValidExpression(char* expression);

void ProcessExpression(char** input);