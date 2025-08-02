#include <iostream>

class Queue {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int frontIndex;
    int rearIndex;

public:
    Queue() {
        frontIndex = -1;
        rearIndex = -1;
    }

    void enqueue(int x) {

        if (isEmpty()) {
            frontIndex = 0;
            rearIndex = 0;
        } else {
            rearIndex = (rearIndex + 1) % MAX_SIZE;
        }
        arr[rearIndex] = x;
    }

    int dequeue() {

        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return -1;
        }

        int frontElement = arr[frontIndex];

        if (frontIndex == rearIndex) {
            frontIndex = -1;
            rearIndex = -1;
        } else {
            frontIndex = (frontIndex + 1) % MAX_SIZE;
        }

        return frontElement;
    }

    bool isEmpty() { return frontIndex == -1 && rearIndex == -1; }
};

class StackUsingQueue {
private:
    Queue q1, q2;

public:
    void push(int x) {
        q1.enqueue(x);
    }

    int pop() {

        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop.\n";
            return -1;
        }
        while (q1.dequeue() != -1) {
            q2.enqueue(q1.dequeue());
        }

        std::swap(q1, q2);
        return q2.dequeue();
    }

    bool isEmpty() { return q1.isEmpty() && q2.isEmpty(); }
};

int main() {
    StackUsingQueue stack;

    stack.push(4);
    stack.push(2);
    stack.push(5);

    std::cout << "Pop: " << stack.pop() << std::endl;

    std::cout << "Is Empty: " << (stack.isEmpty() ? "true" : "false") << std::endl;

    std::cout << "Pop: " << stack.pop() << std::endl;
    std::cout << "Pop: " << stack.pop() << std::endl;

    std::cout << "Is Empty: " << (stack.isEmpty() ? "true" : "false") << std::endl;

    return 0;
}

