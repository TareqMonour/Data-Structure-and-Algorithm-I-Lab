#include <stdio.h>
#include <stdlib.h>

// Definition for a stack node.
struct Node {
    int data;
    struct Node* next;
};

// Definition for a stack.
struct Stack {
    struct Node* top;
};

// Function to initialize an empty stack.
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Function to push a value onto the stack.
void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a value from the stack.
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        // Stack is empty
        return -1; // Assuming -1 as an invalid value; you may choose a different approach
    }

    struct Node* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);

    return value;
}

// Function to replace the middle element in the stack with a given value.
void replaceMiddleElement(struct Stack* stack, int n, int m) {
    // Find the middle position
    int middlePosition = n / 2;

    // Traverse to the middle node
    struct Node* current = stack->top;
    for (int i = 0; i < middlePosition; ++i) {
        current = current->next;
    }

    // Replace the middle element with m
    current->data = m;
}

// Function to print the elements of the stack.
void printStack(struct Stack* stack) {
    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the stack.
void freeStack(struct Stack* stack) {
    while (stack->top != NULL) {
        pop(stack);
    }
}

int main() {
    int n, m;
    printf("Enter the number of elements in the stack (odd): ");
    scanf("%d", &n);

    printf("Enter the value to replace the middle element: ");
    scanf("%d", &m);

    struct Stack stack;
    initializeStack(&stack);

    printf("Enter the %d elements of the stack: ", n);
    for (int i = 0; i < n; ++i) {
        int value;
        scanf("%d", &value);
        push(&stack, value);
    }

    // Replace the middle element with m
    replaceMiddleElement(&stack, n, m);

    printf("Updated stack: ");
    printStack(&stack);

    // Free the allocated memory
    freeStack(&stack);

    return 0;
}
