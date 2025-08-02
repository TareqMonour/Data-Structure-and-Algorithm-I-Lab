#include <stdio.h>
#include <stdlib.h>

// Definition of the Circular Queue structure
#define MAX_SIZE 5

struct CircularQueue {
    int items[MAX_SIZE];
    int front;
    int rear;
    int size;
};

// Function to initialize an empty circular queue
void initializeCircularQueue(struct CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* queue) {
    return (queue->size == 0);
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* queue) {
    return (queue->size == MAX_SIZE);
}

// Function to enqueue an item into the circular queue
void enqueue(struct CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = item;
    queue->size++;

    printf("Enqueued: %d\n", item);
}

// Function to dequeue an item from the circular queue
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Assuming -1 as an invalid value; you may choose a different approach
    }

    int dequeuedItem = queue->items[queue->front];

    if (queue->front == queue->rear) {
        // Last element in the queue is being dequeued
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    queue->size--;

    printf("Dequeued: %d\n", dequeuedItem);
    return dequeuedItem;
}

// Function to get the front item from the circular queue without removing it
int front(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No front item.\n");
        return -1; // Assuming -1 as an invalid value; you may choose a different approach
    }

    return queue->items[queue->front];
}

int main() {
    struct CircularQueue myQueue;
    initializeCircularQueue(&myQueue);

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

    // Enqueue more elements to fill the queue
    enqueue(&myQueue, 40);
    enqueue(&myQueue, 50);
    enqueue(&myQueue, 60);
    enqueue(&myQueue, 70);

    // Check if the queue is full
    if (isFull(&myQueue)) {
        printf("Queue is full.\n");
    } else {
        printf("Queue is not full.\n");
    }

    return 0;
}
