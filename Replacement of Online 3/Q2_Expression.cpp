#include <iostream>
#include <stack>
#include <cctype>

bool isPalindrome(const std::string& s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (s[i++] != s[j--]) {
            return false;
        }
    }
    return true;
}

bool isValidExpression(const std::string& expression) {
    std::stack<char> charStack;
    bool hasOperator = false;
    bool hasDigit = false;

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            charStack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (charStack.empty() ||
                (c == ')' && charStack.top() != '(') ||
                (c == ']' && charStack.top() != '[') ||
                (c == '}' && charStack.top() != '{')) {
                return false;  // Invalid closing parenthesis
            }
            charStack.pop();
        } else if (isdigit(c)) {
            hasDigit = true;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            hasOperator = true;
        }
    }

    if (!charStack.empty() || !hasDigit || !hasOperator) {
        return false;
    }

    // Check for empty sets of parentheses
    size_t found = expression.find("()");
    while (found != std::string::npos) {
        if (found > 0 && isdigit(expression[found - 1])) {
            if (found + 1 < expression.length() && isdigit(expression[found + 1])) {
                return false;  // Empty set of parentheses with digits in between
            }
        }
        found = expression.find("()", found + 2);
    }

    // Check for palindrome digits
    size_t start = expression.find_first_of("0123456789");
    size_t end = expression.find_last_of("0123456789");
    if (start != std::string::npos && end != std::string::npos) {
        std::string digits = expression.substr(start, end - start + 1);
        if (!isPalindrome(digits)) {
            return false;  // Digits are not palindrome
        }
    }

    return true;
}

int main() {
    std::cout << std::boolalpha;

    std::cout << "Valid: ((4++1)*4) - " << isValidExpression("((4++1)*4)") << "\n";
    std::cout << "Valid: ([(2*2)]) - " << isValidExpression("([(2*2)])") << "\n";
    std::cout << "Valid: ({(9)-{3+9}}) - " << isValidExpression("({(9)-{3+9}})") << "\n";
    std::cout << "Invalid: (((2+3)*4)) - " << isValidExpression("(((2+3)*4))") << "\n";
    std::cout << "Invalid: ([2++]*2) - " << isValidExpression("([2++]*2)") << "\n";
    std::cout << "Invalid: [] - " << isValidExpression("[]") << "\n";
    std::cout << "Invalid: (2++) - " << isValidExpression("(2++)") << "\n";
    std::cout << "Invalid: (+) - " << isValidExpression("(+)") << "\n";

    return 0;
}

