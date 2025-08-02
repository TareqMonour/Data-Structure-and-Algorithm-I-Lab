#include <iostream>
#include <stack>
#include <cctype>

bool isAlphabetic(char c) {
    return std::isalpha(c) != 0;
}

bool isPalindrome(const std::string& input) {
    std::stack<char> charStack;

    // Push alphabetic characters onto the stack
    for (char c : input) {
        if (isAlphabetic(c)) {
            charStack.push(std::tolower(c));
        }
    }

    // Check if the string is a palindrome
    for (char c : input) {
        if (isAlphabetic(c)) {
            char top = charStack.top();
            charStack.pop();
            if (std::tolower(c) != top) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "Palindrome\n";
    } else {
        std::cout << "Not a Palindrome\n";
    }

    return 0;
}
