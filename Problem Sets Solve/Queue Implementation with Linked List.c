#include <stdio.h>
#include <stdlib.h>

// Definition of the Queue Node
struct Node {
    int data;
    struct Node* next;
};

// Definition of the Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize an empty queue
void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an item into the queue
void enqueue(struct Queue* queue, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot enqueue.\n");
        return;
    }

    newNode->data = item;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Enqueued: %d\n", item);
}

// Function to dequeue an item from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Assuming -1 as an invalid value; you may choose a different approach
    }

    struct Node* temp = queue->front;
    int dequeuedItem = temp->data;

    if (queue->front == queue->rear) {
        // Last element in the queue is being dequeued
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = temp->next;
    }

    free(temp);
    printf("Dequeued: %d\n", dequeuedItem);
    return dequeuedItem;
}

// Function to get the front item from the queue without removing it
int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No front item.\n");
        return -1; // Assuming -1 as an invalid value; you may choose a different approach
    }

    return queue->front->data;
}

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    // Enqueue elements
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    // Get and print the front item
    printf("Front item: %d\n", front(&myQueue));

    // Dequeue elements
    dequeue(&myQueue);
    dequeue(&myQueue);

    // Check if the queue is empty
    if (isEmpty(&myQueue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    return 0;
}
