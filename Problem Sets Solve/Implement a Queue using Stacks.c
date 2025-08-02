#include <stdio.h>
#include <stdlib.h>

// Definition of a stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Definition of a stack
struct Stack {
    struct StackNode* top;
};

// Function to initialize an empty stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isStackEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push a value onto the stack
void push(struct Stack* stack, int value) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a value from the stack
int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Assuming -1 as an invalid value; you may choose a different approach
    }

    struct StackNode* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);

    return value;
}

// Definition of a queue using two stacks
struct QueueUsingTwoStacks {
    struct Stack stack1; // Used for enqueue operation
    struct Stack stack2; // Used for dequeue operation
};

// Function to initialize an empty queue using two stacks
void initializeQueue(struct QueueUsingTwoStacks* queue) {
    initializeStack(&queue->stack1);
    initializeStack(&queue->stack2);
}

// Function to enqueue an element into the queue
void enqueue(struct QueueUsingTwoStacks* queue, int x) {
    push(&queue->stack1, x);
}

// Function to dequeue an element from the queue
int dequeue(struct QueueUsingTwoStacks* queue) {
    if (isStackEmpty(&queue->stack2)) {
        // If stack2 is empty, transfer elements from stack1 to stack2
        while (!isStackEmpty(&queue->stack1)) {
            int value = pop(&queue->stack1);
            push(&queue->stack2, value);
        }
    }

    return pop(&queue->stack2);
}

int main() {
    struct QueueUsingTwoStacks myQueue;
    initializeQueue(&myQueue);

    // Enqueue elements
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    // Dequeue elements
    printf("Dequeued: %d\n", dequeue(&myQueue));
    printf("Dequeued: %d\n", dequeue(&myQueue));

    // Enqueue more elements
    enqueue(&myQueue, 40);
    enqueue(&myQueue, 50);

    // Dequeue remaining elements
    while (!isStackEmpty(&myQueue.stack1) || !isStackEmpty(&myQueue.stack2)) {
        printf("Dequeued: %d\n", dequeue(&myQueue));
    }

    return 0;
}
