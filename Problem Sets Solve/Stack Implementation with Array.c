#include <stdio.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to push an item onto the stack
void push(struct Stack* stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow! Cannot push %d\n", item);
        return;
    }
    stack->arr[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from an empty stack\n");
        return -1; // Assuming -1 as an indicator of an empty stack
    }
    return stack->arr[stack->top--];
}

// Function to peek at the topmost item without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Cannot peek from an empty stack\n");
        return -1; // Assuming -1 as an indicator of an empty stack
    }
    return stack->arr[stack->top];
}

int main() {
    struct Stack myStack;
    initialize(&myStack);

    // Demonstrate stack operations
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top element: %d\n", peek(&myStack));

    printf("Popped element: %d\n", pop(&myStack));
    printf("Popped element: %d\n", pop(&myStack));

    printf("Is the stack empty? %s\n", isEmpty(&myStack) ? "Yes" : "No");

    return 0;
}
