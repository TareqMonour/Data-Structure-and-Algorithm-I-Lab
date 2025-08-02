#include <iostream>
#include <queue>

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        // Move all elements from the primary queue to the auxiliary queue
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push the new element onto the primary queue
        q1.push(x);

        // Move all elements back from the auxiliary queue to the primary queue
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    /** Removes the element on the top of the stack and returns it. */
    int pop() {
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    /** Get the top element. */
    int top() {
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }

private:
    std::queue<int> q1, q2;
};

int main() {
    MyStack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Top element: " << myStack.top() << std::endl;

    std::cout << "Pop: " << myStack.pop() << std::endl;

    std::cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
