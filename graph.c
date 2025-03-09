#include "draw.h"
#include "evaluation.h"
#include "expression_processing.h"

int main() {
    printf(
        "Please, pay attention to parentheses balacing and to the following list of allowed operators:\n+, "
        "-, *, /, sin(), cos(), tan(), "
        "ctg(), sqrt(), ln().\nArgument should be specified by x character.\nPlease, enter expression to "
        "plot:\n");
    char* input = (char*)calloc(MAX_EXPRESSION_SIZE, sizeof(char));
    size_t size = 0;
    getline(&input, &size, stdin);
    ProcessExpression(&input);
    int flag = 1;
    char* RPN = GetPostfixNotation(input, &flag);
    if (!flag || InValidExpression(RPN)) {
        printf("%s", "You entered invalid exrpession. Please, try again. Exit..\n");
    } else {
        draw_graph(&SolveExpression, RPN);
    }
    free(RPN);
    free(input);
    return 0;
}
