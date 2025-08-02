#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool isDigit(char ch) {
    return isdigit(ch);
}

bool isOpeningParen(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

bool isClosingParen(char ch) {
    return ch == ')' || ch == ']' || ch == '}';
}

bool areParenthesesMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isPalindrome(char* str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool isValidExpression(char* expression) {
    int len = strlen(expression);
    int openCount = 0;
    bool hasOperator = false;
    bool hasDigit = false;

    for (int i = 0; i < len; i++) {
        char current = expression[i];

        if (isOpeningParen(current)) {
            openCount++;
        } else if (isClosingParen(current)) {
            if (openCount == 0 || !areParenthesesMatching(expression[i - 1], current)) {
                return false;
            }
            openCount--;
        } else if (isDigit(current)) {
            hasDigit = true;
        } else if (isOperator(current)) {
            hasOperator = true;
        }

        if (i > 0 && isOpeningParen(expression[i - 1]) && isClosingParen(current)) {
            return false;
        }
    }

    if (openCount != 0) {
        return false;
    }

    if (!hasDigit) {
        return false;
    }

    if (!hasOperator) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        if (isDigit(expression[i])) {
            int j = i;
            while (j < len && isDigit(expression[j])) {
                j++;
            }
            if (!isPalindrome(expression, i, j - 1)) {
                return false;
            }
            i = j - 1;
        }
    }

    return true;
}

int main() {

    printf("%s\n", isValidExpression("((4++1)*4)") ? "Valid" : "Invalid");
    printf("%s\n", isValidExpression("([(2*2)])") ? "Valid" : "Invalid");
    printf("%s\n", isValidExpression("({(9)-{3+9}})") ? "Valid" : "Invalid");
    printf("%s\n", isValidExpression("(((2+3)*4))") ? "Valid" : "Invalid");
    printf("%s\n", isValidExpression("([2++]*2)") ? "Valid" : "Invalid");
    printf("%s\n", isValidExpression("[]") ? "Valid" : "Invalid");
    printf("%s\n", isValidExpression("(2++)") ? "Valid" : "Invalid");
    printf("%s\n", isValidExpression("(+)") ? "Valid" : "Invalid");

    return 0;
}

