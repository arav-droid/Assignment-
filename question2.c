/**
 * @file circular_queue.c
 * @brief Circular Queue Implementation using Array in C
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    int items[SIZE];
    int front;
    int rear;
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue *q) {
    return (q->front == (q->rear + 1) % SIZE);
}

int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("[ERROR] Queue Overflow! Circular Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % SIZE;
    }
    
    q->items[q->rear] = value;
    printf("[SUCCESS] Enqueued %d at index %d.\n", value, q->rear);
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("[ERROR] Queue Underflow! Circular Queue is empty.\n");
        return -1;
    }

    int dequeuedValue = q->items[q->front];
    printf("[SUCCESS] Dequeued %d from index %d.\n", dequeuedValue, q->front);

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }

    return dequeuedValue;
}

int getFront(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("[WARNING] Queue is empty! No front element.\n");
        return -1;
    }
    return q->items[q->front];
}

void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("[INFO] Circular Queue is empty.\n\n");
        return;
    }

    printf("Current Circular Queue (Front to Rear): ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);

    printf("=========================================\n");
    printf("   CIRCULAR QUEUE ARRAY IMPLEMENTATION   \n");
    printf("=========================================\n\n");

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    // Overflow test
    enqueue(&q, 60);

    printf("\n");
    display(&q);

    printf("Front Element: %d\n\n", getFront(&q));

    dequeue(&q);
    dequeue(&q);

    printf("\n");
    display(&q);

    printf("--- Demonstrating Circular Wrapping ---\n");
    enqueue(&q, 60);
    enqueue(&q, 70);

    printf("\n");
    display(&q);

    return 0;
}
