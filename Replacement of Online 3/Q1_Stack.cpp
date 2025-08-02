#include <bits/stdc++.h>
using namespace std;

class TwoStacks {
private:
    int* arr;
    int size;
    int top1;
    int top2;

public:
    TwoStacks(int maxSize) {
        size = maxSize;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void pushStack1(int x) {
        if (top1 < top2 - 1) {
            arr[++top1] = x;
            std::cout << "Pushed " << x << " onto Stack 1\n";
        } else {
            std::cout << "Stack 1 is Full. Cannot Push " << x << "\n";
        }
    }

    void pushStack2(int x) {
        if (top1 < top2 - 1) {
            arr[--top2] = x;
            std::cout << "Pushed " << x << " onto Stack 2\n";
        } else {
            std::cout << "Stack 2 is Full. Cannot Push " << x << "\n";
        }
    }

    int popStack1() {
        if (top1 >= 0) {
            int popped = arr[top1--];
            std::cout << "Popped from Stack 1: " << popped << "\n";
            return popped;
        } else {
            std::cout << "Stack 1 is Empty\n";
            return -1;
        }
    }

    int popStack2() {
        if (top2 < size) {
            int popped = arr[top2++];
            std::cout << "Popped from Stack 2: " << popped << "\n";
            return popped;
        } else {
            std::cout << "Stack 2 is Empty\n";
            return -1;
        }
    }

    bool isEmptyStack1() {
        return (top1 == -1);
    }

    bool isEmptyStack2() {
        return (top2 == size);
    }
};

int main() {
    TwoStacks myStacks(6);

    myStacks.pushStack1(5);
    myStacks.pushStack1(10);

    myStacks.pushStack2(20);
    myStacks.pushStack2(25);

    int popped1 = myStacks.popStack1(); // 10
    int popped2 = myStacks.popStack2(); // 25

    myStacks.pushStack2(30);

    int popped3 = myStacks.popStack1(); // 5
    int popped4 = myStacks.popStack2(); // 30

    bool isEmpty1 = myStacks.isEmptyStack1(); // True
    bool isEmpty2 = myStacks.isEmptyStack2(); // False

    return 0;
}
