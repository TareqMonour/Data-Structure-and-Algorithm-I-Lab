#include <iostream>
#include <stack>

bool isValidSequence(const std::string& s) {
    std::stack<char> parenthesesStack;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            parenthesesStack.push(c);
        } else {
            if (parenthesesStack.empty()) {
                // Closing parenthesis with no matching open parenthesis
                return false;
            }

            char top = parenthesesStack.top();
            parenthesesStack.pop();

            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                // Mismatched closing parenthesis
                return false;
            }
        }
    }

    // If the stack is not empty, try removing one parenthesis from the end and check again
    if (!parenthesesStack.empty()) {
        parenthesesStack.pop();
    }

    return parenthesesStack.empty();
}

int main() {
    std::string input;
    std::cout << "Enter a string of parentheses: ";
    std::cin >> input;

    if (isValidSequence(input)) {
        std::cout << "The string forms a valid parentheses sequence by removing at most one parenthesis.\n";
    } else {
        std::cout << "The string does not form a valid parentheses sequence by removing at most one parenthesis.\n";
    }

    return 0;
}
