#include <iostream>
#include <stack>
#include <sstream>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

std::string postfixToInfix(const std::string& postfix) {
    std::stack<std::string> expressionStack;
    std::istringstream iss(postfix);

    std::string token;
    while (iss >> token) {
        if (!isOperator(token[0])) {
            expressionStack.push(token);
        } else {
            std::string operand2 = expressionStack.top();
            expressionStack.pop();
            std::string operand1 = expressionStack.top();
            expressionStack.pop();

            std::string infixExpression = "(" + operand1 + " " + token + " " + operand2 + ")";
            expressionStack.push(infixExpression);
        }
    }

    return expressionStack.top();
}

int evaluatePostfix(const std::string& postfix) {
    std::stack<int> operandStack;
    std::istringstream iss(postfix);

    std::string token;
    while (iss >> token) {
        if (!isOperator(token[0])) {
            operandStack.push(std::stoi(token));
        } else {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            int result;
            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    std::cerr << "Invalid operator: " << token << std::endl;
                    return 0;  // Invalid input
            }

            operandStack.push(result);
        }
    }

    return operandStack.top();
}

int main() {
    std::string postfixExpression;
    std::cout << "Enter a space-separated postfix expression: ";
    std::getline(std::cin, postfixExpression);

    std::string infixExpression = postfixToInfix(postfixExpression);
    std::cout << "Infix expression: " << infixExpression << std::endl;

    int result = evaluatePostfix(postfixExpression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
