#include <iostream>
#include <stack>

// Function to insert an element at the bottom of a stack
void insertAtBottom(std::stack<int>& st, int item) {
    if (st.empty()) {
        st.push(item);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st, item);
    st.push(temp);
}

// Function to reverse a stack using recursion
void reverseStack(std::stack<int>& st) {
    if (!st.empty()) {
        int item = st.top();
        st.pop();

        reverseStack(st);

        insertAtBottom(st, item);
    }
}

// Function to print the elements of the stack
void printStack(const std::stack<int>& st) {
    std::stack<int> tempStack = st;
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<int> myStack;

    // Push elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    std::cout << "Original Stack: ";
    printStack(myStack);

    // Reverse the stack
    reverseStack(myStack);

    std::cout << "Reversed Stack: ";
    printStack(myStack);

    return 0;
}
