#include <stdio.h>
#include <stdlib.h>

// Definition of the Queue structure
#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize an empty queue
void initializeQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to enqueue an item into the queue
void enqueue(struct Queue* queue, int item) {
    if ((queue->rear + 1) % MAX_SIZE == queue->front) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->items[queue->rear] = item;
    printf("Enqueued: %d\n", item);
}

// Function to dequeue an item from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Assuming -1 as an invalid value; you may choose a different approach
    }

    int dequeuedItem = queue->items[queue->front];

    if (queue->front == queue->rear) {
        // Last element in the queue is being dequeued
        initializeQueue(queue);
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    printf("Dequeued: %d\n", dequeuedItem);
    return dequeuedItem;
}

// Function to get the front item from the queue without removing it
int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No front item.\n");
        return -1; // Assuming -1 as an invalid value; you may choose a different approach
    }

    return queue->items[queue->front];
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
