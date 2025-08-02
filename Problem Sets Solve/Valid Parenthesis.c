#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(std::string s) {
    std::stack<char> charStack;
    std::unordered_map<char, char> bracketMap = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char c : s) {
        if (bracketMap.find(c) != bracketMap.end()) {
            // Current character is a closing bracket
            char topElement = charStack.empty() ? '#' : charStack.top();
            charStack.pop();

            if (topElement != bracketMap[c]) {
                return false;
            }
        } else {
            // Current character is an opening bracket
            charStack.push(c);
        }
    }

    // The string is valid if the stack is empty at the end
    return charStack.empty();
}

int main() {
    std::string input;
    std::cout << "Enter a string containing brackets: ";
    std::cin >> input;

    if (isValid(input)) {
        std::cout << "The string is valid.\n";
    } else {
        std::cout << "The string is not valid.\n";
    }

    return 0;
}
